#pragma once
#include "NativeCheckBox.h"

namespace MetaFrame {

    class CheckBox;
    typedef std::function<void(CheckBox &sender)> CheckBoxFunctionSender;

    class CheckBox : public NativeCheckBox {
    public:
        CheckBox() {};



        CheckBox *setState(bool state) {
            nativeSetState(state);
            return this;
        }
        bool getState() {
            return nativeGetState();
        }





    public:
        ADD_SET_OF_SETTERS(CheckBox);
        ~CheckBox() {};
    };


}
