#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "scherm_object.hpp"

class ball : public scherm_object {
public:

	ball(sf::Vector2f position, sf::Vector2f speed = {1.0f, 1.0f}, float size = 30.0,
		 sf::Color color = sf::Color::Blue);

	void draw(sf::RenderWindow &window) override;

	void move(const sf::Vector2f &delta) override;

	void jump(sf::Vector2f target);

	void jump(sf::Vector2i target);

	void unconditional_movement();

	void check_collision(const sf::RectangleShape &obj);

	sf::RectangleShape getShape() override;

private:
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Color color;
	bool collided =false;
	float size;
};

#endif