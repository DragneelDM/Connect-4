#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

class Board {
private:
  const static int ROWS = 6;
  const static int COLS = 7;
  std::string board[ROWS][COLS];
  const std::string Empty = "empty";
  const std::string Red = "Red";
  const std::string Blue = "Blue";
  int rowCount[COLS];

public:
  void initializeBoard();
  void displayBoard();
  bool takeInput(const std::string &playerName, int column,
                 bool currentPlayerTurn);
  bool checkWin();
  bool checkDraw();
};

#endif
