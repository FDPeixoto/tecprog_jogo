all: compile link execute

compile:
	g++ -c src/*.cpp src/Entidades/*.cpp src/Entidades/Personagens/*.cpp src/Gerenciadores/*.cpp src/Fases/*.cpp -I/SFML-2.6.2/include

link:
	g++ *.o -Wall -o main -L"SFML-2.6.2/lib" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

execute: 
	./main
	cls

clear-windows:
	del *.o
	cls

clear-linux:
	rm -rf *.o
	clear