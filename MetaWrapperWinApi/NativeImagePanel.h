#pragma once

#include "NativeAbstructObject.h"
namespace MetaFrame {


    class NativeImagePanel : public NativeAbstructObject {
    public:
        NativeImagePanel(Image &image)
            : NativeAbstructObject(L"button"), image(image) 
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;

            className = L"static";
            style = WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SS_NOTIFY;
        };


    protected:

        Image &image;


        virtual void command(WPARAM wParam, LPARAM lParam) {
            runActionEvents();
        };




        virtual LRESULT nativeWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
            if (message == WM_PAINT) {

                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                StretchBlt(hdc, 0, 0, image.getSize().width, image.getSize().height, image.getHDC(), 0, 0, image.getSize().width,
                           image.getSize().height, SRCCOPY);
                DeleteDC(hdc);
                EndPaint(hWnd, &ps);

            }
            //return CallWindowProc(nativeAbstructObject[hWnd].second, hWnd, message, wParam, lParam);
            return 0;
        }

    public:


        ~NativeImagePanel() {};
    };



}