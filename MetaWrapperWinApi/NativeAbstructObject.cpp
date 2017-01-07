#include "stdafx.h"
#include "NativeAbstructObject.h"

namespace MetaFrame {


    static HashMap<HWND, Pair<NativeAbstructObject*, WNDPROC>> nativeAbstructObject;



    static LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
        /*if (Message == WM_COMMAND && nativeAbstructObject.count(hwnd) != 0) {
            nativeAbstructObject[hwnd].first->wmCommand(wParam, lParam);
        }*/
        return CallWindowProc(nativeAbstructObject[hwnd].second, hwnd, Message, wParam, lParam);
    }

    void NativeAbstructObject::postInit() {
        nativeAbstructObject[*(this->hWindow)] = { this, (WNDPROC)SetWindowLong(*(this->hWindow), GWL_WNDPROC, (LONG)WndProc) };
    }

}

