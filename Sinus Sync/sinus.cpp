#include <QPushButton> 
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPainter>

#include "sinus.h"
#include "canvas.h"


/** c'tor */
Sinus::Sinus(QWidget *parent)
	: QWidget(parent)
{
	// instantiate Canvas and button
	viewport = new Canvas();
	btnDrawSin = new QPushButton("&Draw Sinus");
    btnDrawP = new QPushButton("&Draw Point");

	// instantiate elements for setting world window
	ledMinX = new QLineEdit("0");
	lblMinX = new QLabel("World MinX");
	lblMinX->setBuddy(ledMinX);

	ledMinY = new QLineEdit("0");
	lblMinY = new QLabel("World MinY");
	lblMinY->setBuddy(ledMinY);

	ledMaxX = new QLineEdit("1");
	lblMaxX = new QLabel("World MaxX");
	lblMaxX->setBuddy(ledMaxX);

	ledMaxY = new QLineEdit("1");
	lblMaxY = new QLabel("World MaxY");
	lblMaxY->setBuddy(ledMaxY);
    
    
    //instantiate new elements
    ledPx = new QLineEdit("0");
    lblPx = new QLabel("P X");
    lblPx->setBuddy(ledPx);
    
    ledPy = new QLineEdit("0");
    lblPy = new QLabel("P Y");
    lblPy->setBuddy(ledPy);

	// create layout and add gui elements to it
	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setColumnStretch(0, 3);

	mainLayout->addWidget(viewport, 0, 0, 1, 3);
	mainLayout->addWidget(lblMinX, 2, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMinX, 2, 2);
	mainLayout->addWidget(lblMinY, 3, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMinY, 3, 2);
	mainLayout->addWidget(lblMaxX, 4, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMaxX, 4, 2);
	mainLayout->addWidget(lblMaxY, 5, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMaxY, 5, 2);
    
    //add new widgets
    mainLayout->addWidget(lblPx, 6, 0, Qt::AlignRight);
    mainLayout->addWidget(ledPx, 6, 2);
    mainLayout->addWidget(lblPy, 7, 0, Qt::AlignRight);
    mainLayout->addWidget(ledPy, 7, 2);
    
	mainLayout->addWidget(btnDrawSin, 8, 1, 1, 2, Qt::AlignRight);
    mainLayout->addWidget(btnDrawP, 9, 1, 1, 2, Qt::AlignRight);
    


	// add layout to this widget instance
	setLayout(mainLayout);
	
	// connect button click event to draw handler
	connect(btnDrawSin, SIGNAL(clicked()), this, SLOT(drawBtnPressed()));
    connect(btnDrawP, SIGNAL(clicked()), this, SLOT(pDrawBtnPressed()));
}

/** d'tor */
Sinus::~Sinus()
{
}

/** method for handling button clicked event */
void Sinus::drawBtnPressed()
{
	QPointF min, max;

	min.setX(ledMinX->text().toFloat());
	min.setY(ledMinY->text().toFloat());

	max.setX(ledMaxX->text().toFloat());
	max.setY(ledMaxY->text().toFloat());

	// update world window in canvas instance
	viewport->setWorld(min, max);

	// force redraw
	update();
}

void Sinus::pDrawBtnPressed()
{
    QPointF point;
    point.setX(ledPx->text().toFloat());
    point.setY(ledPy->text().toFloat());
    viewport->setPoint(point);
    // force redraw
    update();

}
