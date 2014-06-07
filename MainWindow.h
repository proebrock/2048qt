#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_



#include <QWidget>
#include "GameButton.h"
#include "Board.h"



class MainWindow : public QWidget
{
	Q_OBJECT
	
	public:
	
		explicit MainWindow(QWidget *parent = NULL);
		void Set(const Board &board);

	signals:

	public slots:

	protected:

	private:

		GameButton *buttons[Board::NumFields];

};



#endif // _MAINWINDOW_H_

