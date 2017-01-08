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
        };

    protected:

        void nativeSetCenter() {
            this->dwStyle = SS_CENTER;
        };

        virtual void init(HWND hWnd) override;


        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;

        virtual LRESULT nativeWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override {
            return CallWindowProc(nativeAbstructObject[hWnd].second, hWnd, message, wParam, lParam);
        }

    public:
        ~NativeLabel() {};
    };



}