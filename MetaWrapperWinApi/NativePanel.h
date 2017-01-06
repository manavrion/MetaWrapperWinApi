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

            dwExStyle = 0;
            dwStyle = WS_BORDER;
        };


        void nativeSetBorder(Border border) {
            switch (border) {
                case MetaFrame::Border::NO_BORDER:
                    dwExStyle = 0;
                    dwStyle = 0;
                    break;
                case MetaFrame::Border::BORDER:
                    dwExStyle = 0;
                    dwStyle = WS_BORDER;
                    break;
                case MetaFrame::Border::SOFT_BEVEL:
                    dwExStyle = WS_EX_STATICEDGE; //WS_EX_STATICEDGE - Создает окно с трехмерным стилем рамки, предполагается использовать для элементов, которые не принимают вводимую информацию от пользователя.
                    dwStyle = 0;
                    break;
                case MetaFrame::Border::BEVEL: //WS_EX_CLIENTEDGE - Определяет, что окно имеет рамку с углубленным краем.
                    dwExStyle = WS_EX_CLIENTEDGE;
                    dwStyle = 0;
                    break;
                default:
                    break;
            }
            
        }

    protected:

        virtual void init(HWND hWnd) {

            *(this->hWindow) = CreateWindowExW(0 | dwExStyle,
                                     L"static",
                                     text,
                                     WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | dwStyle /* | SS_SUNKEN | WS_BORDER*/,
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