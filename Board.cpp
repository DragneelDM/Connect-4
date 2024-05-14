class Board {
private:
    const static int ROWS = 6;
    const static int COLS = 7;
    std::string board[ROWS][COLS];

public:
    Board() {
        // Initialize board
    }
    
    void display() const {
        // Display board
    }
    
    void dropPiece(int column, const std::string& color) {
        // Drop a piece in the specified column
    }
    
    bool checkWin(const std::string& color) const {
        // Check for a win condition
    }
    
    bool checkDraw() const {
        // Check for a draw condition
    }
};
