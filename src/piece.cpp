#include "boardpiece.h"
#include <algorithm>

Piece::Piece(char pcolor, int ix, int iy, char ptype) {
    isCaptured = false;
    color = pcolor;
    x = ix;
    y = iy;
    type = ptype;
}
