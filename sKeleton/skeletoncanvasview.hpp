/*
  This file is part of "bounce" by Gunnstein Lye <gl@ez.no>
  Copyright (C) 2000 eZ systems as, Norway
  (http://www.ez.no)
  bounce is part of a QCanvas tutorial on www.zez.org.
  
  skeleton is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.
  
  You should have received a copy of the GNU General Public License
  along with skeleton; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
  Boston, MA 02111-1307, USA.
*/

#ifndef BONCECANVASVIEW_HPP
#define BONCECANVASVIEW_HPP

#include <qcanvas.h>
#include <qpoint.h>
#include <qqueue.h>

class QWidget;
class QMouseEvent;
class QTimer;


class SkeletonCanvasView : public QCanvasView
{
    Q_OBJECT
public:
    SkeletonCanvasView( QCanvas *canvas, QWidget *parent, const char *name );
    ~SkeletonCanvasView();

protected:
    void contentsMousePressEvent( QMouseEvent* );
    void contentsMouseMoveEvent( QMouseEvent* );
    void contentsMouseReleaseEvent( QMouseEvent* );

protected slots:
    void timeout();

private:
    QCanvasItem *Moving;
    QPoint MovingStart;
    QTimer *Timer;
    QQueue<QPoint> MousePosQueue;

};

#endif  // BONCECANVASVIEW_HPP
