#include "stdafx.h"
#include "Control.h"
#include "Panel.h"

namespace MetaFrame {

    Control::Control(FrameObject * captured, FrameObject * insertionSpace, ArrayList<Control*> *controls)
        : captured(captured),
        insertionSpace(insertionSpace),
        controls(controls)
        , pnt()
    {
        insertionSpace = captured->getParent();

        Rect rect = captured->getRect();

        controlLeft = new Panel;
        controlRight = new Panel;
        controlTop = new Panel;
        controlButtom = new Panel;

        updatePosition();

        
        controlButtom->addMouseMovedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            pnt = Point(event.xOnParent, event.yOnParent);
        });
        controlTop->addMouseMovedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            pnt = Point(event.xOnParent, event.yOnParent);
        });
        controlLeft->addMouseMovedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            pnt = Point(event.xOnParent, event.yOnParent);
        });
        controlRight->addMouseMovedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            pnt = Point(event.xOnParent, event.yOnParent);
        });

        controlButtom->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (pnt == Point()) { return; }

            for (auto capt : *controls) {
                capt->captured->setHeight(capt->captured->getHeight() + (event.yOnParent - pnt.y));
                capt->captured->pack();
                capt->updatePosition();
            }             
        });

        controlTop->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (pnt == Point()) { return; }

            for (auto capt : *controls) {
                capt->captured->setY(capt->captured->getY() + (event.yOnParent - pnt.y));
                capt->captured->setHeight(capt->captured->getHeight() - (event.yOnParent - pnt.y));
                capt->captured->pack();
                capt->updatePosition();
            }
        });


        controlRight->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (pnt == Point()) { return; }

            for (auto capt : *controls) {
                capt->captured->setWidth(capt->captured->getWidth() + (event.xOnParent - pnt.x));
                capt->captured->pack();
                capt->updatePosition();
            }

        });

        controlLeft->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (pnt == Point()) { return; }

            for (auto capt : *controls) {
                capt->captured->setX(capt->captured->getX() + (event.xOnParent - pnt.x));
                capt->captured->setWidth(capt->captured->getWidth() - (event.xOnParent - pnt.x));
                capt->captured->pack();
                capt->updatePosition();
            }
        });


        insertionSpace->add(controlLeft);
        controlLeft->build();

        insertionSpace->add(controlRight);
        controlRight->build();

        insertionSpace->add(controlTop);
        controlTop->build();

        insertionSpace->add(controlButtom);
        controlButtom->build();

        captured->addPropertyChangedListener([&](FrameObject *object) {
            this->updatePosition();
        });

    }

}