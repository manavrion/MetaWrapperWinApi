#pragma once

#include "NativeWindow.h"

namespace MetaFrame {

    class Window : public NativeWindow {

    public:
        Window(String name) : NativeWindow(name) {

        };



        void run() {
            build(null);
            NativeWindow::run();
        }

    protected:
        virtual AbstructFrameElement *copy() const {
            return new Window(*this);
        }

    public:
        ADD_SET_OF_SETTERS(Window);
        ~Window() {};
    };

}