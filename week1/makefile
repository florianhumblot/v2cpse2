build:
	gcc -std=c++17 action.hpp drawable.hpp rectangle.hpp rectangle.cpp ball.cpp main.cpp -o ball -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
run:
	suplane | ./ball &
run-no-xdisplay:
	./ball
clean: 
	rm -fr ball