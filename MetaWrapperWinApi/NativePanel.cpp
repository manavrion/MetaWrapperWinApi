#include "stdafx.h"
#include "NativePanel.h"


namespace MetaFrame {

    static HashMap<HWND, Pair<NativePanel*, WNDPROC>> nativePanel;

    LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
        if (Message == WM_COMMAND && nativePanel.count(hwnd) != 0){
            nativePanel[hwnd].first->wmCommand(wParam, lParam);
        }
        return CallWindowProc(nativePanel[hwnd].second, hwnd, Message, wParam, lParam);
    }

    void NativePanel::init(HWND hWnd) {

        *(this->hWindow) = CreateWindowExW(0 | dwExStyle,
                                           L"static",
                                           text,
                                           WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | dwStyle | SS_NOTIFY/* | SS_SUNKEN | WS_BORDER*/,
                                           x, y,
                                           width, height,
                                           hWnd,
                                           (HMENU)NULL,
                                           GetModuleHandle(0),
                                           (LPVOID)NULL);

        nativePanel[*(this->hWindow)] = {this, (WNDPROC)SetWindowLong(*(this->hWindow), GWL_WNDPROC, (LONG)WndProc) };


    }

}