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

        this->hWindow = CreateWindowEx(/*WS_EX_LAYERED*/0,
                                className,
                                title,
                                WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZE/*WS_OVERLAPPEDWINDOW*/ /*| WS_CLIPCHILDREN*/,
                                x, y,
                                width + 16, height + 39,
                                hWnd,
                                nullptr,
                                hInstance,
                                nullptr);


        /*if (this->hWindow == null) {
            throw L"Error in creating window";
        }*/
        //nativeWindowMap[*(this->hWindow)] = this;
        //int transparency = 255;
        //SetLayeredWindowAttributes(this->hWindow, 0, transparency, LWA_ALPHA);
        /*int transparency = 100;
        long extstyle = ::GetWindowLong(*(this->hWindow), GWL_EXSTYLE);
        ::SetWindowLong(*(this->hWindow), GWL_EXSTYLE, extstyle | WS_EX_LAYERED);
        ::SetLayeredWindowAttributes(*(this->hWindow), 0, transparency, LWA_ALPHA);*/
    }


    LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        /*if (message == WM_CREATE || message == WM_GETMINMAXINFO || message == WM_NCCREATE || message == WM_NCCALCSIZE) {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }*/
        return DefWindowProc(hWnd, message, wParam, lParam);;
    }

    void NativeWindow::registerClass() {
        WNDCLASSEXW wcex;

        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WindowProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hInstance;
        wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_METAWRAPPERWINAPI));
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
        //wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_METAWRAPPERWINAPI);
        wcex.lpszMenuName = null;
        wcex.lpszClassName = className;
        wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

        RegisterClassEx(&wcex);
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