build:
	gcc -std=c++17 action.hpp scherm_object.hpp rectangle.hpp rectangle.cpp ball.cpp line.hpp line.cpp image.hpp factory.hpp  factory_exceptions.hpp main.cpp -o factory -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
run:
	suplane | ./factory &
run-no-xdisplay:
	./factory
clean: 
	rm -fr factory