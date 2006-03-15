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

#include "skeletoncanvasview.hpp"
#include "tag.hpp"
#include <qwidget.h>
#include <qevent.h>
#include <qtimer.h>


SkeletonCanvasView::SkeletonCanvasView( QCanvas *canvas, QWidget *parent, const char *name )
    : QCanvasView( canvas, parent, name )
{
    // create and setup a timer
    Timer = new QTimer( this, "Timer" );
   
    setVScrollBarMode(QScrollView::AlwaysOff);
    setHScrollBarMode(QScrollView::AlwaysOff);
//    setStaticBackground(1==1);
    
    connect( Timer, SIGNAL( timeout() ), this, SLOT( timeout() ) );

    MousePosQueue.setAutoDelete( true );  // delete removed items
    Moving = 0;   // we are not holding the tag
}


SkeletonCanvasView::~SkeletonCanvasView()
{
}


void SkeletonCanvasView::contentsMousePressEvent( QMouseEvent *e )
{
    // a list of all items underneath the mouse when it was pressed
    QCanvasItemList list = canvas()->collisions(e->pos());

    // the RTTI of a QCanvasSprite is 1...
    if ( !list.isEmpty() && list.first()->rtti() == 1 )
    {
        // ...which means we can safely cast to a Tag pointer.
        Tag *sphere = (Tag*)list.first();

        // hit() will return false it we hit the transparent corners
        // of the planet image.
        if ( sphere->hit( e->pos() ) )
        {
            Moving = sphere;
            canvas()->setAdvancePeriod( -1 );  // stops the animation when dragging
            MovingStart = e->pos();
            Moving->setZ( 2 );  // raises the current item above other items when dragging.
            // (This in not really necessary here, since we have just one item.)

            Timer->start( 10, false );  // start the timer
        }
    }
}


void SkeletonCanvasView::contentsMouseMoveEvent( QMouseEvent *e )
{
    if ( Moving )    // if we are holding the tag...
    {
        // ...then move it
        Moving->moveBy( e->pos().x() - MovingStart.x(),
                        e->pos().y() - MovingStart.y() );
        MovingStart = e->pos();
        canvas()->update();   // update visual change to canvas
    }
}


void SkeletonCanvasView::contentsMouseReleaseEvent( QMouseEvent* )
{
    if ( Moving )    // if we are holding the tag
    {
        Timer->stop();    // stop the timer

        if ( MousePosQueue.count() )  // if we have recorded mouse positions...
        {
            // ...then calculate average velocity
            int count = MousePosQueue.count();
            QPoint velocity( 0, 0 );
            QPoint pos;
            QPoint prevPos = *MousePosQueue.head();

            while ( MousePosQueue.count() )
            {
                pos = *MousePosQueue.dequeue();
                velocity += pos - prevPos;
                prevPos = pos;
            }

            // set the tags new velocity
            Moving->setXVelocity( velocity.x() / count );
            Moving->setYVelocity( velocity.y() / count );
        }
        else  // if we haven't recorded anything (fast click)
        {
            // set zero velocity (we drop the tag)
            Moving->setXVelocity( 0 );
            Moving->setYVelocity( 0 );
        }

        Moving->setZ( 1 );
        canvas()->setAdvancePeriod( 10 );  // restart the animation
        Moving = 0;     // clear the pointer, we are no longer holding the tag
    }
}


void SkeletonCanvasView::timeout()
{
    MousePosQueue.enqueue( new QPoint( MovingStart ) );   // record position

    if ( MousePosQueue.count() > 10 )      // if larger than 10 items
        MousePosQueue.remove();            // remove one item
}

