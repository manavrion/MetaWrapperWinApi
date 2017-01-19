#pragma once

#include "NativeWindow.h"

namespace MetaFrame {

    class Window : public NativeWindow {

    public:
        Window(String name) : NativeWindow(name) {

        };


        void run() {
            pack();
            build();
            NativeWindow::run();
        }


    public:
        ADD_SET_OF_SETTERS(Window);
        virtual ~Window() {};
    };

}