#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_



#include <QWidget>
#include "NumberButton.h"



#define NUMROWS	4
#define NUMCOLS	4



class MainWindow : public QWidget
{
	Q_OBJECT
	
	public:
	
		explicit MainWindow(QWidget *parent = NULL);

	signals:

	public slots:

	protected:

	private:

		NumberButton *buttons[NUMROWS][NUMCOLS];

};

#endif // _MAINWINDOW_H_

