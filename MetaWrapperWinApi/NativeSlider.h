#pragma once
#include <CommCtrl.h>
#include "NativeAbstructObject.h"

namespace MetaFrame {

    class NativeSlider : public NativeAbstructObject {
    public:
        NativeSlider()
            : NativeAbstructObject(L"button") 
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;
        };

    protected:

        void nativeSetPos(int pos) {

        }
        void nativeSetMinMax(int minPos, int maxPos) {
            if (*(this->hWindow) != null) {
            SendMessage(*(this->hWindow), TBM_SETRANGE,
                (WPARAM)TRUE,                   // redraw flag 
                        (LPARAM)MAKELONG(minPos, maxPos));  // min. & max. positions
            }
        }

        int nativeGetPos() {
            if (*(this->hWindow) != null) {
                return SendMessage(*(this->hWindow), TBM_GETPOS, 0, 0);
            } else {
                return 0;
            } 
        }





        virtual void init(HWND hWnd) override {
            int i = 6;

            *(this->hWindow) = CreateWindowEx(
                0,                               // no extended styles 
                TRACKBAR_CLASS,                  // class name 
                L"Trackbar Control",              // title (caption) 
                WS_CHILD |
                WS_VISIBLE |
                TBS_AUTOTICKS |
                TBS_ENABLESELRANGE,// style 
                x, y,                          // position 
                width, height,                         // size 
                hWnd,                         // parent window 
                (HMENU)i,                     // control identifier 
                GetModuleHandle(0),                         // instance 
                NULL                             // no WM_CREATE parameter 
            );;

            SendMessage(*(this->hWindow), TBM_SETRANGE,
                (WPARAM)TRUE,                   // redraw flag 
                        (LPARAM)MAKELONG(0, 25));  // min. & max. positions

            SendMessage(*(this->hWindow), TBM_SETPAGESIZE,
                        0, (LPARAM)1);                  // new page size

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
        ~NativeSlider() {};
    };

}