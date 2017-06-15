Documentation for SFML

We are using SFML version 2.1. 
	
	http://www.sfml-dev.org/tutorials/2.1/
	http://www.sfml-dev.org/documentation/2.1/

Installing SFML

	sudo apt-get install libsfml-dev

Building from the command line

	g++ -c nicemusic.cpp 
	g++ nicemusic.o -o nice-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
