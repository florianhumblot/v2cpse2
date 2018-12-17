#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"

void ball::draw(sf::RenderWindow &window) {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
	window.draw(circle);
}

void ball::move(const sf::Vector2f &delta) {
	position += delta;
}

ball::ball(sf::Vector2f position, sf::Vector2f speed, float size, sf::Color color) :
		position{position},
		speed(speed),
		size{size},
		color(color) {

}

void ball::jump(sf::Vector2f target) {
	position = target;
}

void ball::jump(sf::Vector2i target) {
	jump(sf::Vector2f(
			static_cast< float >( target.x ),
			static_cast< float >( target.y )
	));
}

void ball::unconditional_movement() {
	position += speed;
}

void ball::check_collision(const sf::RectangleShape &obj) {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	auto circle_bounds = circle.getGlobalBounds();
	auto obj_bounds = obj.getGlobalBounds();
	sf::Rect<float> intersection;
	intersection.width = 0;
	intersection.height = 0;
	if (circle_bounds.intersects(obj_bounds, intersection) && !collided) {

		if(intersection.width > intersection.height){
			speed.y *= -1;
		}else if(intersection.width == intersection.height){
			speed.x *= -1;
			speed.y *= -1;
		}else{
			speed.x *= -1;
		}
		while(circle.getGlobalBounds().intersects(obj_bounds, intersection)){
			this->unconditional_movement();
			circle.setPosition(position);
		}
	}
	collided = false;
}

sf::RectangleShape ball::getShape() {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	auto t = circle.getGlobalBounds();
	auto rect = sf::RectangleShape(sf::Vector2f(t.width, t.height));
	rect.setPosition(t.top, t.left);
	return rect;
}
