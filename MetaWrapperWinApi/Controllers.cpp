#include "stdafx.h"
#include "Controllers.h"
namespace MetaFrame {

    Controllers::Controllers(Editor *editor, Panel *editorSpace, Panel *panelTool)
        : editor(editor), editorSpace(editorSpace), panelTool(panelTool)
    {

        
        editor->addMouseReleasedListener([=](FrameObject *panel, const MouseEventInfo &event) {
            clearBind();
            insertFrame = editorSpace;
        });


        insertFrame = editorSpace;

        editorSpace->addMouseReleasedListener([=](Panel *panel, const MouseEventInfo &event) {
            for (auto ob : editorSpace->getChilds()) {
                if (ob->getRect().contains(event.x, event.y)) {
                    return;
                }
            }
            clearBind();
            insertFrame = editorSpace;
            rebind(editorSpace);
        });

        /* capturedZone */
        capturedZone = null;
        editor->addMousePressedRecListener([=](FrameObject *panel, const MouseEventInfo &event) {
            if (event.isCtrlPressed == false) {
                return;
            }
            
            delete capturedZone;
            capturedZone = null;
            capturedZone = new Panel;
            capturedZone->setPosition(event.x, event.y);
            editor->add(capturedZone);
            capturedZone->setText(L"capture zone");
            capturedZone->setSize(Size());
            capturedZone->build();
            *capturedPoint = {event.x, event.y};
        });

        editor->addMouseDraggedRecListener([=](FrameObject *panel, const MouseEventInfo &event) {
            if (event.isCtrlPressed == false) {
                delete capturedZone;
                capturedZone = null;
                return;
            }
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

        editor->addMouseReleasedRecListener([=](FrameObject *panel, const MouseEventInfo &event) {
            Rect rect;

            if (capturedZone != null) {
                rect = capturedZone->getRect();
                delete capturedZone;
                capturedZone = null;
            } else {
                return;
            }
            if (event.isCtrlPressed == false) {
                return;
            }
            
            clearBind();

            ArrayList<FrameObject*> captiredElements;


            Queue<FrameObject*> q;

            q.push(editorSpace);

            while (!q.empty()) {

                FrameObject *obj = q.front();
                q.pop();

                if (rect.contains(obj->getRect())) {
                    captiredElements.push_back(obj);
                }

                for (auto ob : obj->getChilds()) {
                    q.push(ob);
                }

            }
            

            if (!captiredElements.empty()) {
                rebind(captiredElements);
            }           


        });


        /*deleting elements*/
        editor->addKeyTypedListener([=](FrameObject *sender, const KeyEvent &event) {
            if (event.code == KeyCodes::KEY_DELETE) {

                for (auto ob : controls) {
                    if (editorSpace != ob->captured) {
                        delete ob->captured;
                    }
                    delete ob;
                }
                controls.clear();

                clearBind();
            }
        });

    }


    void Controllers::addListenersToElement(FrameObject *frameObject) {
        
        frameObject->addMousePressedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            if (event.isCtrlPressed == true) {
                return;
            }
            if (!isBinded(sender)) {
                rebind(sender);
            }           
        });


        frameObject->addMouseDraggedListener([&](FrameObject *sender, const MouseEventInfo &event) {  
            if (!isBinded(sender) || capturedZone != null) {
                return;
            }
            for (auto &ob : controls) {
                ob->captured->setX(ob->captured->getX() - event.dx);
                ob->captured->setY(ob->captured->getY() - event.dy);
            }
            editorSpace->repaint();
            sender->repaint();
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

    void Controllers::addListenersToInsert(FrameObject *frameObject) {
        frameObject->addMousePressedListener([=](FrameObject *sender, const MouseEventInfo &event) {
            insertFrame = frameObject;
        });        
    }


    void Controllers::rebind(FrameObject * frameObject) {
        rebind(ArrayList<FrameObject*>({ frameObject }));
    }


    void Controllers::rebind(ArrayList<FrameObject*> frameObjects) {
        clearBind();

        for (auto frameObject : frameObjects) {
            frameObject->clearAllListeners();
            controls.push_back(new Control(frameObject, insertFrame, &controls));
            addListenersToElement(frameObject);
        }    

        if (frameObjects.size() == 1) {
            addListenersToInsert(frameObjects.front());
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


        editorSpace->clearAllListeners();
        editorSpace->addMousePressedListener([=](Panel *panel, const MouseEventInfo &event) {
            if (event.isCtrlPressed == true) {
                return;
            }
            for (auto ob : editorSpace->getChilds()) {
                if (ob->getRect().contains(event.x, event.y)) {
                    return;
                }
            }
            clearBind();
            insertFrame = editor;
            rebind(editorSpace);
        });
    }


    Controllers::~Controllers() {}


}