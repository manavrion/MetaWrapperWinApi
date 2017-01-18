#pragma once

#include "Panel.h"
#include "TextField.h"
#include "Label.h"


namespace MetaFrame {

    class Control {
    public:
        Control(FrameObject * captured, FrameObject *editorSpace, ArrayList<Control*> *controls);

        bool isCaptured(FrameObject *captured) {
            if (this->captured == captured) {
                return true;
            } else {
                return false;
            }
        }

        FrameObject *captured;
        Point pnt;
    private:
        void updatePosition() {
            Size size(12, 12);

            Rect rect = captured->getRect();
            controlLeft
                ->setPosition(Point(rect.x - size.width, rect.y + rect.height / 2 - size.width / 2))
                ->setSize(size);

            controlRight
                ->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - size.width / 2))
                ->setSize(size);

            controlTop
                ->setPosition(Point(rect.x + rect.width / 2 - size.height / 2, rect.y - size.height))
                ->setSize(size);

            controlButtom
                ->setPosition(Point(rect.x + rect.width / 2 - size.height / 2, rect.y + rect.height))
                ->setSize(size);

            controlLeft->repaint();
            controlRight->repaint();
            controlTop->repaint();
            controlButtom->repaint();
        }
        FrameObject *insertionSpace;

        ArrayList<Control*> *controls;


        Panel *controlLeft = null;
        Panel *controlRight = null;
        Panel *controlTop = null;
        Panel *controlButtom = null;
        //TextField *controlText = null;
        //Label *controlLabelText = null;
        //Button *controlDeleteButton = null;
    public:
        ~Control() {
            delete controlLeft;
            delete controlRight;
            delete controlTop;
            delete controlButtom;
        };
    };

}