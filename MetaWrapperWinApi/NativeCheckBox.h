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
        };

    protected:

        void nativeSetState(bool state) {
            SendMessage(*(this->hWindow), BM_SETCHECK, state, 0);
        }

        bool nativeGetState() {
            return (int)SendMessage(*(this->hWindow), BM_GETCHECK, 0, 0);
        }





        virtual void init(HWND hWnd) override {
            int i = 4;

            *(this->hWindow) = CreateWindow(L"button",
                                            text,
                                            BS_AUTOCHECKBOX | WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                            x, y,
                                            width, height,
                                            hWnd,
                                            (HMENU)i,
                                            GetModuleHandle(0),
                                            NULL);

            //setting standart font
            NONCLIENTMETRICS ncm;
            ncm.cbSize = sizeof(NONCLIENTMETRICS);
            UINT uiParam = sizeof(NONCLIENTMETRICS);
            SystemParametersInfo(SPI_GETNONCLIENTMETRICS, uiParam, &ncm, 0);

            SendMessage(*(this->hWindow), WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);
        };


        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;

        virtual LRESULT nativeWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override {
            return CallWindowProc(nativeAbstructObject[hWnd].second, hWnd, message, wParam, lParam);
        }

    public:
        ~NativeCheckBox() {};
    };


}