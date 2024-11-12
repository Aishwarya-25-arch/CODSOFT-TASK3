#include <iostream>
using namespace std;

void drawBoard(char board[3][3]) //creating a board of 3x3
{
    cout << "_____________\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n_____________\n";
    }
}

bool checkWin(char board[3][3], char player) 
{
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

void resetBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

int main() 
{
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    int row, col;
    int turn;
    int scoreX = 0, scoreO = 0; // Scores 
    char playAgain;

    cout <<"\n						WELCOME TO TIC-TOE GAME..!						\n";

    do {
        resetBoard(board);
        for (turn = 0; turn < 9; turn++) {
            drawBoard(board);
            
            while (true) {
                cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
                cin >> row >> col;

                // Check if the move is valid
                if (row < 0 || row > 2 || col < 0 || col > 2) {
                    cout << "Invalid move. Row and column must be between 0 and 2.\n";
                }
                else if (board[row][col] != ' ') {
                    cout << "Slot already occupied! Try a different slot.\n";
                }
                else {
                    break;
                }
            }

            // Make the move
            board[row][col] = player;

            if (checkWin(board, player)) {
                drawBoard(board);
                cout << "Player " << player << " wins!\n";
                
                if (player == 'X')
                    scoreX++;
                else
                    scoreO++;
                
                break; 
            }

            // Switch players
            player = (player == 'X') ? 'O' : 'X';
        }

        drawBoard(board);

        if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) {
            cout << "It's a draw!\n";
        }

        // Display scores
        cout << "\nScoreboard:\n";
        cout << "Player X: " << scoreX << " | Player O: " << scoreO << "\n";

        cout << "Do you want to play again? (y/n): \n";
        cin >> playAgain;

        player = 'X'; 

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
