#include "stdafx.h"
#include "Control.h"
#include "Panel.h"

namespace MetaFrame {

    Control::Control(FrameObject * captured, Panel * editorSpace, ArrayList<Control*> *controls)
        : captured(captured),
        editorSpace(editorSpace),
        controls(controls)
    {
        Rect rect = captured->getRect();

        controlLeft = new Panel;
        controlRight = new Panel;
        controlTop = new Panel;
        controlButtom = new Panel;

        updatePosition();

        static Point pnt;

        editorSpace->addMouseReleasedListener([&](FrameObject *sender, const MouseEventInfo &event) {
            pnt = Point();
        });

        controlButtom->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (pnt == Point()) { pnt = Point(event.xOnParent, event.yOnParent); return;  }

            for (auto capt : *controls) {
                capt->captured->setHeight(capt->captured->getHeight() + (event.yOnParent - pnt.y));
                capt->captured->pack();
                capt->updatePosition();
            }             

            pnt = Point(event.xOnParent, event.yOnParent);
        });

        controlTop->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (pnt == Point()) { pnt = Point(event.xOnParent, event.yOnParent); return; }

            for (auto capt : *controls) {
                capt->captured->setY(capt->captured->getY() + (event.yOnParent - pnt.y));
                capt->captured->setHeight(capt->captured->getHeight() - (event.yOnParent - pnt.y));
                capt->captured->pack();
                capt->updatePosition();
            }

            pnt = Point(event.xOnParent, event.yOnParent);
        });


        controlRight->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (pnt == Point()) { pnt = Point(event.xOnParent, event.yOnParent); return; }

            for (auto capt : *controls) {
                capt->captured->setWidth(capt->captured->getWidth() + (event.xOnParent - pnt.x));
                capt->captured->pack();
                capt->updatePosition();
            }

            pnt = Point(event.xOnParent, event.yOnParent);
        });

        controlLeft->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (pnt == Point()) { pnt = Point(event.xOnParent, event.yOnParent); return; }

            for (auto capt : *controls) {
                capt->captured->setX(capt->captured->getX() + (event.xOnParent - pnt.x));
                capt->captured->setWidth(capt->captured->getWidth() - (event.xOnParent - pnt.x));
                capt->captured->pack();
                capt->updatePosition();
            }

            pnt = Point(event.xOnParent, event.yOnParent);
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