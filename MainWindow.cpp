#include <QGridLayout>



#include "MainWindow.h"



MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent)
{
	setWindowTitle("2048qt");
	resize(500, 500);
	
	setStyleSheet("background-color: #bbada0");

	QVBoxLayout *layout = new QVBoxLayout();
	grid = new GameButtonGrid(this);
	grid->setSizePolicy(QSizePolicy::Expanding,
		QSizePolicy::Expanding);
	grid->setFocus();
	layout->addWidget(grid);
	setLayout(layout);

	resizeTimer = new QTimer(this);
	connect(resizeTimer, SIGNAL(timeout()), this, SLOT(resizeTimeout()));
}



void MainWindow::resizeEvent(QResizeEvent *event)
{
	// Resize resets a timer every time it is called
    resizeTimer->stop();
    currentEvent = event;
    resizeTimer->start(ResizeTimeoutMilliseconds);
}



void MainWindow::resizeTimeout()
{
	// If the timer is actually triggered, call the original event handler
    resizeTimer->stop();
    QWidget::resizeEvent(currentEvent); // Possible problem: is currentEvent still valid
}
