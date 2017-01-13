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
            capturedZone->setSize(Size());
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
                rebind(captiredElements);
            }
            


        });

    }


    void Controllers::addListenersToElement(FrameObject *frameObject) {

        //frameObject->clearAllListeners();
        
        frameObject->addMousePressedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (!isBinded(sender)) {
                rebind(sender);
            }            
        });

        static Point pnt;

        frameObject->addMouseReleasedListener([&](FrameObject *sender, const MouseEventInfo &event) {
            pnt = Point(0, 0);
        });

        frameObject->addMouseDraggedListener([&](FrameObject *sender, const MouseEventInfo &event) {
            if (!isBinded(sender) || capturedZone != null) {
                return;
            }
            if (pnt == Point(0, 0)) {
                pnt = Point(event.xOnParent, event.yOnParent);
                return;
            }      

            for (auto &ob : controls) {
                ob->captured->setX(ob->captured->getX() - (pnt.x - event.xOnParent));
                ob->captured->setY(ob->captured->getY() - (pnt.y - event.yOnParent));
                //ob->updatePosition();
            }
            editorSpace->repaint();
            sender->repaint();
            pnt = Point(event.xOnParent, event.yOnParent);
        });

        frameObject->addMouseDoubleClickedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            rebind(sender);

            delete dynamicTextField;
            dynamicTextField = new TextField();

            dynamicTextField->setText(sender->getText());

            editorSpace->add(dynamicTextField
                             ->setPosition(sender->getX(), sender->getY() - 20)
                             ->addActionListener([=](TextField *tf) {
                                sender->setText(tf->getText());
                             })
            );

            editorSpace->build();
        });

        frameObject->addPropertyChangedListener([=](FrameObject *sender) {
            if (dynamicTextField != null) {
                dynamicTextField->setText(sender->getText());
            }
        });

    }


    void Controllers::rebind(FrameObject * frameObject) {
        rebind(ArrayList<FrameObject*>({ frameObject }));
    }


    void Controllers::rebind(ArrayList<FrameObject*> frameObjects) {
        clearBind();

        for (auto frameObject : frameObjects) {
            controls.push_back(new Control(frameObject, editorSpace, &controls));
            addListenersToElement(frameObject);
        }        

        panelProperty = new PanelProperty(&controls);
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