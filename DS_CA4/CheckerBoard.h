/**
 *  A simple class that implements an 8x8 game checker board with three possible values
 *  for each cell:  0, 1 or 2.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H

class CheckerBoard {
   private:
    static const int DIMENSION = 8;
    int grid[DIMENSION][DIMENSION];

   public:
    CheckerBoard();
    void setElementAt(int x, int y, int value);
    int elementAt(int x, int y);
    bool equals(const CheckerBoard& board);
    int hashCode();
};

#endif
