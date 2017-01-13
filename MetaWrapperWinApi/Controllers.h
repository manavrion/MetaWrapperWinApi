#pragma once

#include "Panel.h"
#include "TextField.h"
#include "Label.h"
#include "Editor.h"

#include "PropertyMenu.h"

namespace MetaFrame {

    class Control {
    public:
        Control(FrameObject *captured, Panel *editorSpace);

        bool isCaptured(FrameObject *captured) {
            if (this->captured == captured) {
                return true;
            } else {
                return false;
            }
        }

        void updatePosition();
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





    class Controllers {
    public:
        Controllers(Editor *editor, Panel *editorSpace, Panel *panelTool);

    protected:
        Editor *editor;
        Panel *editorSpace;
        Panel *panelTool;

        Panel *capturedZone = null;
        Point *capturedPoint = new Point;

        ArrayList<Control*> controls;


        PanelProperty *panelProperty = null;

        TextField *dynamicTextField = null;

        bool isBinded(FrameObject *frameObject) {
            for (auto ob : controls) {
                if (ob->isCaptured(frameObject)) {
                    return true;
                }
            }
            return false;
        }

    public:

        void addDragAndDropActions(FrameObject *frameObject);


        void rebind(FrameObject *frameObject);

        void bind(ArrayList<FrameObject> objects);

        void clearBind();


    public:
        ~Controllers();
    };

}