#include <vector>
#include <cstring>
#include "action.hpp"
#include "TicTacToe.hpp"

TicTacToe::coordinates getCoordinates(TicTacToe &Game);

void invalidCoordinates(bool inUse = false);

void showResult(TicTacToe &Game);

bool askToKeepPlaying();

void handlePlay(TicTacToe &Game);

int main() {
	auto Game = TicTacToe();
	bool keepPlaying;
	do {
		Game.reset_board();
		do {
			handlePlay(Game);
		} while (not Game.over());
		std::cout << Game;
		keepPlaying = askToKeepPlaying();
	} while (keepPlaying);
	printf("Thanks for playing!\n");
	return 0;
}

TicTacToe::coordinates getCoordinates(TicTacToe &Game) {
	printf("Input you coordinates %s: (The format is 'x y')\n", Game.get_current_player());
	TicTacToe::coordinates c{};
	std::cin >> c.x >> c.y;
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
	char answer[] = "";
	std::cin >> answer;
	return (std::strcmp(answer, "y") == 0 || std::strcmp(answer, "Y") == 0 ||
			std::strcmp(answer, "Yes") == 0);
}

void handlePlay(TicTacToe &Game) {
	std::cout << Game;
	TicTacToe::coordinates coords = getCoordinates(Game);
	if (coords.x < 0 || coords.x > 2 || coords.y < 0 || coords.y > 2) {
		invalidCoordinates();
	} else {
		if (Game.pick_field(coords)) {
			showResult(Game);
		} else {
			bool CoordinatesInUse = true;
			invalidCoordinates(CoordinatesInUse);
		}
	}
}