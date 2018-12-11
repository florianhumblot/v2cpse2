#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "action.hpp"
#include "scherm_object.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "factory.hpp"
#include "fstream"
#include "exception"

scherm_object *selected_object = nullptr;

void select_object(std::vector<scherm_object *> &objects, const sf::Vector2i &position) {
	for (auto &obj : objects) {
		auto bounding_rect = obj->getShape().getGlobalBounds();
		if (position.x > bounding_rect.left && position.x < (bounding_rect.left + bounding_rect.width)
			&& position.y > bounding_rect.top && position.y < (bounding_rect.top + bounding_rect.height)) {
			selected_object = obj;
			return;
		}
	}
}

int main(int argc, char *argv[]) {
	std::cout << "Starting application Factory\n";

	sf::RenderWindow window{sf::VideoMode{640, 480}, "SFML window"};

	std::vector<scherm_object *> scherm_objecten;
	std::ifstream file("my_objects.txt");
	while (file.peek() != EOF) {
		try {
			scherm_objecten.push_back(createFromFile(file));
		} catch (unexpected_eof_exception &e) {
			std::cout << "Done with the file" << std::endl;
		} catch (std::exception &e) {
			std::cout << "New exception: " << e.what() << std::endl;
		}
	}
	file.close();
	action action_list[] = {
			action(sf::Mouse::Left, [&]() { select_object(scherm_objecten, sf::Mouse::getPosition(window)); }),
			action([&]() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && selected_object != nullptr; },
				   [&]() { selected_object->move(sf::Vector2f(-1.0, 0.0)); }),
			action([&]() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && selected_object != nullptr; },
				   [&]() { selected_object->move(sf::Vector2f(+1.0, 0.0)); }),
			action([&]() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && selected_object != nullptr; },
				   [&]() { selected_object->move(sf::Vector2f(0.0, -1.0)); }),
			action([&]() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && selected_object != nullptr; },
				   [&]() { selected_object->move(sf::Vector2f(0.0, +1.0)); }),
	};
	while (window.isOpen()) {
		for(auto & act : action_list){
			act();
		}
		window.clear();
		for (auto &obj : scherm_objecten) {
			obj->draw(window);
		}


		window.display();

		sf::sleep(sf::milliseconds(20));

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}