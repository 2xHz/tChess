#ifndef BOARDPIECE_H
#define BOARDPIECE_H

class Piece {
    private:
        char color;
        int x;
        int y;
        char type;

    public:
        char getType() {return type;}
        char getColor() {return color;}
        int getX() {return x;}
        int getY() {return y;}
        Piece(char pcolor, int ix, int iy, char ptype);

};

class Board {
    private:
        Piece *squares[8][8];

    public:
        bool isOccupied(int x, int y);
        char getType(int x, int y);
        char getColor(int x, int y);
        void capture(int x, int y);
        void occupy(int x, int y, Piece *ppiece);
        void initBoard();
        void initPieces();
        void printBoard();
        int movePiece(int x, int y, int dx, int dy);
        int makeCloser(int a, int b);
        Board();
};

#endif