#include "sceneellipse.h"
#include <iostream>

SceneEllipse::SceneEllipse()
{
	
	
	//animation = new QGraphicsItemAnimation;
	animation = new TUIOanimation;
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable,true);
    setCursor(Qt::PointingHandCursor);
    
    tangible_type = 2;
    tangible_geom = QString("Ellipse");
    fiducial.append(2);
    OSCdata = new TouchData;
    OSCdata->X = (scenePos()).rx() ;
    OSCdata->LX = (scenePos()).rx() ;
    OSCdata->Y = (scenePos()).ry() ;
    OSCdata->LY = (scenePos()).ry() ;

}


 void SceneEllipse::keyPressEvent(QKeyEvent *keyevent)
 {
 	switch (keyevent->key())
 	{
 		case Qt::Key_R : rotate(1);
 					OSCdata->orientation++;
 					OSCdata->orientation = OSCdata->orientation  % 360 ;
 					if (OSCdata->orientation<0) OSCdata->orientation += 360 ;
 					OSCdata->angle = OSCdata->orientation * 0.01745 ; //Convert degree to radian
 					OSCdata->packetUpdate = true ;
 					break;
 					
 					
 		case Qt::Key_L : rotate(-1);
 		 			OSCdata->orientation--;
 					OSCdata->orientation = OSCdata->orientation  % 360 ;
 					if (OSCdata->orientation<0) OSCdata->orientation += 360 ;
 					OSCdata->angle = OSCdata->orientation * 0.01745 ; //Convert degree to radian
 					OSCdata->packetUpdate = true ;
 					break;
 		
 		default : break;
 					
 					
 					
		}
 	QGraphicsItem::keyPressEvent(keyevent);
 	
}


  void SceneEllipse::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
	{

		//std::cout << "Ellipse Mouse Release Event TangibleId  " << OSCdata->ID << "\n" ;
		QGraphicsItem::mouseReleaseEvent(mouseEvent);


	}

  void SceneEllipse::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
	{
		//std::cout << "Ellipse Mouse Press Event TangibleId  " << OSCdata->ID << "\n" ;
		QGraphicsItem::mousePressEvent(mouseEvent);


	}
	
  void SceneEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
	{
		//std::cout << "Ellipse Mouse Move Event TangibleId  " << OSCdata->ID << "\n" ;
		OSCdata->X = (mouseEvent->scenePos()).rx() ;
		OSCdata->Y = (mouseEvent->scenePos()).ry() ;
		OSCdata->packetUpdate = true ;
		QGraphicsItem::mouseMoveEvent(mouseEvent);



	}

