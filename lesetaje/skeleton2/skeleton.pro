#
#  This file is part of "bounce" by Gunnstein Lye <gl@ez.no>
#  Copyright (C) 2000 eZ systems as, Norway
#  (http://www.ez.no)
#  bounce is part of a QCanvas tutorial on www.zez.org.
#  
#  bounce is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2, or (at your option)
#  any later version.
#  
#  You should have received a copy of the GNU General Public License
#  along with bounce; see the file COPYING.  If not, write to
#  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
#  Boston, MA 02111-1307, USA.
#

PROJECT                 = skeleton
TEMPLATE                = app
CONFIG                  = qt warn_on debug

OBJECTS_DIR             = obj
MOC_DIR                 = moc

HEADERS                 = skeletonwidget.hpp \
                          skeletoncanvasview.hpp \
                          tag.hpp \
			  

SOURCES                 = main.cpp \
                          skeletonwidget.cpp \
                          skeletoncanvasview.cpp \
                          tag.cpp \

TARGET                  = skeleton
