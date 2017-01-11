#pragma once

#include "NativeAbstructObject.h"

namespace MetaFrame {


    class NativeCheckBox : public NativeAbstructObject {
    public:
        NativeCheckBox()
            : NativeAbstructObject(L"button") 
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;

            className = L"button";
            style = BS_AUTOCHECKBOX | WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
        };

    protected:

        void nativeSetState(bool state) {
            SendMessage(hWindow, BM_SETCHECK, state, 0);
        }

        bool nativeGetState() {
            return (int)SendMessage(hWindow, BM_GETCHECK, 0, 0);
        }


        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;



    public:
        ~NativeCheckBox() {};
    };


}