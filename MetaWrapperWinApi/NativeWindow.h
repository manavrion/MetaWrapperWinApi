#pragma once

#include "Resource.h"
#include "NativeAbstructObject.h"

namespace MetaFrame {

    class NativeWindow : public NativeAbstructObject {
    public:
        NativeWindow(const String &name)
            : hInstance(GetModuleHandle(0)), title(name), NativeAbstructObject(name)
        {
            registerClass();
        };

        void run() {
            
            int nCmdShow = 10;
            ShowWindow(hWnd, nCmdShow);
            UpdateWindow(hWnd);

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
    protected:
        HINSTANCE hInstance;
        String title;
        void registerClass();

        static friend LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        LRESULT windowProcLocal(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    public:
        ~NativeWindow() {};
    };

}