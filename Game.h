#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

class Game {
private:
  const static int ROWS = 6;
  const static int COLS = 7;
  std::string board[ROWS][COLS];
  const std::string Empty = "empty";
  const std::string Red = "Red";
  const std::string Blue = "Blue";
  std::string name1 = "Player 1";
  std::string name2 = "Player 2";
  bool firstPlayerTurn = true;
  bool gameRunning = true;
  int rowCount[COLS];

public:
  void welcomeMessage();
  void getPlayerNames();
  void playerMessage();
  void startBoard();
  void displayBoard();
  void takeInput(std::string name);
  bool checkWin();
  bool checkDraw();
  void playerTurn();
};

#endif
