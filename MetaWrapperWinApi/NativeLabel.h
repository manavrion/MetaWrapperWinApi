#pragma once

#include "NativeAbstructObject.h"

namespace MetaFrame {

    class NativeLabel : public NativeAbstructObject {
    public:
        NativeLabel()
            : NativeAbstructObject(L"button") 
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;

            style = WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SS_NOTIFY;
            className = L"static";
        };

    protected:

        void nativeSetCenter() {
            this->style = SS_CENTER;
        };

        virtual void init(HWND hWnd);


        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;



    public:
        ~NativeLabel() {};
    };



}