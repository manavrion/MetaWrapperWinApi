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

        frameObject->addMousePressedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            clearBind();
            controls.push_back(new Control(frameObject, editorSpace));
        });

        frameObject->addMouseDoubleClickedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (!this->isBinded(sender)) {
                return;
            }

            delete dynamicTextField;
            dynamicTextField = new TextField();

            dynamicTextField->setText(sender->getText());

            editorSpace->add(dynamicTextField
                             ->setPosition(sender->getX(), sender->getY() - 20)
                             ->addActionListener([=](TextField *tf) {
                                sender->setText(tf->getText());
                             })
            );


            //editorSpace->add()
            /*((FrameNode*)sender)->add((new TextField)
                                      ->setMargin(0, 0, 0, 0)
                                      ->setAlignment(Alignment::Center)
            );*/
            editorSpace->build();
        });

    }

    void Controllers::rebind(FrameObject * frameObject) {
        clearBind();

        controls.push_back(new Control(frameObject, editorSpace));

        addDragAndDropActions(frameObject);
    }

    void Controllers::bind(ArrayList<FrameObject> objects) {}

    void Controllers::clearBind() {
        delete dynamicTextField;
        dynamicTextField = null;
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