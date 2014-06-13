#include <QGridLayout>



#include <QtGui>
#include "GameButtonGrid.h"



GameButtonGrid::GameButtonGrid(QWidget *parent) :
	QWidget(parent)
{
	setStyleSheet("background-color: #bbada0");

	QGridLayout *layout = new QGridLayout();
	layout->setSpacing(12);
	setLayout(layout);

	for (unsigned int r = 0, i = 0; r < Board::NumRows; r++)
	{
		for (unsigned int c = 0; c < Board::NumCols; c++)
		{
			buttons[i] = new GameButton();
			buttons[i]->setSizePolicy(QSizePolicy::Expanding,
				QSizePolicy::Expanding);
			layout->addWidget(buttons[i], r, c);
			i++;
		}
	}

	// Prepare board
	board.AddRandom();
	board.AddRandom();
	DisplayBoard();
}



void GameButtonGrid::DisplayBoard()
{
	for (unsigned int i = 0; i < Board::NumFields; i++)
		buttons[Board::NumFields - i - 1]->Set(board.GetField(i));
}



void GameButtonGrid::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
		case Qt::Key_Left:
			if (board.Left())
			{
				board.AddRandom();
				DisplayBoard();
			}
			event->accept();
			break;
		case Qt::Key_Up:
			if (board.Up())
			{
				board.AddRandom();
				DisplayBoard();
			}
			event->accept();
			break;
		case Qt::Key_Right:
			if (board.Right())
			{
				board.AddRandom();
				DisplayBoard();
			}
			event->accept();
			break;
		case Qt::Key_Down:
			if (board.Down())
			{
				board.AddRandom();
				DisplayBoard();
			}
			event->accept();
			break;
		default:
			QWidget::keyPressEvent(event);
	}
}
