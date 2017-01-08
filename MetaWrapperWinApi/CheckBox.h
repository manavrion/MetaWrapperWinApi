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


        CheckBox *addActionListener(CheckBoxFunctionSender checkBoxFunction) {
            actionEventFunctionsSender.push_back(checkBoxFunction); return this;
        }

    protected:
        /*virtual AbstructFrameElement *copy() const {
            CheckBox *ret = new CheckBox(*this);
            this->clearChilds();
            return ret;
        }*/

        ArrayList<CheckBoxFunctionSender> actionEventFunctionsSender;

        void runActionEvents() override {
            for (auto &f : actionEventFunctionsSender) f(*this);;
        }


    public:
        ADD_SET_OF_SETTERS(CheckBox);
        ~CheckBox() {};
    };


}
