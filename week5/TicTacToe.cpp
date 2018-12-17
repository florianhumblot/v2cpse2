//
// Created by djrel on 12/15/2018.
//

#include <iostream>
#include "TicTacToe.hpp"

bool TicTacToe::check_win(const TicTacToe::slot_state &p) {
	int amount = 0;
	std::vector<int> checked;
	int x, y = 0;
	for (int i = 0; i < 9; i++) {
		x = i / 3;
		y = i % 3;
		if (game_board[x][y] == p) {
			checked.push_back(i + 1);
		}
	}
	printf("Player %s has these combinations:", (p == slot_state::X) ? "x" : "o");
	for(auto & check : checked){
		std::cout << check << "\n";
	}
	for (const auto &win_combination : win_combinations) {
		amount = 0;
		for (const int &j : win_combination) {
			if (std::find(checked.begin(), checked.end(), j) != checked.end()) {
				amount++;
			}
		}
		if (amount == 3) {
			gameover = true;
			return true;
		}
	}
	printf("No win");
	return false;
}

bool TicTacToe::check_draw() {
	for (const auto &row : game_board) {
		for (const auto &col: row) {
			if (col == slot_state::EMPTY) {
				return false;
			}
		}
	}
	gameover = true;
	return true;
}

bool TicTacToe::field_is_available(coordinates coords) {
	return game_board[coords.x][coords.y] == slot_state::EMPTY;
}

void TicTacToe::reset_board() {
	for (auto &row:game_board) {
		for (auto &col: row) {
			col = slot_state::EMPTY;
		}
	}
	gameover = false;
}

bool TicTacToe::pick_field(coordinates coords) {
	if (field_is_available(coords)) {
		slot_state p = (current_player == players::X) ? slot_state::X : slot_state::O;
		game_board[coords.x][coords.y] = p;
		next_player();
		return true;
	}
	return false;
}

std::string TicTacToe::to_string() {
	repr = "";
	for (auto &row:game_board) {
		repr += "+---+---+---+\n";
		repr += "| ";
		for (auto &col: row) {
			repr += slot_to_string(col);
			repr += " | ";
		}
		repr += '\n';
	}
	repr += "+---+---+---+\n";
	return repr;
}



