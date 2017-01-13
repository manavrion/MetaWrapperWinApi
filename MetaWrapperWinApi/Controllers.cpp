#include "stdafx.h"
#include "Controllers.h"
namespace MetaFrame {

    Controllers::Controllers(Editor *editor, Panel *editorSpace, Panel *panelTool)
        : editor(editor), editorSpace(editorSpace), panelTool(panelTool)
    {
        editorSpace->addMouseReleasedListener([=](Panel *panel, const MouseEventInfo &event) {
            for (auto ob : editorSpace->getChilds()) {
                if (ob->getRect().contains(event.x, event.y)) {
                    return;
                }
            }
            clearBind();
        });
        capturedZone = null;
        editorSpace->addMousePressedListener([=](Panel *panel, const MouseEventInfo &event) {
            for (auto ob : editorSpace->getChilds()) {
                if (ob->getRect().contains(event.x, event.y)) {
                    return;
                }
            }
            delete capturedZone;
            capturedZone = null;
            capturedZone = new Panel;
            capturedZone->setPosition(event.x, event.y);
            editorSpace->add(capturedZone);
            capturedZone->setText(L"capture zone");
            capturedZone->build();
            *capturedPoint = {event.x, event.y};
        });

        editorSpace->addMouseDraggedListener([=](Panel *panel, const MouseEventInfo &event) {

            if (capturedZone != null) {
                int dx = event.x - capturedPoint->x;
                int dy = event.y - capturedPoint->y;

                if (dx >= 0) {
                    capturedZone->setWidth(dx);
                } else {
                    capturedZone->setWidth(capturedPoint->x - event.x);
                    capturedZone->setX(event.x);
                }

                if (dy >= 0) {
                    capturedZone->setHeight(dy);
                } else {
                    capturedZone->setHeight(capturedPoint->y - event.y);
                    capturedZone->setY(event.y);
                }
                capturedZone->repaint();
            }  
        });

        editorSpace->addMouseReleasedListener([=](Panel *panel, const MouseEventInfo &event) {
            for (auto ob : editorSpace->getChilds()) {
                if (ob == capturedZone) {
                    continue;
                }
                if (ob->getRect().contains(event.x, event.y)) {
                    return;
                }
            }
            if (editorSpace == null) {
                return;
            }
            
            clearBind();

            ArrayList<FrameObject*> captiredElements;

           for (auto elem : editorSpace->getChilds()) {
                if (elem != capturedZone) {
                    if (capturedZone->getRect().contains(elem->getRect())) {
                        captiredElements.push_back(elem);
                    }
                }
            }
            delete capturedZone;
            capturedZone = null;

            if (!captiredElements.empty()) {
                bind(captiredElements);
            }
            


        });

    }

    void Controllers::addDragAndDropActions(FrameObject *frameObject) {

        frameObject->clearMouseDraggedListeners();
        frameObject->clearMousePressedListeners();
        frameObject->clearMouseDoubleClickedListeners();
        frameObject->clearPropertyChangedListeners();

        frameObject->addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (!this->isBinded(sender) || capturedZone != null) {
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
            rebind(sender);
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


        panelProperty = new PanelProperty(frameObject);
        panelTool->add(panelProperty);
        panelProperty
            ->setHorizontalAlignment(HorizontalAlignment::Stretch)
            ->setVerticalAlignment(VerticalAlignment::Bottom)
            ->setHeight(200);
        panelTool->pack();
        panelProperty->build();

    }

    void Controllers::bind(ArrayList<FrameObject*> frameObjects) {
        clearBind();

        for (auto frameObject : frameObjects) {
            controls.push_back(new Control(frameObject, editorSpace));
            addDragAndDropActions(frameObject);
        }
        

        panelProperty = new PanelProperty(frameObjects);
        panelTool->add(panelProperty);
        panelProperty
            ->setHorizontalAlignment(HorizontalAlignment::Stretch)
            ->setVerticalAlignment(VerticalAlignment::Bottom)
            ->setHeight(200);
        panelTool->pack();
        panelProperty->build();
    }

    void Controllers::clearBind() {
        delete dynamicTextField;
        dynamicTextField = null;
        delete panelProperty;
        panelProperty = null;
        for (auto ob : controls) {
            delete ob;
        }
        controls.clear();
    }

    Controllers::~Controllers() {}


}