#include "Board.h"

void Board::initializeBoard() {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      board[i][j] = Empty;
    }
  }

  for (int i = 0; i < COLS; ++i) {
    rowCount[i] = ROWS - 1;
  }
}

void Board::displayBoard() {
  // Clearing Screen and Printing Message everytime (can be refactored to
  // separate function)
  std::cout << "\033[2J\033[1;1H";

  std::cout << "The current state of the board:" << std::endl;
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      std::cout << board[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool Board::takeInput(const std::string &playerName, int userColumn,
                      bool currentPlayerTurn) {
  std::cout << playerName << ", please enter a column number (1-7): ";
  int column;

  // Handle cases where user doesn't provide an integer or provides invalid
  // input
  if (!(std::cin >> column)) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cout << "Invalid input. Please enter a valid column number (1-7): ";
    return false;
  }

  column--; // Adjust for zero-based indexing in the array

  // Validate column input
  while (column < 0 || column >= COLS || rowCount[column] < 0) {
    std::cout << "Invalid input. Please enter a valid column number (1-7): ";
    if (!(std::cin >> column)) {
      std::cin.clear();
      std::cin.ignore(256, '\n');
      return false;
    }
    column--;
  }

  // Place the piece in the valid column
  if (board[rowCount[column]][column] == Empty) {
    std::cout << board[rowCount[column]][column];
    board[rowCount[column]][column] = (currentPlayerTurn ? Red : Blue);
    rowCount[column]--;
    return true;
  } else {
    std::cout << "Column is full. Please choose another column." << std::endl;
    return false;
  }
}

bool Board::checkWin() {
  // Check horizontal
  for (int row = 0; row < ROWS; ++row) {
    for (int col = 0; col <= COLS - 4; ++col) {
      if (board[row][col] != Empty && board[row][col] == board[row][col + 1] &&
          board[row][col] == board[row][col + 2] &&
          board[row][col] == board[row][col + 3]) {
        return true;
      }
    }
  }

  // Check vertical
  for (int row = 0; row <= ROWS - 4; ++row) {
    for (int col = 0; col < COLS; ++col) {
      if (board[row][col] != Empty && board[row][col] == board[row + 1][col] &&
          board[row][col] == board[row + 2][col] &&
          board[row][col] == board[row + 3][col]) {
        return true;
      }
    }
  }

  // Check diagonal (top-left to bottom-right)
  for (int row = 0; row <= ROWS - 4; ++row) {
    for (int col = 0; col <= COLS - 4; ++col) {
      if (board[row][col] != Empty &&
          board[row][col] == board[row + 1][col + 1] &&
          board[row][col] == board[row + 2][col + 2] &&
          board[row][col] == board[row + 3][col + 3]) {
        return true;
      }
    }
  }

  // Check diagonal (bottom-left to top-right)
  for (int row = 3; row < ROWS; ++row) {
    for (int col = 0; col <= COLS - 4; ++col) {
      if (board[row][col] != Empty &&
          board[row][col] == board[row - 1][col + 1] &&
          board[row][col] == board[row - 2][col + 2] &&
          board[row][col] == board[row - 3][col + 3]) {
        return true;
      }
    }
  }

  return false;
}

bool Board::checkDraw() {
  // Checking if Top line has any empty left
  for (int i = 0; i < COLS; ++i) {
    if (rowCount[i] >= 0)
      return false;
  }
  return true;
}
