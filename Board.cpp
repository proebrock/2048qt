#include "Board.h"



Board::row_t *Board::lookupTableLeft = (Board::row_t *)0;
Board::row_t *Board::lookupTableRight = (Board::row_t *)0;
int *Board::scores = (int *)0;



Board::Board() : Board(0)
{
}



Board::Board(board_t mask)
{
	unsigned int n = 1 << BitsPerRow;
	this->mask = mask;

	if (lookupTableLeft == (Board::row_t *)0)
	{
		lookupTableLeft = new row_t[n];
		scores = new int[n];
		for (unsigned int i = 0; i < n; i++)
			lookupTableLeft[i] = MoveRow((Board::row_t)i, false, &(scores[i]));
		lookupTableRight = new row_t[n];
		for (unsigned int i = 0; i < n; i++)
			lookupTableRight[i] = MoveRow((Board::row_t)i, true, (int *)0);
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



void Board::Clear()
{
	mask = 0;
}



unsigned int Board::GetField(unsigned int index) const
{
	return (mask >> (BitsPerField * index)) & FieldMask;
}



void Board::SetField(unsigned int index, unsigned int value)
{
	mask &= ~((board_t)(FieldMask) << (BitsPerField * index));
	mask |= ((board_t)(value & FieldMask) << (BitsPerField * index));
}



Board::row_t Board::GetRow(unsigned int index) const
{
	return ((row_t *)&mask)[NumRows - index - 1];
}



void Board::SetRow(unsigned int index, Board::row_t value)
{
	((row_t *)&mask)[NumRows - index - 1] = value;
}



void Board::Transpose()
{
	mask =
		((mask & 0xf0000f0000f0000f) |
		((mask & 0x0000f0000f0000f0) << (3 * BitsPerField)) |
		((mask & 0x00000000f0000f00) << (6 * BitsPerField)) |
		((mask & 0x000000000000f000) << (9 * BitsPerField)) |
		((mask & 0x0f0000f0000f0000) >> (3 * BitsPerField)) |
		((mask & 0x00f0000f00000000) >> (6 * BitsPerField)) |
		((mask & 0x000f000000000000) >> (9 * BitsPerField)));
}



int Board::Apply(Move move)
{
	board_t oldmask = mask;
	int totalScore = 0;
	switch (move)
	{
		case Left:
			for (unsigned int i = 0; i < NumRows; i++)
			{
				row_t row = GetRow(i);
				SetRow(i, lookupTableLeft[row]);
				totalScore += scores[row];
			}
			break;
		case Up:
			Transpose();
			for (unsigned int i = 0; i < NumRows; i++)
			{
				row_t row = GetRow(i);
				SetRow(i, lookupTableLeft[row]);
				totalScore += scores[row];
			}
			Transpose();
			break;
		case Right:
			for (unsigned int i = 0; i < NumRows; i++)
			{
				row_t row = GetRow(i);
				SetRow(i, lookupTableRight[row]);
				totalScore += scores[row];
			}
			break;
		case Down:
			Transpose();
			for (unsigned int i = 0; i < NumRows; i++)
			{
				row_t row = GetRow(i);
				SetRow(i, lookupTableRight[row]);
				totalScore += scores[row];
			}
			Transpose();
			break;
		default:
			return -1;
	}
	if (oldmask == mask)
		return -1;
	else
		return totalScore;
}



unsigned int Board::NumEmptyFields() const
{
	unsigned int result = 0;
	for (unsigned int i = 0; i < NumFields; i++)
		if (GetField(i) == 0)
			result++;
	return result;
}



unsigned int Board::GetEmptyFields(unsigned int *fieldIndices) const
{
	unsigned int result = 0;
	for (unsigned int i = 0; i < NumFields; i++)
		if (GetField(i) == 0)
			fieldIndices[result++] = i;
	return result;
}



bool Board::AddRandom()
{
	unsigned int fieldIndices[NumFields];
	unsigned int numEmpty = GetEmptyFields(fieldIndices);
	if (numEmpty == 0)
		return false;
	SetField(fieldIndices[rand() % numEmpty], rand() % 100 >= 90 ? 2 : 1);
	return true;
}



Board::row_t Board::MoveRow(Board::row_t value, bool moveRight, int *score)
{
	// Initialize score
	if (score != (int *)0)
		*score = 0;
	// Move values from bit field into array for easier access
	unsigned int input[NumCols];
	unsigned int in = 0;
	if (moveRight)
		for (unsigned int i = 0; i < NumCols; i++)
			input[i] = (value >> (BitsPerField * i)) & FieldMask;
	else
		for (unsigned int i = 0; i < NumCols; i++)
			input[NumCols - i - 1] = (value >> (BitsPerField * i)) & FieldMask;
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
		// Combine or append
		if (combinePossible &&
			(output[out-1] == input[in]) &&
			(input[in] < FieldMask))
		{
			// Combine with the previous one in output
			output[out-1]++;
			combinePossible = false;
			in++;
			// Update score
			if (score != (int *)0)
				*score += 1 << output[out-1];
		}
		else
		{
			// Append to output
			output[out++] = input[in++];
			combinePossible = true;
		}
	}

done:
	// Move back result from array into bit field
	Board::row_t result = 0;
	if (moveRight)
		for (unsigned int i = 0; i < NumCols; i++)
			result |= (Board::row_t)(output[i] << (BitsPerField * i));
	else
		for (unsigned int i = 0; i < NumCols; i++)
			result |= (Board::row_t)(output[NumCols - i - 1] << (BitsPerField * i));
	return result;
}
