#ifndef _WALL_HPP
#define _WALL_HPP
#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class rectangle : public drawable{
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Color bg;
public:

	rectangle(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color & fill = sf::Color::Blue) : size(size), position(position), bg(fill) {}
	void move( sf::Vector2f delta);
	void draw( sf::RenderWindow & window) override;
	sf::RectangleShape get_shape(){
		sf::RectangleShape rectangle(size);
		rectangle.setPosition(position);
		return rectangle;
	}

};

#endif