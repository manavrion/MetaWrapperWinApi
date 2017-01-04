#include "stdafx.h"
#include "NativeButton.h"
#include <set>

namespace MetaFrame {
    std::set<int> ids;

    void NativeButton::init(HWND hWnd) {
        int i = 1;
        while (true) {
            if (ids.count(i) == 0) {
                ids.insert(i);
                IDC_OF_BUTTON = i;
                break;
            } else {
                i++;
            }
        }

        this->hWnd = CreateWindow(L"button", L"Text",
                                  WS_CHILD | WS_VISIBLE, 10, 10, 100, 100, hWnd, (HMENU)i, GetModuleHandle(0), NULL);
    }

}