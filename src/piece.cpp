#include "boardpiece.hpp"
#include <algorithm>

Piece::Piece(char pcolor, int ix, int iy, char ptype) {
    color = pcolor;
    x = ix;
    y = iy;
    type = ptype;
}