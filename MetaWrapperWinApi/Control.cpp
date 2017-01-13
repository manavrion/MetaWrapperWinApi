#include "stdafx.h"
#include "Control.h"
#include "Panel.h"

namespace MetaFrame {

    Control::Control(FrameObject * captured, Panel * editorSpace)
        : captured(captured),
        editorSpace(editorSpace) 
    {
        Rect rect = captured->getRect();

        controlLeft = new Panel;
        controlRight = new Panel;
        controlTop = new Panel;
        controlButtom = new Panel;

        updatePosition();

        controlButtom->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            //sender.setX(event.xOnParent - 4);
            sender->setY(event.yOnParent - 2);
            captured->setHeight(event.yOnParent - 2 - captured->getY());

            Rect rect = captured->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            //controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
            captured->pack();
        });

        controlTop->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            sender->setY(event.yOnParent - 4);
            captured->setY(event.yOnParent - 4 + sender->getHeight());

            captured->setHeight(-captured->getY() + controlButtom->getY());

            Rect rect = captured->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            //controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
            captured->pack();
        });


        controlRight->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            //sender.setX(event.xOnParent - 4);
            sender->setX(event.xOnParent - 2);
            captured->setWidth(event.xOnParent - 2 - captured->getX());

            Rect rect = captured->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            //controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
            captured->pack();
        });

        controlLeft->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            sender->setX(event.xOnParent - 4);
            captured->setX(event.xOnParent - 4 + sender->getWidth());

            captured->setWidth(-captured->getX() + controlRight->getX());

            Rect rect = captured->getRect();
            //controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
            captured->pack();
        });






        editorSpace->add(controlLeft);
        controlLeft->build();

        editorSpace->add(controlRight);
        controlRight->build();

        editorSpace->add(controlTop);
        controlTop->build();

        editorSpace->add(controlButtom);
        controlButtom->build();



    }

}