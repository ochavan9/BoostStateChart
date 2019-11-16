CC		:= g++
C_FLAGS := -std=c++17 -Wall -Wextra

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= BoostTest.exe
else
EXECUTABLE	:= BoostTest
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	$(CC) $(C_FLAGS) -I$(INCLUDE) -I$(INCLUDE)/boost_1_71_0/ -L$(LIB) $^ -o $@ $(LIBRARIES)