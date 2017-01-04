#pragma once

#include "AbstructFrameObject.h"
#include "NativeButton.h"

namespace MetaFrame {

    class Button : public NativeButton {
    public:
        Button() {};




        ADD_SET_OF_SETTERS(Button);

        ~Button() {};
    };

}