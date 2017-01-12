#include "stdafx.h"
#include "Controllers.h"
namespace MetaFrame {

    Controllers::Controllers(Editor *editor, Panel *editorSpace)
        : editor(editor), editorSpace(editorSpace)
    {

    }

    void Controllers::addDragAndDropActions(FrameObject *frameObject) {

        frameObject->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (!this->isBinded(sender)) {
                return;
            }

            sender->setX(event.xOnParent - sender->getWidth() / 2);
            sender->setY(event.yOnParent - sender->getHeight() / 2);

            for (auto &ob : controls) {
                ob->updatePosition();
            }
            editorSpace->repaint();
            sender->repaint();
        });

        

    }

    void Controllers::rebind(FrameObject * frameObject) {
        clearBind();

        Control *control = new Control(frameObject, editorSpace);
        controls.push_back(control);

        addDragAndDropActions(frameObject);

    }

    void Controllers::bind(ArrayList<FrameObject> objects) {}

    void Controllers::clearBind() {
        for (auto ob : controls) {
            delete ob;
        }
        controls.clear();
    }

    Controllers::~Controllers() {}






    Control::Control(FrameObject * captured, Panel *editorSpace) : captured(captured), editorSpace(editorSpace) {
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

    void Control::updatePosition() {
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

}