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



    public:
        ADD_SET_OF_SETTERS(TextField);
        ~TextField() {};
    };

}