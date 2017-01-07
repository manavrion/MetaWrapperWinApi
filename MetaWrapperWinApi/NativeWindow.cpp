#include "stdafx.h"
#include "NativeWindow.h"
#include <queue>
#include <memory>
namespace MetaFrame {

    /*static HashMap<HWND, NativeWindow*> nativeWindowMap;

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        if (message == WM_CREATE || message == WM_GETMINMAXINFO || message == WM_NCCREATE || message == WM_NCCALCSIZE) {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        return nativeWindowMap[hWnd]->windowProcLocal(hWnd, message, wParam, lParam);
    }*/

    void NativeWindow::init(HWND hWnd) {

        *(this->hWindow) = CreateWindowEx(WS_EX_LAYERED,
                                className,
                                title,
                                WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
                                x, y,
                                width + 16, height + 39,
                                hWnd,
                                nullptr,
                                hInstance,
                                nullptr);


        if (!*(this->hWindow)) {
            throw L"Error in creating window";
        }
        //nativeWindowMap[*(this->hWindow)] = this;
        int transparency = 255;
        SetLayeredWindowAttributes(*(this->hWindow), 0, transparency, LWA_ALPHA);
        /*int transparency = 100;
        long extstyle = ::GetWindowLong(*(this->hWindow), GWL_EXSTYLE);
        ::SetWindowLong(*(this->hWindow), GWL_EXSTYLE, extstyle | WS_EX_LAYERED);
        ::SetLayeredWindowAttributes(*(this->hWindow), 0, transparency, LWA_ALPHA);*/
    }

    /*
    LRESULT NativeWindow::windowProcLocal(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        switch (message) {
            case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                // TODO: Add any drawing code that uses hdc here...
                EndPaint(hWnd, &ps);
            }
            break;
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }*/

}