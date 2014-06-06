#include <QtGui>

#include "NumberButton.h"



NumberButton::NumberButton(QWidget *parent) : QPushButton(parent)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setEnabled(false);
}



void NumberButton::SetNumber(unsigned int power2)
{
	QStringList backgroundColors = QStringList()
		<< "#cdc0b4"	// 0 - empty
		<< "#eee4da"	// 1 - 2
		<< "#ede0c8"	// 2 - 4
		<< "#f2b179"	// 3 - 8
		<< "#f59563"	// 4 - 16
		<< "#f67c5f"	// 5 - 32
		<< "#f65e3b"	// 6 - 64
		<< "#edcf72"	// 7 - 128
		<< "#edcc61"	// 8 - 256
		<< "#edc850"	// 9 - 512
		<< "#edc53f"	// 10 - 1024
		<< "#edc22e";	// 11 - 2048 and higher
	if (power2 == 0)
	{
		setText("");
		setStyleSheet("background-color: " + backgroundColors[0]);
	}
	else
	{
		setText(QString::number(1 << power2));
		setStyleSheet("background-color: " + backgroundColors[qMin((unsigned int)11, power2)]);
	}
}



void NumberButton::resizeEvent(QResizeEvent *event)
{
	int button_margin = style()->pixelMetric(QStyle::PM_ButtonMargin);
	QFont f = font();
	f.setPixelSize((event->size().height() - button_margin * 2)/3);
	setFont(f);
}
