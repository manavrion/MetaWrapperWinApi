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


        controlButtom->addMouseDraggedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event) {
            //sender.setX(event.xOnParent - 4);
            sender->setY(event.yOnParent - 2);
            element->setHeight(event.yOnParent - 2 - element->getY());

            Rect rect = element->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            //controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
        });

        controlTop->addMouseDraggedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event) {
            sender->setY(event.yOnParent - 4);
            element->setY(event.yOnParent - 4 + sender->getHeight());

            element->setHeight(-element->getY() + controlButtom->getY());

            Rect rect = element->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            //controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
        });


        controlRight->addMouseDraggedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event) {
            //sender.setX(event.xOnParent - 4);
            sender->setX(event.xOnParent - 2);
            element->setWidth(event.xOnParent - 2 - element->getX());

            Rect rect = element->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            //controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
        });

        controlLeft->addMouseDraggedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event) {
            sender->setX(event.xOnParent - 4);
            element->setX(event.xOnParent - 4 + sender->getWidth());

            element->setWidth(-element->getX() + controlRight->getX());

            Rect rect = element->getRect();
            //controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
        });

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ((NativeAbstructObject*)element)->addMouseDraggedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event) {
            if (controlLeft == null) {
                return;
            }
            
            sender->setX(event.xOnParent - sender->getWidth()/2);
            sender->setY(event.yOnParent - sender->getHeight()/2);
            Rect rect = element->getRect();
            controlLeft->setPosition(Point(rect.x - 8, rect.y + rect.height / 2 - 4));
            controlRight->setPosition(Point(rect.x + rect.width, rect.y + rect.height / 2 - 4));
            controlTop->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y - 8));
            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 4, rect.y + rect.height));
            editorSpace->repaint();
            ((AbstructFrameElement*)sender)->repaint();
        });

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //controlText

        if (controlText != null) {
            controlText->destroy();
        }
        if (controlLabelText != null) {
            controlLabelText->destroy();
        }
        if (controlDeleteButton != null) {
            controlDeleteButton->destroy();
        }
        controlText = new TextField;
        controlLabelText = new Label;
        controlDeleteButton = new Button;

        panelTool->add(controlText
                       ->setHorizontalAlignment(HorizontalAlignment::Stretch)
                       ->setVerticalAlignment(VerticalAlignment::Bottom));
        panelTool->add(controlLabelText
                       ->setText(L"Редактирование текста:")
                       ->setMargin(10, 10, 10, 30)
                       ->setHorizontalAlignment(HorizontalAlignment::Stretch)
                       ->setVerticalAlignment(VerticalAlignment::Bottom));

        panelTool->add(controlDeleteButton
                       ->setText(L"Удалить")
                       ->setMargin(10, 10, 10, 60)
                       ->setHorizontalAlignment(HorizontalAlignment::Stretch)
                       ->setVerticalAlignment(VerticalAlignment::Bottom));
        

        controlText->addActionListener([=](AbstructFrameObject *tf) {
            element->setText(tf->getText());
        });

        controlDeleteButton->addActionListener([=](Button *button) {
            element->destroy();
            this->destroyControl();
        });


        panelTool->pack();
        controlText->build();
        controlLabelText->build();
        controlDeleteButton->build();

        

    }
    void Editor::destroyControl() {
        if (controlLeft == null) {
            return;
        }
        /*controlLeft->destroy();
        controlRight->destroy();
        controlTop->destroy();
        controlButtom->destroy();

        controlText->destroy();
        controlLabelText->destroy();

        controlDeleteButton->destroy();*/

        delete controlLeft;
        delete controlRight;
        delete controlTop;
        delete controlButtom;

        delete controlText;
        delete controlLabelText;
     
        //delete controlDeleteButton;
        controlDeleteButton->destroy();

        controlLeft = null;
        controlRight = null;
        controlTop = null;
        controlButtom = null;

        controlText = null;
        controlLabelText = null;

        controlDeleteButton = null;

    }
}