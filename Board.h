#ifndef _BOARD_H_
#define _BOARD_H_



#include <stdlib.h>



class Board
{
	public:

		typedef unsigned char index_t;
		typedef unsigned char field_t;
		typedef unsigned short row_t;		// 2 bytes = 16 bit
		typedef unsigned long long board_t;	// 8 bytes = 64 bit
		typedef int score_t;
		static const unsigned int BitsPerField = 4;
		static const unsigned int BitsPerRow = 8 * sizeof(row_t);
		static const unsigned int FieldMask = ((1 << BitsPerField) - 1);
		static const unsigned int RowMask = ((1 << BitsPerRow) - 1);
		static const unsigned int NumRows = sizeof(board_t) / sizeof(row_t);
		static const unsigned int NumCols = (8 * sizeof(row_t)) / BitsPerField;
		static const unsigned int NumFields = NumRows * NumCols;

		Board();
		Board(board_t mask);
		~Board();

		void Clear();

		field_t GetField(index_t index) const;
		void SetField(index_t index, field_t value);
		row_t GetRow(index_t index) const;
		void SetRow(index_t index, row_t value);

		void Transpose();
		enum Move
		{
			Left = 0,
			Up,
			Right,
			Down,
			NumMoves
		};
		score_t Apply(Move move);

		index_t NumEmptyFields() const;
		index_t GetEmptyFields(index_t *fieldIndices) const;
		void AddRandom();

	private:

		volatile board_t mask;

		// Lookup tables implemented as singleton
		static row_t *lookupTableLeft;
		static row_t *lookupTableRight;
		static score_t *scores;

		row_t MoveRow(row_t value, bool moveRight, score_t *score);
};



#endif // _BOARD_H_
