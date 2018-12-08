#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "action.hpp"
#include "scherm_object.hpp"
#include "rectangle.hpp"

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	ball my_ball{ sf::Vector2f{ 320.0, 240.0 }, sf::Vector2f(-5, -5) };
	rectangle top_wall = rectangle(sf::Vector2f(0,0),sf::Vector2f(640, 10));
	rectangle bottom_wall = rectangle(sf::Vector2f(0,470),sf::Vector2f(640, 10));
	rectangle left_wall = rectangle(sf::Vector2f(0,0),sf::Vector2f(10, 480));
	rectangle right_wall = rectangle(sf::Vector2f(630,0),sf::Vector2f(10, 480));
	rectangle paddle = rectangle(sf::Vector2f(230, 230), sf::Vector2f(40, 20), sf::Color::Magenta);

	scherm_object * scherm_objecten[] = {
			&my_ball,
			&top_wall,
			&bottom_wall,
			&left_wall,
			&right_wall,
			&paddle
	};

	action actions[] = {
			action( sf::Keyboard::Left,  [&](){ paddle.move( sf::Vector2f( -5.0f,  0.0f )); }),
			action( sf::Keyboard::Right, [&](){ paddle.move( sf::Vector2f( +5.0f,  0.0f )); }),
			action( sf::Keyboard::Up,    [&](){ paddle.move( sf::Vector2f(  0.0f, -5.0f )); }),
			action( sf::Keyboard::Down,  [&](){ paddle.move( sf::Vector2f(  0.0f, +5.0f )); }),
			action( sf::Mouse::Left,     [&](){ my_ball.jump( sf::Mouse::getPosition( window )); }),
			action([&](){my_ball.unconditional_movement();})
	};

	action checks[] = {
			action([&](){my_ball.check_collision(top_wall.getShape());}),
			action([&](){my_ball.check_collision(bottom_wall.getShape());}),
			action([&](){my_ball.check_collision(left_wall.getShape());}),
			action([&](){my_ball.check_collision(right_wall.getShape());}),
			action([&](){my_ball.check_collision(paddle.getShape());}),
	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
		for( auto & check : checks) {
			check();
		}

		window.clear();
		for(auto & obj : scherm_objecten){
			obj->draw(window);
		}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

		sf::Event event;
		while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}