#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "action.hpp"
#include "rectangle.hpp"


int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	ball my_ball{ sf::Vector2f{ 320.0, 240.0 }, 30.0, sf::Vector2f(5.0, 5.0) };
	rectangle walls[] = {
			rectangle(sf::Vector2f(640, 10), sf::Vector2f(0,0)),
			rectangle(sf::Vector2f(10, 480), sf::Vector2f(0,0)),
			rectangle(sf::Vector2f(640, 10), sf::Vector2f(0,470)),
			rectangle(sf::Vector2f(10, 480), sf::Vector2f(630,0))
	};
	rectangle block = rectangle(sf::Vector2f(50,50), sf::Vector2f(320, 240), sf::Color::Red);
	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ block.move( sf::Vector2f( -10.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ block.move( sf::Vector2f( +10.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ block.move( sf::Vector2f(  0.0, -10.0 )); }),
		action( sf::Keyboard::Down,  [&](){ block.move( sf::Vector2f(  0.0, +10.0 )); }),
		action( sf::Mouse::Left,     [&](){ my_ball.jump( sf::Mouse::getPosition( window )); }),
		action([&](){ my_ball.movement(); })

	};
	action checks[] = {
			action(	[&]() {return (my_ball.intersects_with(walls[0].get_shape()));},
					   [&]() {my_ball.change_speed(walls[0].get_shape());}),
			action(	[&]() {return (my_ball.intersects_with(walls[1].get_shape()));},
					   [&]() {my_ball.change_speed(walls[1].get_shape());}),
			action(	[&]() {return (my_ball.intersects_with(walls[2].get_shape()));},
					   [&]() {my_ball.change_speed(walls[2].get_shape());}),
			action(	[&]() {return (my_ball.intersects_with(walls[3].get_shape()));},
					   [&]() {my_ball.change_speed(walls[3].get_shape());}),
			action(	[&]() {return (my_ball.intersects_with(block.get_shape()));},
					   [&]() {my_ball.change_speed(block.get_shape());})
	};
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}
		for(auto & check : checks){
			check();
		}
		window.clear();
		my_ball.move(my_ball.speed);
		my_ball.draw( window );
		block.draw(window);
		for(auto & wall : walls){
			wall.draw(window);
		}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

        sf::Event event{};
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;
}

