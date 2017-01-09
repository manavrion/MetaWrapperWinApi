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
                this->dwStyle = ES_MULTILINE | ES_AUTOVSCROLL ;
            } else {
                this->dwStyle = 0;
            }
        };

        virtual void init(HWND hWnd) override {
            int i = 1;


            hWindow = CreateWindow(L"edit",
                                            text,
                                            this->dwStyle | ES_AUTOHSCROLL | WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                            x, y,
                                            width, height,
                                            hWnd,
                                            (HMENU)i,
                                            GetModuleHandle(0),
                                            NULL);

            nativeSetWritable(flagWritable);

            //setting standart font
            NONCLIENTMETRICS ncm;
            ncm.cbSize = sizeof(NONCLIENTMETRICS);
            UINT uiParam = sizeof(NONCLIENTMETRICS);
            SystemParametersInfo(SPI_GETNONCLIENTMETRICS, uiParam, &ncm, 0);

            SendMessage(hWindow, WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);
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