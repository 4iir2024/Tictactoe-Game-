#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void play() {
        while (true) {
            displayBoard();
            makeMove();
            if (checkWin()) {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }
            if (boardFull()) {
                displayBoard();
                std::cout << "It's a draw!" << std::endl;
                break;
            }
            switchPlayer();
        }
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void displayBoard() const {
        std::cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void makeMove() {
        int row, col;
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
        } while (!isValidMove(row, col));

        board[row - 1][col - 1] = currentPlayer;
    }

    bool isValidMove(int row, int col) const {
        return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ');
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool checkWin() const {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;  // Check rows
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;  // Check columns
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;  // Check diagonal from top-left to bottom-right
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;  // Check diagonal from top-right to bottom-left
        }
        return false;
    }

    bool boardFull() const {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    TicTacToe game;
    game.play();

    return 0;
}
