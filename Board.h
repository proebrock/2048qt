#ifndef _BOARD_H_
#define _BOARD_H_



#include <stdlib.h>



class Board
{
	public:

		typedef unsigned short row_t;		// 2 bytes = 16 bit
		typedef unsigned long long board_t;	// 8 bytes = 64 bit
		static const unsigned int BitsPerField = 4;
		static const unsigned int FieldMask = ((1 << BitsPerField) - 1);
		static const unsigned int BitsPerRow = 8 * sizeof(row_t);
		static const unsigned int RowMask = ((1 << BitsPerRow) - 1);
		static const unsigned int NumRows = sizeof(board_t) / sizeof(row_t);
		static const unsigned int NumCols = (8 * sizeof(row_t)) / BitsPerField;
		static const unsigned int NumFields = NumRows * NumCols;

		Board();
		Board(board_t mask);
		~Board();

		unsigned int GetField(unsigned int index) const;
		void SetField(unsigned int index, unsigned int value);
		row_t GetRow(unsigned int index) const;
		void SetRow(unsigned int index, row_t value);

		void Transpose();
		int Left();
		int Up();
		int Right();
		int Down();

		unsigned int NumEmptyFields() const;
		unsigned int GetEmptyFields(unsigned int *fieldIndices) const;
		bool AddRandom();

	private:

		volatile board_t mask;

		// Lookup tables implemented as singleton
		static row_t *lookupTableLeft;
		static row_t *lookupTableRight;
		static int *scores;

		Board::row_t MoveRow(Board::row_t value, bool moveRight, int *score);
};



#endif // _BOARD_H_
