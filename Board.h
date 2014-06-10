#ifndef _BOARD_H_
#define _BOARD_H_



#define GETFIELD(mask, number)	((mask << number) & FIELDMASK)



class Board
{
	public:

		typedef unsigned long long board_t;

		Board(board_t mask);

		static const unsigned int NumRows = 4;
		static const unsigned int NumCols = 4;
		static const unsigned int NumFields = NumRows * NumCols;
		static const unsigned int BitsPerField = 4;
		static const unsigned int FieldMask = ((1 << BitsPerField) - 1);

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
};



#endif // _BOARD_H_
