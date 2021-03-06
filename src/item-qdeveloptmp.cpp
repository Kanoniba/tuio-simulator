#include "item.h"

myitem::myitem(QPolygon *mypolygon ,QTimeLine* timer,QGraphicsItem *parent,QGraphicsScene *scene):QGraphicsPolygonItem(parent, scene)
	
	{  
		if(  (mypolygon)== NULL )
		    {
		        mypolygon = new QPolygon;   	
 			    (*mypolygon) << QPoint(-50, -50) << QPoint(-50, 50)
                      << QPoint(50, 50) << QPoint(50,-50)
                      << QPoint(-50,-50); 
            }
                          
                          
                          
       setPolygon(*mypolygon);
       animation = new QGraphicsItemAnimation;
                       

    
                          
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setCursor(Qt::PointingHandCursor);
    
	}
	

	
 void myitem::keyPressEvent(QKeyEvent *keyevent)
 {
 	switch (keyevent->key())
 	{
 		case Qt::Key_R : rotate(1);
 					break;
 					
 					
 		case Qt::Key_L : rotate(-1);
 					break;
 		
 		default : break;
 					
 					
 					
		}
 	QGraphicsItem::keyPressEvent(keyevent);
 	
}

