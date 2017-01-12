#pragma once

#include "Window.h"
#include "Panel.h"
#include "EditorWrapped.h"
//#include "Controllers.h"

namespace MetaFrame {

    class Editor : public Window {

    public:
        Editor(String text);

        void createPanel();

        void createButton();

        void createSlider();

        void createLabel();

        //void destroyControl();
    protected:


        Panel *editorSpace;
        Panel *panelTool;

        //void rebind(Rect rect, FrameNode *element);


        

    public:
        ~Editor();
    };



}