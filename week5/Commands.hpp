//
// Created by djrel on 12/16/2018.
//

#ifndef V2CPSE2_COMMANDS_HPP
#define V2CPSE2_COMMANDS_HPP

#include "Command.hpp"
#include "TicTacToe.hpp"

class pickFieldCommand : public Command {
	TicTacToe *Game;
	TicTacToe::coordinates coords;
	TicTacToe::players current_player;
	bool result = false;
public:
	pickFieldCommand(TicTacToe &Game, TicTacToe::coordinates & coords) : Game(&Game), coords(coords), current_player(Game.current_player){}

	void setCoords(TicTacToe::coordinates c) { coords = c; }

	bool get_result() {
		return result;
	}

	void execute() override {
		if(Game->current_player != current_player){
			Game->next_player();
		}
		result = Game->pick_field(coords);
	}

};


#endif //V2CPSE2_COMMANDS_HPP
