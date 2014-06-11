#include "Board.h"



Board::row_t *Board::lookupTableLeft = (Board::row_t *)0;
Board::row_t *Board::lookupTableRight = (Board::row_t *)0;



Board::Board(board_t mask)
{
	this->mask = mask;

	if (lookupTableLeft == (Board::row_t *)0)
	{
		lookupTableLeft = new row_t[RowMask+1];
		// TODO: Generate
	}
	if (lookupTableRight == (Board::row_t *)0)
	{
		lookupTableRight = new row_t[RowMask+1];
		// TODO: Generate
	}
}



Board::~Board()
{
	if (lookupTableLeft != (Board::row_t *)0)
	{
		delete [] lookupTableLeft;
	}
	if (lookupTableRight != (Board::row_t *)0)
	{
		delete [] lookupTableRight;
	}
}
