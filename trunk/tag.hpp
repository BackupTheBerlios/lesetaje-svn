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

#ifndef BALL_HPP
#define BALL_HPP

#include <qstring.h>
#include <qcanvas.h>
#include <qpoint.h>


class Tag : public QCanvasSprite
{
public:
    Tag( QCanvasPixmapArray *parray, QCanvas *canvas );
    ~Tag();

    bool hit( const QPoint &p ) const;
    void advance( int phase );

private:
    bool MoveX, MoveY;
    double Air_resistance;
    double Bump_resistance;
    double Mass;

};


#endif  // BALL_HPP
