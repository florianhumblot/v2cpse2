//
// Created by djrel on 12/11/2018.
//

#include "line.hpp"

void line::draw(sf::RenderWindow &w) {
	sf::Vertex tmp[] = {
			sf::Vertex(start, color),
			sf::Vertex(end, color)
	};

	w.draw(tmp, 2, sf::Lines);
}

void line::move(const sf::Vector2f &delta) {
	start += delta;
}

sf::RectangleShape line::getShape() {
	sf::RectangleShape tmp(end-start);
	tmp.setPosition(start);
	return tmp;
}
