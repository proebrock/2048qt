#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_



#include <QWidget>
#include <QTimer>
#include "GameButtonGrid.h"



class MainWindow : public QWidget
{
	Q_OBJECT
	
	public:
	
		explicit MainWindow(QWidget *parent = NULL);

	signals:

	public slots:

		void resizeTimeout();

	protected:

		// Special functionality to avoid frequent calls to the resize
		// event; due to the fact that the automatic game button font size
		// adaption cost a lot of calculation time
		QTimer* resizeTimer;
		static const int ResizeTimeoutMilliseconds = 250;
		void resizeEvent(QResizeEvent *event);
		QResizeEvent *currentEvent;

	private:

		GameButtonGrid *grid;

};



#endif // _MAINWINDOW_H_

