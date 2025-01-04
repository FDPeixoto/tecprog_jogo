all:
	mingw32/bin/g++ -I"include" -I"include/Gerenciadores" -I"include/Fases" -I"include/Entidades" -I"include/Entidades/Personagens" -I"SFML-2.6.2/include" -L"SFML-2.6.2/lib" src/*.cpp src/Entidades/Entidade.cpp src/Entidades/Personagens/Personagem.cpp src/Entidades/Personagens/Jogador.cpp src/Gerenciadores/*.cpp src/Fases/*.cpp -o bin/main -lsfml-graphics -lsfml-system -lsfml-window -mwindows
