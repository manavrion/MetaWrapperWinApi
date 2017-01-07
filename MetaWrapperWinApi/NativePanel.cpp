#include "stdafx.h"
#include "NativePanel.h"


namespace MetaFrame {

    void NativePanel::init(HWND hWnd) {

        *(this->hWindow) = CreateWindowExW(0 | dwExStyle,
                                           L"static",
                                           text,
                                           WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | dwStyle | SS_NOTIFY,
                                           x, y,
                                           width, height,
                                           hWnd,
                                           (HMENU)NULL,
                                           GetModuleHandle(0),
                                           (LPVOID)NULL);

        /**(this->hWindow) = CreateWindowExW(0,
                                           L"static",
                                           L"",
                                            WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | SS_NOTIFY,
                                           x, y,
                                           width, height,
                                           hWnd,
                                           (HMENU)NULL,
                                           GetModuleHandle(0),
                                           (LPVOID)NULL);
        
        
        HWND tmohWnd =    CreateWindowExW(0 ,
                                             L"button",
                                             text,
                                             WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | BS_GROUPBOX ,
                                             0, 0,
                                             width, height,
                                            *(this->hWindow),
                                             (HMENU)NULL,
                                             GetModuleHandle(0),
                                             (LPVOID)NULL);*/




        //setting standart font
        NONCLIENTMETRICS ncm;
        ncm.cbSize = sizeof(NONCLIENTMETRICS);
        UINT uiParam = sizeof(NONCLIENTMETRICS);
        SystemParametersInfo(SPI_GETNONCLIENTMETRICS, uiParam, &ncm, 0);

        SendMessage(*(this->hWindow), WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);
        //SendMessage(tmohWnd, WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);
    }

}