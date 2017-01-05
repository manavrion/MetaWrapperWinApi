#pragma once
#include <functional>
#include "AbstructFrameObject.h"
#include "NativeButton.h"

namespace MetaFrame {

    typedef std::function<void()> ButtonFunction;

    class Button : public NativeButton {
    public:
        Button() {};




        Button &addActionListener(ButtonFunction buttonFunction) {
            actionEventFunctions.push_back(buttonFunction);
            return *this;
        }

    protected:
        virtual AbstructFrameElement *copy() const {
            return new Button(*this);
        }

        ArrayList<ButtonFunction> actionEventFunctions;

        void runActionEvents() {
            for (auto &f : actionEventFunctions) f();
        }


    public:
        ADD_SET_OF_SETTERS(Button);

        ~Button() {};
    };

}