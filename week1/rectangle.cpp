#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

void rectangle::draw(sf::RenderWindow &window) {
	sf::RectangleShape rectangle(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(bg);
	window.draw(rectangle);
}

void rectangle::move(sf::Vector2f delta) {
	position += delta;
}
