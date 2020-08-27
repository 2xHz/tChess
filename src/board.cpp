#include <iostream>
#include <algorithm>
#include "boardpiece.hpp"

using namespace std;

Board::Board() {
    initBoard();
    initPieces();
}

bool Board::isOccupied(int x, int y) {
    return squares[x][y] != nullptr;
}

char Board::getType(int x, int y) {
    char type = squares[x][y]->getType();
    return type;
}

char Board::getColor(int x, int y) {
    char color = squares[x][y]->getColor();
    return color;
}

void Board::capture(int x, int y) {
    delete squares[x][y];
    squares[x][y] = nullptr;  
}

void Board::occupy(int x, int y, Piece *ppiece) {
    squares[x][y] = ppiece;
}

void Board::initBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; j++) {
            squares[i][j] = nullptr;
        }
    }
}

void Board::initPieces() {
    // White pieces
    Piece * wra = new Piece('W', 0, 0, 'R');
    occupy(wra->getX(), wra->getY(), wra);
//
    //Piece * wnb = new Piece('W', 1, 0, 'N');
    //occupy(wnb->getX(), wnb->getY(), wnb);
//
    //Piece * wbc = new Piece('W', 2, 0, 'B');
    //occupy(wbc->getX(), wbc->getY(), wbc);
//
    //Piece * wq = new Piece('W', 3, 0, 'Q');
    //occupy(wq->getX(), wq->getY(), wq);
//
    //Piece * wk = new Piece('W', 4, 0, 'K'); 
    //occupy(wk->getX(), wk->getY(), wk);
//
    //Piece * wbf = new Piece('W', 5, 0, 'B');
    //occupy(wbf->getX(), wbf->getY(), wbf);
//
    //Piece * wng = new Piece('W', 6, 0, 'N');
    //occupy(wng->getX(), wng->getY(), wng);
//
    //Piece * wrh = new Piece('W', 7, 0, 'R');
    //occupy(wrh->getX(), wrh->getY(), wrh);
//
    //// White pawns
    Piece * wpa = new Piece('W', 0, 1, 'P');
    occupy(wpa->getX(), wpa->getY(), wpa);
//
    //Piece * wpb = new Piece('W', 1, 1, 'P');
    //occupy(wpb->getX(), wpb->getY(), wpb);
//
    //Piece * wpc = new Piece('W', 2, 1, 'P');
    //occupy(wpc->getX(), wpc->getY(), wpc);
    //
    //Piece * wpd = new Piece('W', 3, 1, 'P');
    //occupy(wpd->getX(), wpd->getY(), wpd);
    //
    //Piece * wpe = new Piece('W', 4, 1, 'P');
    //occupy(wpe->getX(), wpe->getY(), wpe);
//
    //Piece * wpf = new Piece('W', 5, 1, 'P');
    //occupy(wpf->getX(), wpf->getY(), wpf);
//
    //Piece * wpg = new Piece('W', 6, 1, 'P');
    //occupy(wpg->getX(), wpg->getY(), wpg);
//
    //Piece * wph = new Piece('W', 7, 1, 'P');
    //occupy(wph->getX(), wph->getY(), wph);
//
//
//
    //// Black pieces
    Piece * bra = new Piece('B', 0, 7, 'r');
    occupy(bra->getX(), bra->getY(), bra);
//
    //Piece * bnb = new Piece('B', 1, 7, 'n');
    //occupy(bnb->getX(), bnb->getY(), bnb);
//
    //Piece * bbc = new Piece('B', 2, 7, 'b');
    //occupy(bbc->getX(), bbc->getY(), bbc);
//
    //Piece * bq = new Piece('B', 3, 7, 'q');
    //occupy(bq->getX(), bq->getY(), bq);
//
    //Piece * bk = new Piece('B', 4, 7, 'k');
    //occupy(bk->getX(), bk->getY(), bk);
//
    //Piece * bbf = new Piece('B', 5, 7, 'b');
    //occupy(bbf->getX(), bbf->getY(), bbf);
//
    //Piece * bng = new Piece('B', 6, 7, 'n');
    //occupy(bng->getX(), bng->getY(), bng);
//
    //Piece * brh = new Piece('B', 7, 7, 'r');
    //occupy(brh->getX(), brh->getY(), brh);
//
//
    //// Black pawns
    //Piece * bpa = new Piece('B', 0, 6, 'p');
    //occupy(bpa->getX(), bpa->getY(), bpa);
    //
    //Piece * bpb = new Piece('B', 1, 6, 'p');
    //occupy(bpb->getX(), bpb->getY(), bpb);
    //
    //Piece * bpc = new Piece('B', 2, 6, 'p');
    //occupy(bpc->getX(), bpc->getY(), bpc);
    //
    //Piece * bpd = new Piece('B', 3, 6, 'p');
    //occupy(bpd->getX(), bpd->getY(), bpd);
    //
    //Piece * bpe = new Piece('B', 4, 6, 'p');
    //occupy(bpe->getX(), bpe->getY(), bpe);
    //
    //Piece * bpf = new Piece('B', 5, 6, 'p');
    //occupy(bpf->getX(), bpf->getY(), bpf);
    //
    //Piece * bpg = new Piece('B', 6, 6, 'p');
    //occupy(bpg->getX(), bpg->getY(), bpg);
    //
    //Piece * bph = new Piece('B', 7, 6, 'p');
    //occupy(bph->getX(), bph->getY(), bph);
    //
}

void Board::printBoard() {
    for (int i = 7; i >= 0; --i) {
        for (int j = 0; j < 8; ++j) {
            if (isOccupied(j, i)) {
                cout << squares[j][i]->getType();
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }
}

int Board::movePiece(int x, int y, int dx, int dy) {
    if (isOccupied(x, y)) {
        char ptype = squares[x][y]->getType();
        char pcolor = squares[x][y]->getColor();

        // White pieces
        if (ptype == 'R' || ptype == 'r') {

            // Vertical movement
            if (dx == x) {
                // Moving up
                if (y < dy) {
                    for (int i = (y + 1); i != dy; i++) {
                        if (isOccupied(x, i)) {
                            return 1;
                        }

                        else {
                            continue;
                        }
                    }
                }

                // Moving down
                else {
                    for (int i = (y + 1); i != dy; i--) {
                        if (isOccupied(x, i)) {
                            return 1;
                        }

                        else {
                            continue;
                        }
                    }
                }

                // TODO: check if move puts either king in check...

                // If opposite color piece is there capture it
                if (isOccupied(dx, dy)) {
                    if (getColor(dx, dy) != pcolor) {
                        capture(dx, dy);
                    }
                    else {
                        return 1;
                    }
                }

                // Actually move the piece
                squares[dx][dy] = squares[x][y];
                squares[x][y] = nullptr;
                return 0;
            }

            // Horizontal move
            else if (dy == y) {
                // Moving right
                if (x < dx) {
                    // Check if another piece is in the way
                    for (int i = x + 1; i != dx; i++) {
                        if (isOccupied(i, y)) {
                            return 1;
                        }

                        else {
                            continue;
                        }
                    }
                }
                
                // Moving left
                else {
                    // Check if another piece is in the way
                    for (int i = x - 1; i != dx; i--) {
                        if (isOccupied(i, y)) {
                            return 1;
                        }

                        else {
                            continue;
                        }
                    }
                }

                // TODO: check if move puts either king in check...

                // If opposite color piece is there capture it
                if (isOccupied(dx, dy)) {
                    if (getColor(dx, dy) != pcolor) {
                        capture(dx, dy);
                    }
                    else {
                        return 1;
                    }
                }

                // Actually move the piece
                squares[dx][dy] = squares[x][y];
                squares[x][y] = nullptr;
                return 0;
            }

            else {
                return 1;
            }
        }

        else if (ptype == 'P') {
            if (dx == x || (((x - dx == 1) || (x - dx == -1)) && ((y - dy == 1) || (y - dy == -1)))) {
                if (x == dx) {
                    if (y == 1 && dy == 3) {
                        for (int i = (y + 1); i != dy; i++) {
                            if (isOccupied(x, i)) {
                                return 1;
                            }

                            else {
                                continue;
                            }
                        }

                        if (isOccupied(dx, dy)) {
                            return 1;
                        }
                        squares[dx][dy] = squares[x][y];
                        squares[x][y] = nullptr;
                        return 0;
                    }

                    else if (dy - y == 1) {
                        if (isOccupied(dx, dy)) {
                            return 1;
                        }
                        squares[dx][dy] = squares[x][y];
                        squares[x][y] = nullptr;
                        return 0;

                    }

                    else {return 1;}
                }

                else if (dx - x == 1 || dx - x == -1) {
                    if (dy - y == 1) {
                        if (isOccupied(dx, dy) && getColor(dx, dy) != pcolor) {
                            capture(dx, dy);
                            
                            squares[dx][dy] = squares[x][y];
                            squares[x][y] = nullptr;
                            return 0;
                        }
                        else {return 1;}
                    }

                    else {return 1;}
                }

                else {return 1;}
            }
        }
    }

    else {return 1;}
}
