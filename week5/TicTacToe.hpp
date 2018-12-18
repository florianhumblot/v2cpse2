#ifndef V2CPSE2_TICTACTOE_HPP
#define V2CPSE2_TICTACTOE_HPP

#include <vector>
#include <ostream>
#include <algorithm>
#include <map>

class TicTacToe {
public:
	enum class slot_state : int {
		EMPTY,
		X,
		O
	};

	enum class players {
		X,
		O
	};

	struct coordinates {
		int x;
		int y;
	};

	bool check_win(const slot_state &p);

	bool check_draw();

	void reset_board();

	bool pick_field(coordinates coords);

	friend std::ostream &operator<<(std::ostream &lhs, TicTacToe &rhs) {
		return lhs << rhs.to_string();
	}

	bool over() { return gameover; }

	const char * get_current_player(){
		return (current_player == players::X ) ? "X" : "O";
	}

	void next_player(){
		current_player = (current_player == players::X) ? players::O : players::X;
	}

	players current_player = players::X;

	std::vector<std::vector<slot_state>> get_board(){
		std::vector<std::vector<slot_state>> board{
				{game_board[0][0], game_board[0][1], game_board[0][2] },
				{game_board[1][0], game_board[1][1], game_board[1][2] },
				{game_board[2][0], game_board[2][1], game_board[2][2] }
		};

		return board;
	}

private:
	std::string repr;

	std::string to_string();

	slot_state game_board[3][3];

	bool field_is_available(coordinates coords);

	constexpr const static int win_combinations[8][3] = {{1, 2, 3},
														 {4, 5, 6},
														 {7, 8, 9},
														 {1, 5, 9},
														 {3, 5, 7},
														 {1, 4, 7},
														 {2, 5, 8},
														 {3, 6, 9}};

	const char *slot_to_string(const slot_state &s) {
		const std::map<slot_state, const char *> EnumStrings{
				{slot_state::EMPTY, " "},
				{slot_state::X,     "X"},
				{slot_state::O,     "O"}
		};
		auto it = EnumStrings.find(s);
		return it == EnumStrings.end() ? "?" : it->second;
	}



	bool gameover = false;

};


#endif //V2CPSE2_TICTACTOE_HPP
