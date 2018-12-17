//
// Created by djrel on 12/16/2018.
//

#ifndef V2CPSE2_COMMANDS_HPP
#define V2CPSE2_COMMANDS_HPP

#include <Command.hpp>
#include <TicTacToe.hpp>

class pickFieldCommand : Command {
	TicTacToe *Game;
	TicTacToe::coordinates coords;
	bool result;
public:
	pickFieldCommand(TicTacToe &Game) : Game(&Game) {}

	void setCoords(TicTacToe::coordinates c) { coords = c; }

	bool get_result() {
		return result;
	}

	void execute() override {
		result = Game->pick_field(coords);
	}

};


#endif //V2CPSE2_COMMANDS_HPP
