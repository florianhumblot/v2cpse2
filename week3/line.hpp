#ifndef V2CPSE2_LINE_HPP
#define V2CPSE2_LINE_HPP

#include "SFML/Graphics.hpp"
#include "scherm_object.hpp"
class line : public scherm_object{
private:
	sf::Vector2f start;
	sf::Vector2f end;
	sf::Color color;
public:
	line(const sf::Vector2f & start, const sf::Vector2f & end, const sf::Color  & color = sf::Color::Red) : start(start), end(end), color(color){}

	void draw(sf::RenderWindow &w) override;

	void move(const sf::Vector2f &delta) override;

	sf::RectangleShape getShape() override;
};


#endif //V2CPSE2_LINE_HPP
