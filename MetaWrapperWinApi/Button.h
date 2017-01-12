#pragma once
#include <functional>
#include "FrameObject.h"
#include "NativeButton.h"

namespace MetaFrame {

    class Button;
    typedef std::function<void()> ButtonFunctionVoid;
    typedef std::function<void(Button &sender)> ButtonFunctionSender;

    class Button : public NativeButton {
    public:
        Button() {};



    public:
        ADD_SET_OF_SETTERS(Button);

        ~Button() {};
    };

}