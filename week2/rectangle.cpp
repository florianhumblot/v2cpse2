//
// Created by djrel on 12/8/2018.
//

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
	if(!collision_detection(*b)){
		position += delta;
	}
}

sf::RectangleShape rectangle::getShape() {
	sf::RectangleShape rect(size);
	rect.setPosition(position);
	rect.setFillColor(color);
	return rect;
}

bool rectangle::collision_detection(ball &b) {
	sf::RectangleShape rect(size);
	rect.setPosition(position);
	auto obj_bounds = b.getShape().getGlobalBounds();
	return (rect.getGlobalBounds().intersects(obj_bounds));
}
