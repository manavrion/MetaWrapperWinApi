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

        virtual void init(HWND hWnd) {

            this->hWnd = CreateWindow(className, title, WS_OVERLAPPEDWINDOW,
                                CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, hWnd, nullptr, hInstance, nullptr);
            if (!this->hWnd) {
                throw L"Error in creating window";
            }

        };
    protected:
        HINSTANCE hInstance;
        String title;
        void registerClass();

    public:
        ~NativeWindow() {};
    };

}