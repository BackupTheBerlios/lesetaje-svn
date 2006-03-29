/*
  This file is part of "skeleton" by Gunnstein Lye <gl@ez.no>
  Copyright (C) 2000 eZ systems as, Norway
  (http://www.ez.no)
  skeleton is part of a QCanvas tutorial on www.zez.org.
  
  skeleton is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.
  
  You should have received a copy of the GNU General Public License
  along with skeleton; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
  Boston, MA 02111-1307, USA.
*/

#ifndef SKELETONWIDGET_HPP
#define SKELETONWIDGET_HPP

#include <qwidget.h>

class QCanvas;
class QPushButton;
class SkeletonCanvasView;
class Tag;



class SkeletonWidget : public QWidget
{
Q_OBJECT
public:
    SkeletonWidget( QWidget *parent, const char *name );
    ~SkeletonWidget();
    public slots:
    	void Pruefen();

private:
    QCanvas *Canvas;
    SkeletonCanvasView *CanvasView;
    QPushButton *QuitButton;
    QPushButton *PruefButton;
    
   

      Tag *sphere20;
      Tag *sphere21;
};

#endif  // BOUNCEWIDGET_HPP
