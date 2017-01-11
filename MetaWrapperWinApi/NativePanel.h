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
            style = WS_BORDER | SS_CENTER | SS_CENTERIMAGE | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SS_NOTIFY;


        };

        void nativeSetBorder(Border border) {
            switch (border) {
                case MetaFrame::Border::NO_BORDER:
                    extendedStyle = 0;
                    style = 0;
                    break;
                case MetaFrame::Border::BORDER:
                    extendedStyle = 0;
                    style = WS_BORDER;
                    break;
                case MetaFrame::Border::SOFT_BEVEL:
                    extendedStyle = WS_EX_STATICEDGE; //WS_EX_STATICEDGE - Создает окно с трехмерным стилем рамки, предполагается использовать для элементов, которые не принимают вводимую информацию от пользователя.
                    style = 0;
                    break;
                case MetaFrame::Border::BEVEL: //WS_EX_CLIENTEDGE - Определяет, что окно имеет рамку с углубленным краем.
                    extendedStyle = WS_EX_CLIENTEDGE;
                    style = 0;
                    break;
                default:
                    break;
            }
            
        }

        void nativeSetBorderText(const String &text) {


        }


    protected:

        virtual void init(HWND hWnd);


        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;


    public:


        ~NativePanel() {};
    };

}