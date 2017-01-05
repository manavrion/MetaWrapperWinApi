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

        this->hWnd = CreateWindow(L"button", 
                                  text,
                                  WS_CHILD | WS_VISIBLE, 
                                  x, y, 
                                  width, height, 
                                  hWnd, 
                                  (HMENU)i, 
                                  GetModuleHandle(0), 
                                  NULL);

        //setting standart font
        NONCLIENTMETRICS ncm;
        ncm.cbSize = sizeof(NONCLIENTMETRICS);
        UINT uiParam = sizeof(NONCLIENTMETRICS);
        SystemParametersInfo(SPI_GETNONCLIENTMETRICS, uiParam, &ncm, 0);

        SendMessage(this->hWnd, WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);


        //SetWindowPos(this->hWnd, 0, x, y, 50, 14, 0);
        //MoveWindow(this->hWnd, x, y, 73, 21, false);

    }

}