#pragma once

#include "NativeTextField.h"

namespace MetaFrame {

    class TextField;
    typedef std::function<void(TextField &sender)> TextFieldFunctionSender;

    class TextField : public NativeTextField {
    public:
        TextField() {};

        TextField *setPageUp() {
            nativeSetPageUp();
            return this;
        }

        TextField *setPageDown() {
            nativeSetPageDown();
            return this;
        }


        TextField *setWritable(bool flag) {
            nativeSetWritable(flag);
            return this;
        }

        TextField *setMultiLine(bool flag) {
            nativeSetMultiLine(flag);
            return this;
        }



        TextField *addActionListener(TextFieldFunctionSender buttonFunction) {
            actionEventFunctionsSender.push_back(buttonFunction); return this;
        }

    protected:
        /*virtual AbstructFrameElement *copy() const {
            TextField *ret = new TextField(*this);
            this->clearChilds();
            return ret;
        }*/

        ArrayList<TextFieldFunctionSender> actionEventFunctionsSender;


        void runActionEvents() {
            for (auto &f : actionEventFunctionsSender) f(*this);
        }

    public:
        ADD_SET_OF_SETTERS(TextField);
        ~TextField() {};
    };

}