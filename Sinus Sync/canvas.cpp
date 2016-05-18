#include <QPainter>
#include <math.h>

#include "canvas.h"

Canvas::Canvas(QWidget *parent)
	: QFrame(parent),
	  wMin(0, 0), wMax(1, 1)
{
	setFrameStyle(QFrame::Box);
}

Canvas::~Canvas()
{
}

QSize Canvas::minimumSizeHint() const
{
	return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
	return QSize(640, 480);
}

void Canvas::setWorld(const QPointF &min, const QPointF &max)
{
	wMin.rx() = min.x();
	wMin.ry() = min.y();

	wMax.rx() = max.x();
	wMax.ry() = max.y();
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    int schrittZaehler = 500;
    int posYAchse = width()/10;
    

	// TODO; implement the following drawing functionality!

	// first draw white background 
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0 , 0 , width()-1, height()-1);
    
	// then draw axis of abscissas 
    QPainterPath path;
//    path.moveTo(WC_to_DC(QPointF(posYAchse, height())));
//    path.lineTo(WC_to_DC(QPointF(posYAchse, 0)));
//    path.moveTo(WC_to_DC(QPointF(0, height()/2)));
//    path.lineTo(WC_to_DC(QPointF(width(), height()/2)));
//    painter.drawPath(path);
	// finally draw sine function
    

    
    double schritte = (width()-posYAchse)/schrittZaehler;
    double weg = 0;
    path.moveTo(WC_to_DC(QPointF(0, height()/2)));
    while (weg< width()) {
        path.lineTo(WC_to_DC(QPointF(weg - (posYAchse) ,sin(weg))));
        //weg = weg + 0.001;
        weg = weg + schritte;
    }
    painter.drawPath(path);

}

QPoint Canvas::WC_to_DC(const QPointF &wc)
{
	float wx0 = wMin.x(), 
		  wx1 = wMax.x(), 
		  wy0 = wMin.y(), 
		  wy1 = wMax.y();
	int dx0 = 0,
        dx1 = width()-1,
        dy0 = 0,
        dy1 = height()-1, x, y;

	// TODO; calculate window-viewport transformation for point (x, y)!

    x = (wc.x() - wx0) * ((dx1 - dx0) / (wx1 - wx0)) + dx0;
    y = (wc.y() - wy0) * ((dy1 - dy0) / (wy1 - wy0)) + dy0;

    

	return QPoint(x, y);
}

QPointF Canvas::DC_to_WC(const QPoint &dc)
{
	// TODO; calculate inverse transform (optional)
	return QPointF(0, 0);
}
