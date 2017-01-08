#pragma once

#include "NativeLabel.h"

namespace MetaFrame {

    class Label : public NativeLabel {
    public:
        Label() {};

        Label *setCenter() {
            nativeSetCenter();
            return this;
        }

    protected:

        void runActionEvents() {
        }

        

        /*virtual AbstructFrameElement *copy() const {
            Label *ret = new Label(*this);
            this->clearChilds();
            return ret;
        }*/

    public:
        ADD_SET_OF_SETTERS(Label);

        ~Label() {};
    };

}
