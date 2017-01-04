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




        ~Window() {};
    };

}