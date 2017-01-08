#pragma once

#include "NativeWindow.h"

namespace MetaFrame {

    class Window : public NativeWindow {

    public:
        Window(String name) : NativeWindow(name) {

        };



        void run() {
            pack();
            build(null);
            NativeWindow::run();
        }

    protected:
        virtual AbstructFrameElement *copy() const {
            Window *ret = new Window(*this);
            this->clearChilds();
            return ret;
        }

    public:
        ADD_SET_OF_SETTERS(Window);
        ~Window() {};
    };

}