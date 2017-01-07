#include "stdafx.h"
#include "NativeAbstructObject.h"

namespace MetaFrame {


    static HashMap<HWND, Pair<NativeAbstructObject*, WNDPROC>> nativeAbstructObject;



    static LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
        if (Message == WM_CTLCOLORSTATIC && nativeAbstructObject.count(hwnd) != 0) {

            /*if (nativeAbstructObject[hwnd].first->hbrBkgnd != null) {
                SetClassLong(hwnd, GCLP_HBRBACKGROUND, (INT_PTR)nativeAbstructObject[hwnd].first->hbrBkgnd);
                //UpdateWindow(hwnd);
                //InvalidateRect(hwnd, NULL, true);
                //SetBkColor((HDC)wParam, nativeAbstructObject[hwnd].first->buf);
                return CallWindowProc(nativeAbstructObject[hwnd].second, hwnd, Message, wParam, lParam);
            } else {
                return CallWindowProc(nativeAbstructObject[hwnd].second, hwnd, Message, wParam, lParam);
            }*/

            //nativeAbstructObject[hwnd].first->wmCommand(wParam, lParam);
            //SetBkColor((HDC)wParam, RGB(13, 13, 255));
            /*PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            SetBkColor(hdc, RGB(13, 13, 255));
            EndPaint(hwnd, &ps);
            return CallWindowProc(nativeAbstructObject[hwnd].second, hwnd, Message, wParam, lParam);*/
            
        }
        /*if (Message == WM_COMMAND && nativeAbstructObject.count(hwnd) != 0) {
            nativeAbstructObject[hwnd].first->wmCommand(wParam, lParam);
        }*/
        return CallWindowProc(nativeAbstructObject[hwnd].second, hwnd, Message, wParam, lParam);
    }

    void NativeAbstructObject::postInit() {
        nativeAbstructObject[*(this->hWindow)] = { this, (WNDPROC)SetWindowLong(*(this->hWindow), GWL_WNDPROC, (LONG)WndProc) };
    }

}

