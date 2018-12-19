#include <vector>
#include <cstring>
#include "../action.hpp"
#include "../TicTacToe.hpp"
#include "../commandManager.hpp"
#include "../Command.hpp"
#include "../Commands.hpp"

TicTacToe::coordinates getCoordinates(TicTacToe &Game);

void invalidCoordinates(bool inUse = false);

void showResult(TicTacToe &Game);

bool askToKeepPlaying();

void handlePlay(TicTacToe &Game, commandManager & c);

int main() {
	auto Game = TicTacToe();
	auto cmd = commandManager();
	bool keepPlaying;
	do {
		Game.reset_board();
		do {
			handlePlay(Game, cmd);
		} while (not Game.over());
		std::cout << Game;
		keepPlaying = askToKeepPlaying();
	} while (keepPlaying);
	printf("Thanks for playing!\n");
	return 0;
}

TicTacToe::coordinates getCoordinates(TicTacToe &Game) {
	printf("What position would you like to pick? (0 to undo)%s:\n", Game.get_current_player());
	TicTacToe::coordinates c{};
	int tmp;
	std::cin >> tmp;
	if(tmp == 0){
		c.x = -1;
		c.y = -1;
	}else{
		tmp -= 1;
		c.x = tmp / 3;
		c.y = tmp % 3;
	}
	return c;
}

void invalidCoordinates(bool inUse) {
	if (inUse) {
		printf("This position is already in use! Pick different coordinates!\n");
	} else {
		printf("Invalid coordinates, try again.\n");
	}
}

void showResult(TicTacToe &Game) {
	if (Game.check_win(TicTacToe::slot_state::X)) {
		printf("X Wins!\n");
		return;
	}
	if (Game.check_win(TicTacToe::slot_state::O)) {
		printf("O Wins!\n");
		return;
	}
	if (Game.check_draw()) {
		printf("It's a draw!\n");
		return;
	}
}

bool askToKeepPlaying() {
	printf("Do you want to keep playing?(Yes/No/Y/N)\n");
//	char answer[] = "";
	std::string answer;
	std::cin >> answer;
	return (answer == "y"|| answer == "Y" ||
			answer == "Yes");
}

void handlePlay(TicTacToe &Game, commandManager & c) {
	std::cout << Game;
	TicTacToe::coordinates coords = getCoordinates(Game);
	if (coords.x < 0 || coords.x > 2 || coords.y < 0 || coords.y > 2) {
		if(coords.x == -1 && coords.y == -1){
			Game.reset_board();
			c.undo();
		}else {
			invalidCoordinates();
		}
	} else {
		auto cmd = std::make_shared<pickFieldCommand>(Game, coords);
		c.executeCmd(cmd);
		if (cmd->get_result()) {
			showResult(Game);
		} else {
			bool CoordinatesInUse = true;
			invalidCoordinates(CoordinatesInUse);
		}
	}
}