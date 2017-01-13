#pragma once

#include "Panel.h"
#include "TextField.h"
#include "Label.h"


namespace MetaFrame {

    class Control {
    public:
        Control(FrameObject * captured, Panel *editorSpace);

        bool isCaptured(FrameObject *captured) {
            if (this->captured == captured) {
                return true;
            } else {
                return false;
            }
        }

        void updatePosition() {
            Rect rect = captured->getRect();
            controlLeft
                ->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4))
                ->setSize(8, 8);

            controlRight
                ->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4))
                ->setSize(8, 8);

            controlTop
                ->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8))
                ->setSize(8, 8);

            controlButtom
                ->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height))
                ->setSize(8, 8);

            controlLeft->repaint();
            controlRight->repaint();
            controlTop->repaint();
            controlButtom->repaint();
        }
    private:
        Panel *editorSpace;

        FrameObject *captured;

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