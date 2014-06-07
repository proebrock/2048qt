#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	MainWindow window;
	window.Set(Board(0x0123456789abcdef));
	window.show();

	return app.exec();
}
