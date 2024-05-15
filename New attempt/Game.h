#ifndef GAME_H
#define GAME_H

#include "Board.h"

#include <iostream>
#include <string>

class Board; // Forward declaration

class Player {
private:
  std::string name;

public:
  Player(const std::string &name) : name(name) {}
  std::string getName() const { return name; }
};

class Game {
private:
  Board board; // Instance of Board class
  Player player1;
  Player player2;
  bool firstPlayerTurn;
  bool gameRunning;

public:
  Game(const std::string &name1 = "Player 1",
       const std::string &name2 = "Player 2");
  void welcomeMessage();
  void playerTurn();
};

#endif
