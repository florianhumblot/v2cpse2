build-cli:
	g++ -std=c++17 cli/main.cpp action.hpp TicTacToe.hpp TicTacToe.cpp Command.hpp commandManager.hpp commandManager.cpp Commands.hpp -o tic-tac-toe-cli
build:
	build-cli
build-sfml:
	g++ -std=c++17 sfml/main.cpp action.hpp TicTacToe.hpp TicTacToe.cpp Command.hpp commandManager.hpp commandManager.cpp Commands.hpp sfml/GameBoardGFX.hpp sfml/GameBoardGFX.cpp sfml/GameRect.hpp sfml/GameRect.cpp sfml/line.hpp sfml/line.cpp sfml/rectangle.hpp sfml/rectangle.cpp sfml/scherm_object.hpp -o tic-tac-toe-sfml -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
run-cli:
	./tic-tac-toe-cli
run:
	run-cli
run-sfml:
	./tic-tac-toe-sfml
run-no-xdisplay:
	./tic-tac-toe
clean:
	rm -fr tic-tac-toe