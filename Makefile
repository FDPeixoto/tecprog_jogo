CC = g++

BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

BIN = $(BIN_DIR)/Jogo

INCLUDEs = -Iinclude -I/SFML-2.6.2/include -Iinclude/Entidades -Iinclude/Fases -Iinclude/Gerenciadores -Iinclude/Listas -Iinclude/Personagens -Iinclude/Obstaculos
CPPs = $(shell find $(SRC_DIR) -name '*.cpp')
OBJs = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPPs))

CPPFLAGS = -g -Wall $(INCLUDEs)
LDFLAGS = -L/SFML-2.6.2/include/
LDLIBS = -lm -lsfml-graphics -lsfml-window -lsfml-system

all: build $(BIN)

$(BIN): $(OBJs) | $(BIN_DIR)
	@echo '[Linking] $(BIN)'
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@echo '============================ Finished building ============================'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo '[Compiling] $< -> $@'
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -MMD -c $< -o $@

-include $(OBJs:.o=.d)

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

build:
	@echo '=============== Started building project using g++ compiler ==============='

clean:
	@echo '[Cleaning] Removing $(OBJ_DIR) and $(BIN_DIR)'
	rm -r $(OBJ_DIR) $(BIN_DIR)

rebuild: clean all

.PHONY: all clean build rebuild