#ifndef _GAMEBUTTONGRID_H_
#define _GAMEBUTTONGRID_H_



#include <QWidget>
#include "GameButton.h"
#include "Board.h"



class GameButtonGrid : public QWidget
{
	Q_OBJECT

	public:

		explicit GameButtonGrid(QWidget *parent = NULL);

		void NewGame();
		void ApplyMove(Board::Move move);
		Board::score_t GetTotalScore() const;

	signals:

	public slots:

	protected:

	private:

		void DisplayBoard();

		Board::score_t totalScore;
		Board board;
		GameButton *buttons[Board::NumFields];
};



#endif	// _GAMEBUTTONGRID_H_
