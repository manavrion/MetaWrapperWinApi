#pragma once

#include "NativeAbstructObject.h"

namespace MetaFrame {

    class NativePanel : public NativeAbstructObject {
    public:
        NativePanel()
            : NativeAbstructObject(L"button") {
            x = 10;
            y = 10;
            width = 73;
            height = 21;
        };


    protected:

        virtual void init(HWND hWnd) {
            int i = 2;
            /*this->hWnd = CreateWindow(L"static",
                                      L"panel",
                                      WS_CHILD | WS_VISIBLE | WS_BORDER,
                                      x, y,
                                      width, height,
                                      hWnd,
                                      (HMENU)i,
                                      GetModuleHandle(0),
                                      NULL);*/

            this->hWnd = CreateWindowEx(WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME, 
                                        _T("STATIC"), 
                                        _T("Panel 1"),
                                        WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | SS_SUNKEN, 
                                        x, y,
                                        width, height,
                                        hWnd, 
                                        (HMENU)NULL, 
                                        GetModuleHandle(0), 
                                        (LPVOID)NULL);


        };


        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;

    public:


        ~NativePanel() {};
    };

}