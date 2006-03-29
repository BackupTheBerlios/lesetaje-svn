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
#include "skeletoncanvasview.hpp"
#include "tag.hpp"
#include <qapplication.h>
#include <qwidget.h>
#include <qcanvas.h>
#include <qpushbutton.h>
#include <qlayout.h>
Tag *sphere23;

SkeletonWidget::SkeletonWidget( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
    // Create and setup canvas and view
    Canvas = new QCanvas( QPixmap( "Loesungsskelett.jpg" ),1,1,630,597 );

//kein Effekt:    Canvas->resize(  700,1000 );
    CanvasView = new SkeletonCanvasView( Canvas, this, "CanvasView" );
//kein Effekt:    CanvasView->resize( 700, 1000  );
    // setup the quit button
    
    QuitButton = new QPushButton( "&Ende", this, "QuitButton" );
    connect( QuitButton, SIGNAL( clicked() ), qApp, SLOT( quit() ) );
    
    PruefButton = new QPushButton( "&Pruefen", this, "PruefButton" );
    connect( PruefButton, SIGNAL( pressed() ), this, SLOT( Pruefen() ) );
    
    connect( PruefButton, SIGNAL( released() ), this, SLOT( Pruefen() ) );
    
    
    
    
    
    
    // setup the layout manager
    QVBoxLayout *vlay = new QVBoxLayout( this );
//    vlay->setResizeMode( QLayout::Fixed );
    vlay->addWidget( CanvasView );
    vlay->addWidget( QuitButton );
    vlay->addWidget( PruefButton);
    // add a planet to our scenery
  
    
    Tag *sphere3 = new Tag( new QCanvasPixmapArray( "Unterkiefer.gif" ), Canvas );
    sphere3->move( 500, 150 );
    sphere3->show();
        
    Tag *sphere4 = new Tag( new QCanvasPixmapArray( "Schienbein.gif" ), Canvas );
    sphere4->move( 500, 165 );
    sphere4->show();
    
    
    Tag *sphere5 = new Tag( new QCanvasPixmapArray( "Oberschenkelknochen.gif" ), Canvas );
    sphere5->move( 500, 190 );
    sphere5->show();
    
    
    Tag *sphere6 = new Tag( new QCanvasPixmapArray( "Schaedel.gif" ), Canvas );
    sphere6->move( 500, 210 );
    sphere6->show();
    
    
    Tag *sphere7 = new Tag( new QCanvasPixmapArray( "Schambein.gif" ), Canvas );
    sphere7->move( 500,230 );
    sphere7->show();
    
    
    Tag *sphere8 = new Tag( new QCanvasPixmapArray( "Sitzbein.gif" ), Canvas );
    sphere8->move( 500, 250 );
    sphere8->show();
    
    
    Tag *sphere9 = new Tag( new QCanvasPixmapArray( "Schluesselbein.gif" ), Canvas );
    sphere9->move( 500, 270 );
    sphere9->show();
    
    
    Tag *sphere10 = new Tag( new QCanvasPixmapArray( "Handwurzelknochen.gif" ), Canvas );
    sphere10->move( 500, 290 );
    sphere10->show();
    
    Tag *sphere11 = new Tag( new QCanvasPixmapArray( "Oberarmknochen.gif" ), Canvas );
    sphere11->move( 500, 310 );
    sphere11->show();
      
    Tag *sphere12 = new Tag( new QCanvasPixmapArray( "Wadenbein.gif" ), Canvas );
    sphere12->move( 500, 330 );
    sphere12->show();
   
     Tag *sphere14 = new Tag( new QCanvasPixmapArray( "Halswirbel.gif" ), Canvas );
    sphere14->move( 600, 170 );
    sphere14->show();
    
    Tag *sphere15 = new Tag( new QCanvasPixmapArray( "Augenhoehle.gif" ), Canvas );
    sphere15->move( 600, 190 );
    sphere15->show();
    
    Tag *sphere16 = new Tag( new QCanvasPixmapArray( "Brustbein.gif" ), Canvas );
    sphere16->move( 600, 210 );
    sphere16->show();
    
    Tag *sphere17 = new Tag( new QCanvasPixmapArray( "Darmbein.gif" ), Canvas );
    sphere17->move( 600, 230 );
    sphere17->show();
    
    Tag *sphere18 = new Tag( new QCanvasPixmapArray( "Elle.gif" ), Canvas );
    sphere18->move( 600, 250 );
    sphere18->show();
    
    Tag *sphere19 = new Tag( new QCanvasPixmapArray( "Speiche.gif" ), Canvas );
    sphere19->move( 600, 270 );
    sphere19->show();
    
    Tag *sphere20 = new Tag( new QCanvasPixmapArray( "Kniescheibe.gif" ), Canvas );
    sphere20->move( 600, 290 );
    sphere20->show();
  
    Tag *sphere21 = new Tag( new QCanvasPixmapArray( "Oberkiefer.gif" ), Canvas );
    sphere21->move( 600, 310 );
    sphere21->show();
    
    Tag *sphere22 = new Tag( new QCanvasPixmapArray( "Fusswurzelknochen.gif" ), Canvas );
    sphere22->move( 600, 330 );
    sphere22->show();
    
    sphere23 = new Tag(new QCanvasPixmapArray( "Loesung.gif" ), Canvas );
    sphere23->move( 550, 240 );
    
   
   
   





}
SkeletonWidget::~SkeletonWidget()
{
}
void SkeletonWidget::Pruefen(void)
{
   if (sphere23->isVisible() )
   	sphere23->hide(); 
   else
   	sphere23->show(); 
   Canvas->update();
  
  }
