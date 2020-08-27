#include "boardpiece.hpp"
#include <iostream>

using namespace std;

int gameControl(Board &board);
int movePiece(Board &board, char &turn);

int main() {
    Board Chess;
    gameControl(Chess);
    return 0;
}

int gameControl(Board &board) {
    char turn = 'W';
    int returnVal;
    while (true) {
        board.printBoard();
        returnVal = movePiece(board, turn);
        switch (returnVal)
        {
        case 1:
            cout << "Invalid move. " << endl;
            continue;
        
        default:
            if (turn == 'W') {
            turn = 'B';
            }
    
            else {
                turn = 'W';
            }
            continue;
        }
        
        
    }
}

int movePiece(Board &board, char &turn) {
    char move[4];
    int sx, sy, dx, dy;
    if (turn == 'W') {
        cout << "White to move: ";
    }
    else {
        cout << "Black to move: ";
    }

    cin >> move;

    if (move[0] < 106 && move[0] > 96) {
        sx = (move[0] - 97);
    }
    else {return 1;}
    if (move[1] < 58 && move[1] > 47) {
        sy = (move[1] - '0') - 1;
    }
    else {return 1;}
    if (move[2] < 106 && move[2] > 96) {
        dx = (move[2] - 97);
    }
    else {return 1;}
    if (move[3] < 58 && move[3] > 47) {
        dy = (move[3] - '0') - 1;
    }
    else {return 1;}

    if (dx == sx && dy == sy) {
        return 1;
    }

    if (board.getColor(sx, sy) != turn) {
        return 1;
    }

    int returnVal = board.movePiece(sx, sy, dx, dy);
    return returnVal;
}