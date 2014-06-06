#ifndef _NUMBERBUTTON_H_
#define _NUMBERBUTTON_H_



#include <QPushButton>



class NumberButton : public QPushButton
{
	Q_OBJECT

	public:
	
		explicit NumberButton(QWidget *parent = NULL);
		void SetNumber(unsigned int power2);

	signals:

	public slots:
	
	protected:
	
		void resizeEvent(QResizeEvent *event);

	private:

};


#endif // _NUMBERBUTTON_H_
