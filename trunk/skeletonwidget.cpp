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

#include "skeletonwidget.hpp"
#include "skeletoncanvasview.hpp"
#include "bone.hpp"

#include <math.h>
#include <qapplication.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qcanvas.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtimer.h>
 Bone *sphere13;
 Bone *knochen[16];
 Bone *rotknochen[16];
 int i;
 int j;
 int sollx[16];
 int solly[16];

SkeletonWidget::SkeletonWidget( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
    
    // Create and setup canvas and view
    Canvas = new QCanvas( this, "Canvas" );
    Canvas->setBackgroundColor( Qt::black );
    Canvas->setBackgroundPixmap( QPixmap( "stars.png" ) );
    Canvas->setAdvancePeriod( 10 );
    Canvas->resize( 500, 600 ); //900x600 
//    Canvas->adaptSize();
    CanvasView = new SkeletonCanvasView( Canvas, this, "CanvasView" );
    //CanvasView->resize( 900, 700 ); //900x600 

    ergebnis = new QLabel ("Setze das Skelett zusammen!",CanvasView, "result");
    ergebnis->setBackgroundColor(Qt::black);
    ergebnis->setPaletteForegroundColor(Qt::white );
    ergebnis->move(5,5);
    ergebnis->setFixedWidth(280);

 

    
    QFont myfont;
    myfont.setPointSize(15);
    ergebnis->setFont(myfont);
     // setup the quit button
    QuitButton = new QPushButton( "&Quit", this, "QuitButton" );
    connect( QuitButton, SIGNAL( clicked() ), qApp, SLOT( quit() ) );
    
	PruefenButton = new QPushButton( "&pruefen", this, "PruefenButton" );
    connect( PruefenButton, SIGNAL( clicked() ), this,  SLOT( pruefen() ) );
   
 
    // setup the layout manager
    QVBoxLayout *vlay = new QVBoxLayout( this );
    QHBoxLayout *inlay = new QHBoxLayout( vlay);
//	vlay->addWidget(ergebnis);
	// ergebnis->setBackgroundMode(Qt::NoBackground);
    // ergebnis->set
//    vlay->setResizeMode( QLayout::Fixed );
    vlay->addWidget( CanvasView );
    vlay->addItem( inlay);
    inlay->addWidget(QuitButton );
	inlay->addWidget( PruefenButton);
    
    // add a planet to our scenery
    knochen[0] = new Bone( new QCanvasPixmapArray( "oberschenkel.gif" ), Canvas );
    knochen[0]->move(323, 350);
    knochen[1] = new Bone( new QCanvasPixmapArray( "oberschenkell.gif" ), Canvas );
    knochen[1]->move(389, 350);
    knochen[2] = new Bone( new QCanvasPixmapArray( "Oberkoerper.gif" ), Canvas );
    knochen[2]->move(360, 174);
    knochen[3] = new Bone( new QCanvasPixmapArray( "kopf.gif" ), Canvas );
    knochen[3]->move(363, 45);
    knochen[4] = new Bone( new QCanvasPixmapArray( "oberarml.gif" ), Canvas );
    knochen[4]->move(416, 168);
    knochen[5] = new Bone( new QCanvasPixmapArray( "halswirbel2.gif" ), Canvas );
    knochen[5]->move(362, 87);
    knochen[6] = new Bone( new QCanvasPixmapArray( "unterarm.gif" ), Canvas );
    knochen[6]->move(294, 262);
    knochen[7] = new Bone( new QCanvasPixmapArray( "unterarml.gif" ), Canvas );
    knochen[7]->move(426, 262);
    knochen[8] = new Bone( new QCanvasPixmapArray( "huefte.gif" ), Canvas );
    knochen[8]->move(363, 267);
    knochen[9] = new Bone( new QCanvasPixmapArray( "handl.gif" ), Canvas ); //r
    knochen[9]->move(305, 334);
    knochen[10] = new Bone( new QCanvasPixmapArray( "handr.gif" ), Canvas );
    knochen[10]->move(444, 332);
    knochen[11] = new Bone( new QCanvasPixmapArray( "fussrechts.gif" ), Canvas );
    knochen[11]->move(330, 549);
    knochen[12] = new Bone( new QCanvasPixmapArray( "oberarm.gif" ), Canvas );
    knochen[12]->move(304, 164);
    knochen[13] = new Bone( new QCanvasPixmapArray( "fusslinks.gif" ), Canvas );
    knochen[13]->move(372, 570);
    knochen[14] = new Bone( new QCanvasPixmapArray( "schienbein.gif" ), Canvas );
    knochen[14]->move(332, 480);
    knochen[15] = new Bone( new QCanvasPixmapArray( "schienbeinl.gif" ), Canvas );
    knochen[15]->move(373,490);
     
    for (i=0; i<=15; i++)
    {
       
    	sollx[i] = (int)round(knochen[i]->x());
	    solly[i] = (int)round(knochen[i]->y());
		knochen[i]->show();
	    
      	knochen[i]->setMass(1);
    	 
	
		
    }
		 knochen[3]->setMass(0);
  
 //   ergebnis.show;
	
 	rotknochen[0] = new Bone( new QCanvasPixmapArray( "rot_oberschenkel.gif" ), Canvas );
	rotknochen[1] = new Bone( new QCanvasPixmapArray( "rot_oberschenkell.gif" ), Canvas );
    rotknochen[2] = new Bone( new QCanvasPixmapArray( "rot_Oberkoerper.gif" ), Canvas );
    rotknochen[3] = new Bone( new QCanvasPixmapArray( "rot_kopf.gif" ), Canvas );
    rotknochen[4] = new Bone( new QCanvasPixmapArray( "rot_oberarml.gif" ), Canvas );
    rotknochen[5] = new Bone( new QCanvasPixmapArray( "rot_halswirbel2.gif" ), Canvas );
    rotknochen[6] = new Bone( new QCanvasPixmapArray( "rot_unterarm.gif" ), Canvas );
    rotknochen[7] = new Bone( new QCanvasPixmapArray( "rot_unterarml.gif" ), Canvas );
    rotknochen[8] = new Bone( new QCanvasPixmapArray( "rot_huefte.gif" ), Canvas );
    rotknochen[9] = new Bone( new QCanvasPixmapArray( "rot_handl.gif" ), Canvas ); //r
    rotknochen[10] = new Bone( new QCanvasPixmapArray( "rot_handr.gif" ), Canvas );
    rotknochen[11] = new Bone( new QCanvasPixmapArray( "rot_fussrechts.gif" ), Canvas );
    rotknochen[12] = new Bone( new QCanvasPixmapArray( "rot_oberarm.gif" ), Canvas );
    rotknochen[13] = new Bone( new QCanvasPixmapArray( "rot_fusslinks.gif" ), Canvas );
    rotknochen[14] = new Bone( new QCanvasPixmapArray( "rot_schienbein.gif" ), Canvas );
    rotknochen[15] = new Bone( new QCanvasPixmapArray( "rot_schienbeinl.gif" ), Canvas );   
 	for (i=0; i<=15; i++)
	rotknochen[i]->hide();
   
}




SkeletonWidget::~SkeletonWidget()
{
	for (i=0; i<=15; i++)
        {printf(" X,Y von %d : %g / %g \n",i,knochen[i]->x(), knochen[i]->y() );
	
	}
}


void  SkeletonWidget::pruefen(void)
{
	    int fehler=0;
		double toleranz = 14.6 ;
		 
        for (i=0; i<=15; i++)
	    {
		    if (( toleranz < abs((double)sollx[i] - knochen[i]->x())  ) || toleranz < abs((double)solly[i] - knochen[i]->y())  )
			{
				fehler++ ;
				rotknochen[i]->move( knochen[i]->x() ,  knochen[i]->y() );
				rotknochen[i]->show();
		 // 			knochen[i]->update();
		
			}
		}		
		ergebnis->setText("Fehler: "+ QString::number(fehler));
		Canvas->update();	
				sleep(2);	
		 for (i=0; i<=15; i++)
	    	rotknochen[i]->hide(); 
			
		Canvas->update();		
	//Timer->start( 1000, true );
	
	
	
	}

