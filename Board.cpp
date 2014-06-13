#include "Board.h"

#include <stdio.h>

Board::row_t *Board::lookupTableLeft = (Board::row_t *)0;
Board::row_t *Board::lookupTableRight = (Board::row_t *)0;



Board::Board(board_t mask)
{
	this->mask = mask;

	if (lookupTableLeft == (Board::row_t *)0)
	{
		lookupTableLeft = new row_t[1 << BitsPerRow];
	}
	if (lookupTableRight == (Board::row_t *)0)
	{
		lookupTableRight = new row_t[1 << BitsPerRow];
		for (unsigned int i = 0; i < 1 << BitsPerRow; i++)
		{
			lookupTableLeft[i] = MoveRight((Board::row_t)i);
			printf("%04x -> %04x\n", i, lookupTableLeft[i]);
		}
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



Board::row_t Board::MoveRight(Board::row_t value)
{
	// Move values from bit field into array for easier access
	unsigned int input[NumCols];
	unsigned int in = 0;
	for (unsigned int i = 0; i < NumCols; i++)
		input[i] = (value >> (BitsPerField * i)) & FieldMask;
	// Prepare output array
	unsigned int output[NumCols];
	unsigned int out = 0;
	bool combinePossible = false;
	for (unsigned int i = 0; i < NumCols; i++)
		output[i] = 0;
	while (true)
	{
		// Find non-zero element
		while (true)
		{
			if (in >= NumCols)
				goto done;
			if (input[in] > 0)
				break;
			in++;
		}
		if (combinePossible && (output[out-1] == input[in]))
		{
			output[out-1]++;
			combinePossible = false;
			in++;
		}
		else
		{
			output[out++] = input[in++];
			combinePossible = true;
		}
		if (out >= NumCols)
			goto done;
	}

done:
	// Move back result from array into bit field
	Board::row_t result = 0;
	for (unsigned int i = 0; i < NumCols; i++)
		result |= (Board::row_t)(output[i] << (BitsPerField * i));
	return result;
}
