#include <QGridLayout>



#include "MainWindow.h"



MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent)
{
	setWindowTitle("2048qt");
	setFixedSize(600, 600);

	setStyleSheet("background-color: #bbada0");

	QGridLayout *layout = new QGridLayout();
	layout->setSpacing(12);
	setLayout(layout);

	for (unsigned int r = 0, i = 0; r < Board::NumRows; r++)
	{
		for (unsigned int c = 0; c < Board::NumCols; c++)
		{
			buttons[i] = new GameButton();
			layout->addWidget(buttons[i], r, c);
			i++;
		}
	}
}



void MainWindow::Set(const Board &board)
{
	for (unsigned int i = 0; i < Board::NumFields; i++)
		buttons[Board::NumFields - i - 1]->Set(board[i]);
}
