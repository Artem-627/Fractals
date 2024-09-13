#include <Render.h>
#include <Complex.h>
#include <MandelbrotSet.h>
#include <Primitives.h>
#include <optional>
#include <thread>
#include <atomic>

MandelbrotSetRender::MandelbrotSetRender(const Box &start_view_box, const std::uint32_t &width,
                                         const std::uint32_t &height) {
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Mandelbrot Set");
    window->setFramerateLimit(30);

    curr_box = new Box(start_view_box);
    // std::cout << "(" << curr_box->min.x << ", " << curr_box->min.y << ")" << " -> ";
    // std::cout << "(" << curr_box->max.x << ", " << curr_box->max.y << ")" << '\n';
}

void MandelbrotSetRender::startRender() {
    std::atomic_bool is_rect_exist = false;
    std::atomic_int area_first_point_x = 0;
    std::atomic_int area_first_point_y = 0;
    std::atomic_int area_curr_point_x = 0;
    std::atomic_int area_curr_point_y = 0;

    std::atomic_int curr_view_width = 0;
    std::atomic_int curr_view_height = 0;

    std::thread* create_rect;
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(is_rect_exist)) {
                is_rect_exist.store(true);
                area_first_point_x.store(sf::Mouse::getPosition(*window).x);
                area_first_point_y.store(sf::Mouse::getPosition(*window).y);

                create_rect = new std::thread([&]() {
                    while (true) {
                        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            if ((std::fabs(area_first_point_x - area_curr_point_x) / std::fabs(area_first_point_y - area_curr_point_y) < 2) &&
                                (std::fabs(area_first_point_y - area_curr_point_y) / std::fabs(area_first_point_x - area_curr_point_x) < 2) &&
                                (std::fabs(area_first_point_x - area_curr_point_x) > 40) &&
                                (std::fabs(area_first_point_y - area_curr_point_y) > 40)) {
                                const float start_d_x = static_cast<float>(area_first_point_x.load()) / static_cast<float>(curr_view_width);
                                const float start_d_y = 1 - static_cast<float>(area_first_point_y.load()) / static_cast<float>(curr_view_height);

                                const float curr_d_x = static_cast<float>(area_curr_point_x.load()) / static_cast<float>(curr_view_width);
                                const float curr_d_y = 1 - static_cast<float>(area_curr_point_y.load()) / static_cast<float>(curr_view_height);

                                const Point new_first_curr_box{
                                    curr_box->min.x + start_d_x * (curr_box->max.x - curr_box->min.x),
                                    curr_box->max.y - start_d_y * (curr_box->max.y - curr_box->min.y)
                                };
                                const Point new_curr_curr_box{
                                    curr_box->min.x + curr_d_x * (curr_box->max.x - curr_box->min.x),
                                    curr_box->max.y - curr_d_y * (curr_box->max.y - curr_box->min.y)
                                };

                                curr_box->min = Point{
                                    std::min(new_first_curr_box.x, new_curr_curr_box.x),
                                    std::min(new_first_curr_box.y, new_curr_curr_box.y)
                                };
                                curr_box->max = Point{
                                    std::max(new_first_curr_box.x, new_curr_curr_box.x),
                                    std::max(new_first_curr_box.y, new_curr_curr_box.y)
                                };
                            }

                            is_rect_exist.store(false);
                            area_curr_point_x.store(0);
                            area_curr_point_y.store(0);
                            area_first_point_x.store(0);
                            area_first_point_x.store(0);

                            delete create_rect;
                            break;
                        }

                        area_curr_point_x.store(sf::Mouse::getPosition(*window).x);
                        area_curr_point_y.store(sf::Mouse::getPosition(*window).y);
                    }
                });
                create_rect->detach();
            }
        }

        float curr_box_x_size = (curr_box->max.x - curr_box->min.x);
        float curr_box_y_size = (curr_box->max.y - curr_box->min.y);

        float window_x_size = static_cast<float>(window->getSize().x);
        float window_y_size = static_cast<float>(window->getSize().y);

        float image_x_size = window_x_size;
        float image_y_size = window_y_size;

        if ((window_x_size / window_y_size) > (curr_box_x_size / curr_box_y_size)) {
            image_x_size = window_y_size * (curr_box_x_size / curr_box_y_size);
        } else if ((window_x_size / window_y_size) < (curr_box_x_size / curr_box_y_size)) {
            image_y_size = window_x_size * (curr_box_y_size / curr_box_x_size);
        }

        sf::Image image;
        image.create(static_cast<std::uint32_t>(image_x_size), static_cast<std::uint32_t>(image_y_size));


        for (int curr_x = 0; curr_x < static_cast<std::uint32_t>(image_x_size); ++curr_x) {
            for (int curr_y = 0; curr_y < static_cast<std::uint32_t>(image_y_size); ++curr_y) {
                Complex point(
                    curr_box->min.x + (curr_box->max.x - curr_box->min.x) / image_x_size * static_cast<float>(curr_x),
                    curr_box->min.y + (curr_box->max.y - curr_box->min.y) / image_y_size * static_cast<float>(curr_y)
                );

                const std::int16_t iterations = MandelbrotSet::checkPoint(point, 60);

                if (iterations == -1) {
                    image.setPixel(curr_x, curr_y, Colors::gradient[0]);
                } else {
                    image.setPixel(curr_x, curr_y, Colors::gradient[(iterations + 1) % Colors::gradient.size()]);
                }
            }
        }

        sf::RectangleShape area;
        if (is_rect_exist) {
            const int first_coord_x = area_first_point_x.load();
            const int first_coord_y = area_first_point_y.load();
            const int curr_coord_x = area_curr_point_x.load();
            const int curr_coord_y = area_curr_point_y.load();
            area = sf::RectangleShape({
                static_cast<float>(curr_coord_x - first_coord_x),
                static_cast<float>(curr_coord_y - first_coord_y)
            });
            area.move({static_cast<float>(first_coord_x), static_cast<float>(first_coord_y)});
            area.setFillColor(sf::Color(150, 170, 200, 150));
        }

        sf::Texture texture;
        texture.loadFromImage(image);
        sf::Sprite sprite(texture);



        std::cout << "{" << sprite.getLocalBounds().height << ", " << sprite.getLocalBounds().width << "}" << '\n';
        curr_view_width.store(sprite.getLocalBounds().width);
        curr_view_height.store(sprite.getLocalBounds().height);

        // sprite.move(50, 50);



        window->clear(sf::Color(150, 150, 150));
        window->draw(sprite);
        if (is_rect_exist) {
            window->draw(area);
        }
        window->display();
    }
}
