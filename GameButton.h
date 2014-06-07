#ifndef _GAMEBUTTON_H_
#define _GAMEBUTTON_H_



#include <QPushButton>



class GameButton : public QPushButton
{
	Q_OBJECT

	public:
	
		explicit GameButton(QWidget *parent = NULL);
		void Set(unsigned int power2);

	signals:

	public slots:
	
	protected:
	
		void resizeEvent(QResizeEvent *event);

	private:

};



#endif // _GAMEBUTTON_H_
