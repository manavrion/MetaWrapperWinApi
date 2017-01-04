#include "stdafx.h"
#include "NativeButton.h"
#include <set>


std::set<int> ids;

inline void NativeButton::init(HWND hWnd) {

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
                              WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, x, y, width, height, hWnd, (HMENU)i, GetModuleHandle(0), NULL);
}
