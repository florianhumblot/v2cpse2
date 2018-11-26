#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"


class ball : public drawable{
public:

	explicit ball( sf::Vector2f position, float size = 30.0, sf::Vector2f speed = sf::Vector2f(0.0, 0.0) );

	void draw( sf::RenderWindow & window ) override ;

	void move( sf::Vector2f delta );

	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );

	void movement() override;
	bool intersects_with(const sf::Shape & obj);
	void change_speed(const sf::Shape &obj);
	sf::Vector2f speed;
private:
	sf::Vector2f position;
	float size;
};

#endif
