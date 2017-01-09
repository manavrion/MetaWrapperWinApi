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
                //IDC_OF_BUTTON = i;
                break;
            } else {
                i++;
            }
        }


        hWindow = CreateWindow(L"button",
                               text,
                               WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
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

        SendMessage(hWindow, WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);

    }

}