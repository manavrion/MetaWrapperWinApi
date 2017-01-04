#pragma once
#include "Resource.h"


class NativeWindow : public NativeAbstructObject {
public:
    NativeWindow() 
        : hInstance(GetModuleHandle(0))
    {
        registerClass();
    };

    void run() {
        hWnd = CreateWindow(L"MyWindow", L"My Window", WS_OVERLAPPEDWINDOW,
                                  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

        if (!hWnd) {
            throw L"Error in creating window";
        }
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

    virtual void add(NativeAbstructObject *nativeAbstructObject) {};

    virtual void init(HWND hWnd) {};
protected:
    HINSTANCE hInstance;
    virtual void registerClass();

public:
    ~NativeWindow() {};
};

