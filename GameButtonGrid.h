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
		void DisplayBoard();

	signals:

	public slots:

	protected:
	
		virtual void keyPressEvent(QKeyEvent *event);

	private:

		Board board;
		GameButton *buttons[Board::NumFields];

};



#endif	// _GAMEBUTTONGRID_H_
