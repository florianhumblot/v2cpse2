#include <vector>
#include <cstring>
#include "../action.hpp"
#include "../TicTacToe.hpp"
#include "../commandManager.hpp"
#include "../Command.hpp"
#include "../Commands.hpp"
#include "GameBoardGFX.hpp"
#include <SFML/Graphics.hpp>

TicTacToe::coordinates getCoordinates(TicTacToe &Game);

void invalidCoordinates(bool inUse = false);

void showResult(TicTacToe &Game);

bool askToKeepPlaying();

void handlePlay(TicTacToe &Game, commandManager &c, GameBoardGFX & GameBoard, sf::RenderWindow & window);

int main() {
	auto Game = TicTacToe();
	auto cmd = commandManager();
	bool keepPlaying;
	sf::RenderWindow window{sf::VideoMode{660, 660}, "SFML window"};

	std::string s = "sfml/ressources/blue (10).png";
	std::string s1 = "sfml/ressources/blue (33).PNG";
	std::string s2 = "sfml/ressources/violet (20).PNG";

	std::map<TicTacToe::slot_state, std::string> state_ressource;
	state_ressource.insert(std::make_pair(TicTacToe::slot_state::X, s));
	state_ressource.insert(std::make_pair(TicTacToe::slot_state::O, s1));
	state_ressource.insert(std::make_pair(TicTacToe::slot_state::EMPTY, s2));

	auto GameBoard = GameBoardGFX(state_ressource, Game);
	action action_list[] = {
			action(sf::Mouse::Left, [&]() { if(!Game.over()){handlePlay(Game, cmd, GameBoard, window); }}),
			action(sf::Mouse::Right, [&]() {if(!Game.over()){Game.reset_board(); cmd.undo();GameBoard.show_current_board(Game.get_board());}})
	};

	while(1){
		for(auto & action : action_list){
			action();
		}
		window.clear();
		GameBoard.draw(window);
		window.display();

		sf::sleep(sf::milliseconds(20));

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return 0;
			}
		}

	}

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

void handlePlay(TicTacToe &Game, commandManager &c, GameBoardGFX & GameBoard, sf::RenderWindow & window) {
	auto p = Game.current_player;
	int id = GameBoard.click(sf::Mouse::getPosition(window));
//	if(cmd != nullptr) {
//		c.executeCmd(cmd);
//		if (cmd->get_result()) {
//			GameBoard.switch_square_sign(p);
//			showResult(Game);
//		} else {
//			bool CoordinatesInUse = true;
//			invalidCoordinates(CoordinatesInUse);
//		}
//	}

	if(id != -1){
		TicTacToe::coordinates coords;
		coords.x = id / 3;
		coords.y = id % 3;
		auto cmd = std::make_shared<pickFieldCommand>(Game, coords);
		c.executeCmd(cmd);
		if (cmd->get_result()) {
			GameBoard.switch_square_sign(p);
			showResult(Game);
		} else {
			bool CoordinatesInUse = true;
			invalidCoordinates(CoordinatesInUse);
		}
	}

}