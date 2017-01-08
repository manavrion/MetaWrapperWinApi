#pragma once
#include <functional>
#include "AbstructFrameObject.h"
#include "NativeButton.h"

namespace MetaFrame {

    class Button;
    typedef std::function<void()> ButtonFunctionVoid;
    typedef std::function<void(Button &sender)> ButtonFunctionSender;

    class Button : public NativeButton {
    public:
        Button() {};




        Button *addActionListener(ButtonFunctionVoid buttonFunction) {
            actionEventFunctionsVoid.push_back(buttonFunction); return this;
        }
        Button *addActionListener(ButtonFunctionSender buttonFunction) {
            actionEventFunctionsSender.push_back(buttonFunction); return this;
        }

    protected:
        /*virtual AbstructFrameElement *copy() const {
            Button *ret = new Button(*this);
            this->clearChilds();
            return ret;
        }*/

        ArrayList<ButtonFunctionVoid> actionEventFunctionsVoid;
        ArrayList<ButtonFunctionSender> actionEventFunctionsSender;

        void runActionEvents() {
            for (auto &f : actionEventFunctionsVoid) f();
            for (auto &f : actionEventFunctionsSender) f(*this);
        }


    public:
        ADD_SET_OF_SETTERS(Button);

        ~Button() {};
    };

}