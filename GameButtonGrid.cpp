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

	NewGame();
}



void GameButtonGrid::NewGame()
{
	totalScore = 0;
	board.AddRandom();
	board.AddRandom();
	DisplayBoard();
}



void GameButtonGrid::keyPressEvent(QKeyEvent *event)
{
	int score = 0;
	switch (event->key())
	{
		case Qt::Key_Left:
			score = board.Left();
			event->accept();
			break;
		case Qt::Key_Up:
			score = board.Up();
			event->accept();
			break;
		case Qt::Key_Right:
			score = board.Right();
			event->accept();
			break;
		case Qt::Key_Down:
			score = board.Down();
			event->accept();
			break;
		default:
			QWidget::keyPressEvent(event);
	}
	if (score >= 0)
	{
		totalScore += score;
		board.AddRandom();
		DisplayBoard();
	}
}



void GameButtonGrid::DisplayBoard()
{
	for (unsigned int i = 0; i < Board::NumFields; i++)
		buttons[Board::NumFields - i - 1]->Set(board.GetField(i));
}
