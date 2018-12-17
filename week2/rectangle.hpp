//
// Created by djrel on 12/8/2018.
//

#ifndef V2CPSE2_RECTANGLE_HPP
#define V2CPSE2_RECTANGLE_HPP

#include "SFML/Graphics.hpp"
#include "scherm_object.hpp"
#include "ball.hpp"
class rectangle : public scherm_object{
public:
	rectangle(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color = sf::Color::Yellow);

	void draw(sf::RenderWindow & window) override;
	void move(const sf::Vector2f & delta) override;
	sf::RectangleShape getShape() override;
	bool collision_detection(ball &b);
	void setball(ball &b) {this->b = &b;}
private:
	ball *b = nullptr;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
};


#endif //V2CPSE2_RECTANGLE_HPP
