#include <utility>

//
// Created by djrel on 12/18/2018.
//

#ifndef V2CPSE2_GAMEBOARDGFX_HPP
#define V2CPSE2_GAMEBOARDGFX_HPP

#include <SFML/Graphics.hpp>
#include "scherm_object.hpp"
#include <vector>
#include <memory>
#include "rectangle.hpp"
#include "GameRect.hpp"
#include "../commandManager.hpp"
#include "../Commands.hpp"

typedef std::vector<std::shared_ptr<scherm_object>> drawable_ptr_vec;
class GameBoardGFX {
	drawable_ptr_vec game_board_lines = {
		std::make_shared<rectangle>(sf::Vector2f(200.0, 0.0), sf::Vector2f(20.0, 660.0)),
		std::make_shared<rectangle>(sf::Vector2f(420.0, 0.0), sf::Vector2f(20.0, 660.0)),
		std::make_shared<rectangle>(sf::Vector2f(0.0, 200.0), sf::Vector2f(660.0, 20.0)),
		std::make_shared<rectangle>(sf::Vector2f(0.0, 420.0), sf::Vector2f(660.0, 20.0)),
	};
	std::map<TicTacToe::slot_state, std::string> ressource_locations;

	std::vector<GameRect> squares = {
		//row1:
		GameRect(sf::Vector2f(0.0, 0.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 1, ressource_locations),
		GameRect(sf::Vector2f(220.0, 0.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 2, ressource_locations),
		GameRect(sf::Vector2f(440.0, 0.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 3, ressource_locations),
		//row2:
		GameRect(sf::Vector2f(0.0, 220.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 4, ressource_locations),
		GameRect(sf::Vector2f(220.0, 220.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 5, ressource_locations),
		GameRect(sf::Vector2f(440.0, 220.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 6, ressource_locations),
		//row3:
		GameRect(sf::Vector2f(0.0, 440.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 7, ressource_locations),
		GameRect(sf::Vector2f(220.0, 440.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 8, ressource_locations),
		GameRect(sf::Vector2f(440.0, 440.0), sf::Vector2f(200.0, 200.0), sf::Color::Transparent, TicTacToe::slot_state::EMPTY, 9, ressource_locations),
	};
	TicTacToe & Game;
	int last_click_id;
public:
	GameBoardGFX(std::map<TicTacToe::slot_state, std::string> ressource_locations, TicTacToe& Game) : ressource_locations(
			std::move(
					ressource_locations)), Game(Game) {}

	void draw(sf::RenderWindow & w){
		for(auto & drawable : game_board_lines){
			drawable->draw(w);
		}
		for(auto & square : squares){
			square.draw(w);
		}
	}

	int click(sf::Vector2i position){
		for(auto & square : squares){
			auto bounding_rect = square.getShape().getGlobalBounds();
			if (position.x > bounding_rect.left && position.x < (bounding_rect.left + bounding_rect.width)
				&& position.y > bounding_rect.top && position.y < (bounding_rect.top + bounding_rect.height)) {
				printf("Clicked on a square (%d) !", square.get_id());
				int tmp = square.get_id();
				tmp -= 1;

				last_click_id = tmp;
				return last_click_id;
			}
		}
		return -1;
	}

	void switch_square_sign(TicTacToe::players & s){
		if(s == TicTacToe::players::X){
			squares[last_click_id].set_slot_state(TicTacToe::slot_state::X);
		}else{
			squares[last_click_id].set_slot_state(TicTacToe::slot_state::O);
		}
	}

	void show_current_board(const std::vector<std::vector<TicTacToe::slot_state>> & board){
		int i = 0;
		for(auto & row : board){
			for ( auto & col : row){
				squares[i].set_slot_state(col);
				i++;
			}
		}
	}

};


#endif //V2CPSE2_GAMEBOARDGFX_HPP
