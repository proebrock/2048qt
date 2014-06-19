#include "MainWindow.h"



#include <QGridLayout>
#include <QtGui>



MainWindow::MainWindow(QWidget *parent) :
	QWidget(parent)
{
	setWindowTitle("2048qt");
	resize(500, 500);
	setFocus();

	setStyleSheet("background-color: #bbada0");

	QHBoxLayout *layout = new QHBoxLayout();
	scoreEdit = new QLineEdit("0");
	scoreEdit->setReadOnly(true);
	scoreEdit->setFocusPolicy(Qt::NoFocus);
	scoreEdit->setContextMenuPolicy(Qt::PreventContextMenu);
	layout->addWidget(scoreEdit);
	newGameButton = new QPushButton("New");
	newGameButton->setFocusPolicy(Qt::NoFocus);
	connect(newGameButton, SIGNAL(released()), this, SLOT(handleNewGameButton()));
	layout->addWidget(newGameButton);
	solveButton = new QPushButton("Solve");
	solveButton->setFocusPolicy(Qt::NoFocus);
	connect(solveButton, SIGNAL(released()), this, SLOT(handleSolveButton()));
	layout->addWidget(solveButton);

	QVBoxLayout *layoutMain = new QVBoxLayout();
	grid = new GameButtonGrid(this);
	grid->setSizePolicy(QSizePolicy::Expanding,
		QSizePolicy::Expanding);
	layoutMain->addLayout(layout);
	layoutMain->addWidget(grid);
	setLayout(layoutMain);

	resizeTimer = new QTimer(this);
	connect(resizeTimer, SIGNAL(timeout()), this, SLOT(resizeTimeout()));
}



void MainWindow::handleNewGameButton()
{
	grid->NewGame();
	scoreEdit->setText(QString::number(grid->GetTotalScore()));
}



void MainWindow::handleSolveButton()
{
}



void MainWindow::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
		case Qt::Key_Left:
			grid->ApplyMove(Board::Move::Left);
			break;
		case Qt::Key_Up:
			grid->ApplyMove(Board::Move::Up);
			break;
		case Qt::Key_Right:
			grid->ApplyMove(Board::Move::Right);
			break;
		case Qt::Key_Down:
			grid->ApplyMove(Board::Move::Down);
			break;
		default:
			QWidget::keyPressEvent(event);
			return;
	}
	scoreEdit->setText(QString::number(grid->GetTotalScore()));
	event->accept();
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
	// Possible problem here: is currentEvent still valid
    QWidget::resizeEvent(currentEvent);
}
