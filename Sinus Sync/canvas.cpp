#include <QPainter>
#include <math.h>
#include "canvas.h"

Canvas::Canvas(QWidget *parent)
	: QFrame(parent),
	  wMin(0, 0), wMax(1, 1), pnt(0, 0)
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

void Canvas::setPoint(const QPointF &p){
    pnt = WC_to_DC(p);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    double schritte = 0.025f;

	// TODO; implement the following drawing functionality!

	// first draw white background 
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0 , 0 , width()-1, height()-1);
    
	// then draw axis of abscissas 
    QPainterPath path;
    path.moveTo(WC_to_DC(QPointF(0, wMax.y())));
    path.lineTo(WC_to_DC(QPointF(0, wMin.y())));
    path.moveTo(WC_to_DC(QPointF(wMin.x(), 0)));
    path.lineTo(WC_to_DC(QPointF(wMax.x(), 0)));
    painter.drawPath(path);
    
	// finally draw sine function
    double weg = wMin.x();
    path.moveTo(WC_to_DC(QPointF(weg, (sin(-weg)))));
    while (weg< width()) {
        path.lineTo(WC_to_DC(QPointF(weg, (sin(-weg)))));
        weg = weg + schritte;
    }
    painter.drawPath(path);
    
    painter.drawEllipse(pnt, 5, 5);

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