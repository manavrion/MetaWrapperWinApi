#pragma once

#include "Panel.h"
#include "TextField.h"
#include "Label.h"
#include "Editor.h"

#include "PropertyMenu.h"

#include "Control.h"

namespace MetaFrame {

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

        void addListenersToElement(FrameObject *frameObject);


        void rebind(FrameObject *frameObject);

        void rebind(ArrayList<FrameObject*> objects);

        void clearBind();


    public:
        ~Controllers();
    };

}