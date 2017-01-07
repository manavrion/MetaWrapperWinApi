#include "stdafx.h"
#include "NativePanel.h"


namespace MetaFrame {

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

        //setting standart font
        NONCLIENTMETRICS ncm;
        ncm.cbSize = sizeof(NONCLIENTMETRICS);
        UINT uiParam = sizeof(NONCLIENTMETRICS);
        SystemParametersInfo(SPI_GETNONCLIENTMETRICS, uiParam, &ncm, 0);

        SendMessage(*(this->hWindow), WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);
    }

}