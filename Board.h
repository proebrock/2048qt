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

	private:

		 board_t mask;
};



#endif // _BOARD_H_
