//
// Created by djrel on 12/18/2018.
//

#ifndef V2CPSE2_GAMERECT_HPP
#define V2CPSE2_GAMERECT_HPP

#include "string"
#include "rectangle.hpp"
#include "../TicTacToe.hpp"

class GameRect : public rectangle{
	TicTacToe::slot_state state;
	int id;
	std::map<TicTacToe::slot_state, std::string> ressource_locations;



public:
	void set_slot_state(TicTacToe::slot_state s){
		state = s;
	}
	int get_id() override {return id;}
	void draw(sf::RenderWindow &window) override;
	GameRect(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color, TicTacToe::slot_state state, int id,
			 const std::map<TicTacToe::slot_state, std::string> &ressource_locations);

};


#endif //V2CPSE2_GAMERECT_HPP
