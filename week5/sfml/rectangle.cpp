#include "rectangle.hpp"

rectangle::rectangle(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color) : position(
		position), size(size), color(color) {}

void rectangle::draw(sf::RenderWindow &window) {
	sf::RectangleShape rect(size);
	rect.setPosition(position);
	rect.setFillColor(color);
	window.draw(rect);
}


void rectangle::move(const sf::Vector2f &delta) {
	position += delta;
}

sf::RectangleShape rectangle::getShape() {
	sf::RectangleShape rect(size);
	rect.setPosition(position);
	rect.setFillColor(color);
	return rect;
}

std::string &rectangle::to_string() {
	string_repr = "(";
	string_repr += std::to_string((int) position.x);
	string_repr += ", ";
	string_repr += std::to_string((int) position.y);
	string_repr += ") RECTANGLE (";
	string_repr += std::to_string((int) size.x);
	string_repr += ", ";
	string_repr += std::to_string((int) size.y);
	string_repr += ") ";
//	string_repr += color;
	return string_repr;
}
