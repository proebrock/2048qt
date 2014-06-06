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

	for (unsigned int r = 0; r < NUMROWS; r++)
	{
		for (unsigned int c = 0; c < NUMCOLS; c++)
		{
			buttons[r][c] = new NumberButton();
			buttons[r][c]->SetNumber(4*r+c);
			layout->addWidget(buttons[r][c], r, c);
		}
	}
}
