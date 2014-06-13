#include <QGridLayout>



#include "MainWindow.h"



MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent)
{
	setWindowTitle("2048qt");
	setFixedSize(600, 600);
	
	setStyleSheet("background-color: #bbada0");

	QVBoxLayout *layout = new QVBoxLayout();
	grid = new GameButtonGrid(this);
	grid->setSizePolicy(QSizePolicy::Expanding,
		QSizePolicy::Expanding);
	grid->setFocus();
	layout->addWidget(grid);
	setLayout(layout);
}
