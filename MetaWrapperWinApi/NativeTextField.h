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
        };



    protected:

        virtual void init(HWND hWnd) override {
            int i = 1;


            *(this->hWindow) = CreateWindow(L"edit",
                                            text,
                                            ES_AUTOHSCROLL | WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
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
        ~NativeTextField() {};
    };

}