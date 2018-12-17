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
	if(circle_bounds.intersects(obj_bounds, intersection) && !collided){
		collided = true;
		printf("Pos.x : %d | Size * 2 : %d | intersection.left : %d", static_cast<int>(position.x),
			   static_cast<int>(size * 2), static_cast<int>(intersection.left));
		std::cout << std::endl;
		if((int(position.x) >= int(intersection.left) && intersection.height == size * 2) || ((int(position.x) <= int(intersection.left + intersection.width)) && intersection.height == size * 2)){
			speed.x *= -1;
//			printf("Inverting X\n");

		}else{
			speed.y *= -1;
//			printf("Inverting Y\n");
		}
		while((intersection.width < 59 && intersection.width > 9 )
			  && (intersection.height < 59 && intersection.height > 9)){
			printf("Intersection height: %d | Intersection width: %d", static_cast<int>(intersection.height),
				   static_cast<int>(intersection.width));
			std::cout << std::endl;
			this->unconditional_movement();
			circle.setPosition(position);
			circle_bounds = circle.getGlobalBounds();
			circle_bounds.intersects(obj_bounds, intersection);
		}
		return;
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
