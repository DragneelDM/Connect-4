#include "Game.h"

Game::Game(const std::string &name1, const std::string &name2)
    : board(), player1(name1), player2(name2), firstPlayerTurn(true),
      gameRunning(true) {}

void Game::welcomeMessage() {
  std::cout << "------------------------\n";
  std::cout << " |           |\n";
  std::cout << " | Welcome to Connect 4 |\n";
  std::cout << " |           |\n";
  std::cout << "------------------------\n\n\n";
}

void Game::playerTurn() {
  while (gameRunning) {
    board.initializeBoard(); // Reset board for each turn
    board.displayBoard();
    Player currentPlayer = firstPlayerTurn ? player1 : player2;
    std::string name = currentPlayer.getName();

    if (!board.takeInput(name, -1,
                         firstPlayerTurn)) { // Ignoring user input for column
                                             // (handled in Board)
      continue;
    }

    if (board.checkWin()) {
      std::cout << name << " wins!" << std::endl;
      gameRunning = false;
    } else if (board.checkDraw()) {
      std::cout << "It's a draw!" << std::endl;
      gameRunning = false;
    }

    firstPlayerTurn = !firstPlayerTurn;
  }
}
