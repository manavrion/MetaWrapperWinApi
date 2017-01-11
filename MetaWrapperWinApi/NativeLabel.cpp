#include "stdafx.h"
#include "NativeLabel.h"


namespace MetaFrame {




    void NativeLabel::init(HWND hWnd) {
        int i = 3;

        /*hWindow = CreateWindow(L"static",
                                        text,
                                        this->style  | WS_CHILD | WS_VISIBLE,
                                        x, y,
                                        width, height,
                                        hWnd,
                                        (HMENU)i,
                                        GetModuleHandle(0),
                                        NULL);*/
        hWindow = CreateWindow(L"static",
                               text,
                               WS_BORDER | WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | style | SS_NOTIFY,
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

        SendMessage(this->hWindow, WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);

    }

}