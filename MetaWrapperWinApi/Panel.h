#pragma once

#include "NativePanel.h"

namespace MetaFrame {

    class Panel : public NativePanel {
    public:
        Panel() {};

    protected:
        virtual AbstructFrameElement *copy() const {
            Panel *ret = new Panel(*this);
            this->clearChilds();
            return ret;
        }

        void runActionEvents() {
            //for (auto &f : actionEventFunctions) f();
        }

    public:
        ADD_SET_OF_SETTERS(Panel);
        ~Panel() {};
    };


}

