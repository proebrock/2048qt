#ifndef _BOARD_H_
#define _BOARD_H_



#define GETFIELD(mask, number)	((mask << number) & FIELDMASK)



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

		Board(board_t mask);
		~Board();

		inline unsigned int operator[](unsigned int index) const
		{
			return (mask >> (BitsPerField * index)) & FieldMask;
		}

		inline void Transpose()
		{
			mask =
				((mask & 0xf0000f0000f0000f) |
				((mask & 0x0000f0000f0000f0) << 3*BitsPerField) |
				((mask & 0x00000000f0000f00) << 6*BitsPerField) |
				((mask & 0x000000000000f000) << 9*BitsPerField) |
				((mask & 0x0f0000f0000f0000) >> 3*BitsPerField) |
				((mask & 0x00f0000f00000000) >> 6*BitsPerField) |
				((mask & 0x000f000000000000) >> 9*BitsPerField));
		}

	private:

		board_t mask;

		// Lookup tables implemented as singleton
		static row_t *lookupTableLeft;
		static row_t *lookupTableRight;
};



#endif // _BOARD_H_
