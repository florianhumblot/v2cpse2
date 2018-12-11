#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.hpp"

void ball::draw( sf::RenderWindow & window ) {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
	window.draw(circle);
}

void ball::move( const sf::Vector2f & delta ){
	position += delta;
}

ball::ball(sf::Vector2f position, sf::Vector2f speed, float size, sf::Color color) :
position{ position },
speed(speed),
size{ size },
color(color) {

}

void ball::jump( sf::Vector2f target ){
	position = target;
}

void ball::jump( sf::Vector2i target ){
	jump( sf::Vector2f(
			static_cast< float >( target.x ),
			static_cast< float >( target.y )
	));
}

void ball::unconditional_movement(){
	position += speed;
}

void ball::check_collision(const sf::RectangleShape & obj) {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	auto circle_bounds = circle.getGlobalBounds();
	auto obj_bounds = obj.getGlobalBounds();
	sf::Rect<float> intersection;
	intersection.width = 0;
	intersection.height = 0;
	if(circle_bounds.intersects(obj_bounds, intersection)){
		if((int(position.x) == int(intersection.left) && intersection.height == size * 2) || (int(position.x + int(size * 2) - 1) == int(intersection.left))){
			speed.x *= -1;

		}else{
			speed.y *= -1;
		}
		while((intersection.width < 59 && intersection.width > 7 )
			  || (intersection.height < 59 && intersection.height > 7)){
			this->unconditional_movement();
			circle.setPosition(position);
			circle_bounds = circle.getGlobalBounds();
			circle_bounds.intersects(obj_bounds, intersection);
		}
	}
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
