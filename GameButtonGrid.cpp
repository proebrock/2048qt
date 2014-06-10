#include <QGridLayout>



#include <QDebug>
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
}



void GameButtonGrid::Set(const Board &board)
{
	for (unsigned int i = 0; i < Board::NumFields; i++)
		buttons[Board::NumFields - i - 1]->Set(board[i]);
}



void GameButtonGrid::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
		case Qt::Key_Left:
			qDebug() << "Key_Left";
			event->accept();
			break;
		case Qt::Key_Up:
			qDebug() << "Key_Up";
			event->accept();
			break;
		case Qt::Key_Right:
			qDebug() << "Key_Right";
			event->accept();
			break;
		case Qt::Key_Down:
			qDebug() << "Key_Down";
			event->accept();
			break;
		default:
			QWidget::keyPressEvent(event);
	}
}
