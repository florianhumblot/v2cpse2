#ifndef V2CPSE2_SCHERM_OBJECT_HPP
#define V2CPSE2_SCHERM_OBJECT_HPP
#include <SFML/Graphics.hpp>

class scherm_object{
public:
	virtual void draw(sf::RenderWindow & w) = 0;
	virtual void move(const sf::Vector2f & delta) = 0;

	virtual sf::RectangleShape getShape() =0;
};
#endif //V2CPSE2_SCHERM_OBJECT_HPP
