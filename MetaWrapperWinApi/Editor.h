#pragma once

#include "Window.h"
#include "Panel.h"
#include "EditorWrapped.h"

namespace MetaFrame {

    class Editor : public Window {

    public:
        Editor(String text);

        void createPanel();

        void createButton();

        void createSlider();

        void createLabel();

    protected:
        

        Panel *editorSpace;
        Panel *panelTool;        

    public:
        ~Editor();
    };



}