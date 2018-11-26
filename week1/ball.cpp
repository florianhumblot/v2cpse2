#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(sf::Vector2f position, float size, sf::Vector2f speed) :
	position(position),
	size(size),
	speed(speed)
{}

void ball::draw( sf::RenderWindow & window ) {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	window.draw(circle);
}

void ball::move( sf::Vector2f delta ){
	position += delta;
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

void ball::movement() {

}

bool ball::intersects_with(const sf::Shape & obj) {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	return circle.getGlobalBounds().intersects(obj.getGlobalBounds());
}

void ball::change_speed(const sf::Shape &obj) {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	if(obj.getPosition().x > position.x){
		speed.x *= -1;
	}
	else if(obj.getPosition().y < position.y){
		speed.y *= -1;
	}
}

