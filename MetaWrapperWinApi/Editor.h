#pragma once

#include "Window.h"
#include "Panel.h"
#include "EditorWrapped.h"




namespace MetaFrame {

    class Editor : public Window {

    public:
        Editor(String text);

        void createFrame(FrameObject *frameObject);

    protected:        

        Panel *editorSpace;
        Panel *panelTool;        


        void save();

        void load();

    public:
        ~Editor();
    };



}



