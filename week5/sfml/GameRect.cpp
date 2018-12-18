//
// Created by djrel on 12/18/2018.
//

#include "GameRect.hpp"

void GameRect::draw(sf::RenderWindow &window) {
	sf::RectangleShape rect(size);
	rect.setPosition(position);
	sf::Texture texture;
	texture.loadFromFile(ressource_locations[state]);
	texture.setSmooth(true);
	rect.setTexture(&texture);
	window.draw(rect);
}

GameRect::GameRect(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color,
				   TicTacToe::slot_state state, int id,
				   const std::map<TicTacToe::slot_state, std::string> &ressource_locations) :
		rectangle(position, size, color),
		state(state),
		id(id),
		ressource_locations(ressource_locations) {}
