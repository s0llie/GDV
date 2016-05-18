#ifndef SINUS_H
#define SINUS_H

#include <QWidget>

class QPushButton;
class QLabel;
class QLineEdit;
class Canvas;

class Sinus : public QWidget
{
	Q_OBJECT

public:
	Sinus(QWidget *parent = 0);
	~Sinus();

private slots:
	void drawBtnPressed();
    void pDrawBtnPressed();

private:
	Canvas *viewport;

	QPushButton *btnDrawSin;
    QPushButton *btnDrawP;
	QLabel *lblMinX;
	QLabel *lblMaxX;
	QLabel *lblMinY;
	QLabel *lblMaxY;
	QLineEdit *ledMinX;
	QLineEdit *ledMaxX;
	QLineEdit *ledMinY;
	QLineEdit *ledMaxY;
    
    QLabel *lblPx;
    QLabel *lblPy;
    QLineEdit *ledPx;
    QLineEdit *ledPy;
};

#endif // SINUS_H
