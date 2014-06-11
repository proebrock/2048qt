#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	MainWindow window;
	Board board(0x0123456789abcdef);
	//board.Transpose();
	window.Set(board);
	window.show();

	return app.exec();
}
