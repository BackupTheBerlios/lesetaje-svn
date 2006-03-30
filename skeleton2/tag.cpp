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

#include "tag.hpp"

#include <qcanvas.h>
#include <qstring.h>
#include <qimage.h>


Tag::Tag( QCanvasPixmapArray *parray, QCanvas *canvas )
    : QCanvasSprite( parray, canvas )
{
    // set the offset to be the center of the image.
    image()->setOffset( width()/2, height()/2 );
    setZ( 1 );
    setAnimated( true );     // allow animation
    MoveX = MoveY = true;

    // Physical data, adjust these for interesting effects...
    Air_resistance = 0;      // air resistance
    Bump_resistance = 0;     // resistance when hitting a wall
    Mass = 0;                     // mass of tag (weight)
}


Tag::~Tag()
{
}


bool Tag::hit( const QPoint &p ) const
{
    // this returns false it a transparent pixel on the image is hit, otherwise true.
    int ix = p.x() - int( x() - width()/2 );
    int iy = p.y() - int( y() - height()/2 );
    if ( !image()->convertToImage().valid( ix, iy ) )
        return false;
    QRgb pixel = image()->convertToImage().pixel( ix, iy );
    return qAlpha( pixel ) != 0;
}


void Tag::advance( int phase )
{
/*
    if ( phase == 0 ) // stuff to be done before we move
    {
        // apply resistance to slow down the tag
        setXVelocity( xVelocity() * Air_resistance );
        setYVelocity( yVelocity() * Air_resistance );

        // apply gravity
        setYVelocity( yVelocity() + Mass );

        // right border hit check
        if ( !canvas()->onCanvas( x() + width()/2 + xVelocity(), 1 ) )
        {
            MoveX = false;
            move( canvas()->width() - width()/2, y() );
            setXVelocity( xVelocity() * -1 * Bump_resistance );
        }
        // left border hit check
        else if ( !canvas()->onCanvas( x() - width()/2 + xVelocity(), 1 ) )
        {
            MoveX = false;
            move( 0 + width()/2, y() );
            setXVelocity( xVelocity() * -1 * Bump_resistance );
        }

        // lower border hit check
        if ( !canvas()->onCanvas( 1, y() + height()/2 + yVelocity() ) )
        {
            MoveY = false;
            move( x(), canvas()->height() - height()/2 );
            setYVelocity( yVelocity() * -1 * Bump_resistance );
        }
        // upper border hit check
        else if ( !canvas()->onCanvas( 1, y() - height()/2 + yVelocity() ) )
        {
            MoveY = false;
            move( x(), 0 + height()/2 );
            setYVelocity( yVelocity() * -1 * Bump_resistance );
        }
    }
    else    // time to move
    {
        if ( MoveX && MoveY )
            move( x() + xVelocity(), y() + yVelocity() );
        else if ( MoveX )
            move( x() + xVelocity(), y() );
        else if ( MoveY )
            move( x(), y() + yVelocity() );

        MoveX = MoveY = true;
    }*/
}

