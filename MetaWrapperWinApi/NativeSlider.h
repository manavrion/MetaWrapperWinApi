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

            className = TRACKBAR_CLASS;
            style = WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_ENABLESELRANGE;
        };

    protected:

        void nativeSetPos(int pos) {

        }
        void nativeSetMinMax(int minPos, int maxPos) {
            if (hWindow != null) {
                SendMessage(this->hWindow, TBM_SETRANGE,
                    (WPARAM)TRUE,                   // redraw flag 
                            (LPARAM)MAKELONG(minPos, maxPos));  // min. & max. positions
            }
        }

        int nativeGetPos() {
            if (hWindow != null) {
                return SendMessage(this->hWindow, TBM_GETPOS, 0, 0);
            } else {
                return 0;
            } 
        }




        
        virtual void createWindow(HWND hWnd) override {
            NativeAbstructObject::createWindow(hWnd);

            SendMessage(hWindow, TBM_SETRANGE,
                (WPARAM)TRUE,                   // redraw flag 
                        (LPARAM)MAKELONG(0, 500));  // min. & max. positions
        };


        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };





    public:
        virtual ~NativeSlider() {};
    };

}