#pragma once

#include "Resource.h"
#include "NativeAbstructObject.h"
#include "Panel.h"
namespace MetaFrame {

    class NativeWindow : public NativeAbstructObject {
    public:
        NativeWindow(const String &name)
            : hInstance(GetModuleHandle(0)), title(name), NativeAbstructObject(name)
        {
            x = CW_USEDEFAULT;
            y = 0;
            width = CW_USEDEFAULT;
            height = 0;
            registerClass();
            
        };

        HWND getHWindow() {
            return hWindow;
        }

    protected:

        Panel panelbuf;

        void run() {
            
            int nCmdShow = 10;
            ShowWindow(hWindow, nCmdShow);
            UpdateWindow(hWindow);

            HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_METAWRAPPERWINAPI));
            MSG msg;
            // Main message loop:
            while (GetMessage(&msg, nullptr, 0, 0)) {
                if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
        }

    

        virtual void init(HWND hWnd);;

        HINSTANCE hInstance;
        String title;
        void registerClass();

        //static friend LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        //LRESULT windowProcLocal(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

        virtual LRESULT nativeWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
            switch (message) {
                case WM_SIZE:
                {
                    width = LOWORD(lParam);
                    height = HIWORD(lParam);
                    pack();
                    break;
                }
                /*case WM_ERASEBKGND: {
                    break;
                }*/
                case WM_PAINT:
                {

                    PAINTSTRUCT ps;
                    HDC hdc = BeginPaint(hWnd, &ps);
                    // TODO: Add any drawing code that uses hdc here...
                    EndPaint(hWnd, &ps);
                    break;
                }
                case WM_DESTROY:
                    PostQuitMessage(0);
                    break;
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
            return 0;
        };


        virtual void command(WPARAM wParam, LPARAM lParam) {

        };

    public:
        ~NativeWindow() {};
    };

}