#include "stdafx.h"
#include "Editor.h"

namespace MetaFrame {
    void Editor::bindControl(Rect rect, AbstructFrameElement * element) {
        if (controlLeft != null) {
            controlLeft->destroy();
        }
        if (controlRight != null) {
            controlRight->destroy();
        }
        if (controlTop != null) {
            controlTop->destroy();
        }
        if (controlButtom != null) {
            controlButtom->destroy();
        }

        controlLeft = new Panel;
        controlRight = new Panel;
        controlTop = new Panel;
        controlButtom = new Panel;

        controlLeft
            ->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4))
            ->setSize(8, 8);
        editorSpace->add(controlLeft);
        controlLeft->build();

        controlRight
            ->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4))
            ->setSize(8, 8);
        editorSpace->add(controlRight);
        controlRight->build();

        controlTop
            ->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8))
            ->setSize(8, 8);
        editorSpace->add(controlTop);
        controlTop->build();

        controlButtom
            ->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height))
            ->setSize(8, 8);
        editorSpace->add(controlButtom);
        controlButtom->build();


        controlButtom->addMouseDraggedListener([=](NativeAbstructObject &sender, const MouseEvent &event) {
            //sender.setX(event.xOnParent - 4);
            sender.setY(event.yOnParent - 2);
            element->setHeight(event.yOnParent - 2 - element->getY());

            Rect rect = element->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            //controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
        });

        controlTop->addMouseDraggedListener([=](NativeAbstructObject &sender, const MouseEvent &event) {
            sender.setY(event.yOnParent - 4);
            element->setY(event.yOnParent - 4 + sender.getHeight());

            element->setHeight(-element->getY() + controlButtom->getY());

            Rect rect = element->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            //controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
        });

        controlRight->addMouseDraggedListener([=](NativeAbstructObject &sender, const MouseEvent &event) {
            //sender.setX(event.xOnParent - 4);
            sender.setX(event.xOnParent - 2);
            element->setWidth(event.xOnParent - 2 - element->getX());

            Rect rect = element->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            //controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
        });

        controlLeft->addMouseDraggedListener([=](NativeAbstructObject &sender, const MouseEvent &event) {
            sender.setX(event.xOnParent - 4);
            element->setX(event.xOnParent - 4 + sender.getWidth());

            element->setWidth(-element->getX() + controlRight->getX());

            Rect rect = element->getRect();
            //controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
        });
    }
}