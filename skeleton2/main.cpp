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

#include "skeletonwidget.hpp"
#include <qapplication.h>
#include <qwidget.h>


int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    SkeletonWidget bw( 0, "SkeletonWidget" );
    a.setMainWidget( &bw );
    bw.setCaption( "Anatomie for beginners!" );
    //bw.setStaticBackground(1==1);
    bw.setFixedSize ( 630, 630 );
    bw.show();
    return a.exec();  
   
}



