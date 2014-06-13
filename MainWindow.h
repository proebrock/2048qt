#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_



#include <QWidget>
#include "GameButtonGrid.h"



class MainWindow : public QWidget
{
	Q_OBJECT
	
	public:
	
		explicit MainWindow(QWidget *parent = NULL);

	signals:

	public slots:

	protected:

	private:

		GameButtonGrid *grid;

};



#endif // _MAINWINDOW_H_

