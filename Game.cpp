#include "Game.h"

    void Game::welcomeMessage() {
      std::cout << "------------------------\n";
      std::cout << " |                      |\n";
      std::cout << " | Welcome to Connect 4 |\n";
      std::cout << " |                      |\n";
      std::cout << "------------------------\n\n\n";
        
    }
    
    void Game::getPlayerNames() {
      std::cout << "Player 1, please enter your name: ";
      std::cin >> name1;
    
      std::cout << std::endl << "Player 2, please enter your name: ";
      std::cin >> name2;
        
    }
    
    void Game::playerMessage() {
      std::cout << "--------------------------\n";
      std::cout << " |                         |\n";
      std::cout << " |        Connect 4        |\n";
      std::cout << " |                         |\n";
      std::cout << " | " << (firstPlayerTurn ? name1 : name2)
                << " It is your turn  |\n";
      std::cout << " |                         |\n";
      std::cout << "--------------------------\n\n\n";
        
    }
    
    void Game::startBoard() {
      for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
          board[i][j] = Empty; // Initialize each cell to 0
        }
      }
    
      for (int i = 0; i < COLS; ++i) {
        rowCount[i] = ROWS - 1; // Initialize rowCount to start at the bottom
      }
    
      displayBoard();
        
    }
    
    void Game::displayBoard() {
      // Clearing Screen and Printing Message everytime
      std::cout << "\033[2J\033[1;1H"; 
      playerMessage();
      std::cout << std::endl;
        
      // Output entire board:
      std::cout << "The current state of the board:" << std::endl;
      for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
          std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
    
    void Game::takeInput(std::string name) {
      std::cout << name << ", please enter a column number (1-7): ";
      int input;
      std::cin >> input;
      input--; // For Array

      // Valid Column 
      while (input < 0 || input >= COLS || rowCount[input] < 0) {
        std::cout << "Invalid input. Please enter a valid column number (1-7): ";
        std::cin >> input;
        input--; // For Array
      }
    
      if (firstPlayerTurn)
        board[rowCount[input]--][input] = Red;
      else
        board[rowCount[input]--][input] = Blue;
        
    }
    
    bool Game::checkWin() {
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
    
    bool Game::checkDraw() {
      // Checking if Top line has any empty left
      for (int i = 0; i < COLS; ++i) {
        if (rowCount[i] >= 0)
          return false;
      }
      return true;
        
    }
    
    void Game::playerTurn() {
      while (gameRunning) {
        displayBoard();
        if (firstPlayerTurn) {
          takeInput(name1);
        } else {
          takeInput(name2);
        }
    
        if (checkWin()) {
          std::cout << (firstPlayerTurn ? name1 : name2) << " wins!" << std::endl;
          gameRunning = false;
        } else if (checkDraw()) {
          std::cout << "It's a draw!" << std::endl;
          gameRunning = false;
        }
    
        firstPlayerTurn = !firstPlayerTurn;
      }
        
    }