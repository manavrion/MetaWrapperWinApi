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
                                      WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | SS_CENTERIMAGE | SS_SUNKEN,
                                      x, y,
                                      width, height,
                                      hWnd,
                                      (HMENU)i,
                                      GetModuleHandle(0),
                                      NULL);*/

            //WS_EX_CLIENTEDGE - Определяет, что окно имеет рамку с углубленным краем.
            //WS_EX_DLGMODALFRAME - Создает окно, которое имеет двойную рамку; окно может быть создано (необязательно) со строкой заголовка, которую определяет стиль WS_CAPTION в параметре dwStyle.
            //WS_EX_WINDOWEDGE - Определяет, что окно имеет рамку с выпуклым краем.
            //WS_EX_STATICEDGE - Создает окно с трехмерным стилем рамки, предполагается использовать для элементов, которые не принимают вводимую информацию от пользователя.

            /*static WNDCLASSEX wndclass;

            GetClassInfoEx(GetModuleHandle(0), L"static", &wndclass);

            wndclass.*/


            *(this->hWindow) = CreateWindowEx(0,
                                     L"static",
                                     text,
                                     WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | WS_BORDER /* | SS_SUNKEN | WS_BORDER*/,
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