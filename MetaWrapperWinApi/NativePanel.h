#pragma once

#include "NativeAbstructObject.h"
#include <Winuser.h>
namespace MetaFrame {

    class NativePanel : public NativeAbstructObject {
    public:
        NativePanel()
            : NativeAbstructObject(L"static") {
            x = 10;
            y = 10;
            width = 73;
            height = 21;

            className = L"static";
            style = SS_CENTER | SS_CENTERIMAGE | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SS_NOTIFY;

            nativeSetBorder(Border::BORDER);
        };

        DWORD extendedStyleBorder = 0;
        DWORD styleBorder = 0;
        

        void nativeSetBorderText(const String &text) {


        }


    protected:




        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;


    public:


        ~NativePanel() {};
    };

}