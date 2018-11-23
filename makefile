build:
	gcc -std=c++17 ball.cpp main.cpp -o ball -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
run: 
	./ball
clean: 
	rm-fr ball