#pragma once

#include "NativeAbstructObject.h"

namespace MetaFrame {


    class NativeTextField : public NativeAbstructObject {
    public:
        NativeTextField()
            : NativeAbstructObject(L"button") 
        {
            x = 10;
            y = 10;
            width = 73;
            height = 15;

            className = L"edit";
            style = ES_AUTOHSCROLL | WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
        };



    protected:
        bool flagWritable = true;



        void nativeSetPageUp() {
            while (SendMessage(this->hWindow, EM_SCROLL, SB_PAGEUP, 0)) {

            }
        }

        void nativeSetPageDown() {
            while (SendMessage(this->hWindow, EM_SCROLL, SB_PAGEDOWN, 0)) {

            }
        }

        
        void nativeSetWritable(bool flagWritable) {
            if (!flagWritable) {
                SendMessage(this->hWindow, EM_SETREADONLY, TRUE, 0);
            } else {
                SendMessage(this->hWindow, EM_SETREADONLY, FALSE, 0);
            }
            this->flagWritable = flagWritable;
        };

        void nativeSetMultiLine(bool flag) {
            if (flag) {
                this->style |= ES_MULTILINE | ES_AUTOVSCROLL ;
            } else {
                this->style |= 0;
            }
        };



        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;



    public:
        ~NativeTextField() {};
    };

}