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


    public:
        ADD_SET_OF_SETTERS(Label);

        virtual ~Label() {};
    };

}
