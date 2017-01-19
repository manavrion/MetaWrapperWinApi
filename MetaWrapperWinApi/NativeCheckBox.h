#pragma once

#include "NativeAbstructObject.h"

namespace MetaFrame {


    class NativeCheckBox : public NativeAbstructObject {
    public:
        NativeCheckBox()
            : NativeAbstructObject(L"button",
              BS_AUTOCHECKBOX | WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON) 
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;            
        };

    protected:

        void nativeSetState(bool state) {
            SendMessage(hWindow, BM_SETCHECK, state, 0);
        }

        bool nativeGetState() {
            return (int)SendMessage(hWindow, BM_GETCHECK, 0, 0);
        }

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };





    public:
        virtual ~NativeCheckBox() {};
    };


}