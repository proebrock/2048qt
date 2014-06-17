#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_



#include <QWidget>
#include <QLineEdit>
#include <QTimer>
#include "GameButtonGrid.h"



class MainWindow : public QWidget
{
	Q_OBJECT

	public:

		explicit MainWindow(QWidget *parent = NULL);

	signals:

	public slots:

		void handleNewGameButton();
		void handleSolveButton();
		void resizeTimeout();

	protected:

		virtual void keyPressEvent(QKeyEvent *event);

		// Special functionality to avoid frequent calls to the resize
		// event; due to the fact that the automatic game button font size
		// adaption cost a lot of calculation time
		QTimer* resizeTimer;
		static const int ResizeTimeoutMilliseconds = 250;
		void resizeEvent(QResizeEvent *event);
		QResizeEvent *currentEvent;

	private:

		GameButtonGrid *grid;
		QLineEdit *scoreEdit;
		QPushButton *newGameButton;
		QPushButton *solveButton;

};



#endif // _MAINWINDOW_H_
