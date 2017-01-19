#include "stdafx.h"
#include "NativeAbstructObject.h"

#include "KeyEvent.h"

namespace MetaFrame {




    HashMap<HWND, Pair<NativeAbstructObject*, WNDPROC>> nativeAbstructObject;

    void NativeAbstructObject::bindWindowProc() {
        nativeAbstructObject[this->hWindow] = { this, (WNDPROC)SetWindowLong(hWindow, GWLP_WNDPROC, (LONG)nativeAbstructWindowProc) };
    }

    LRESULT NativeAbstructObject::nativeWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        //default
        return CallWindowProc(nativeAbstructObject[hWnd].second, hWnd, message, wParam, lParam);
    }

    NativeAbstructObject::~NativeAbstructObject() {
        DeleteBrush(brush);
        destroyImpl();
        nativeAbstructObject.erase(hWindow);
    }



    LRESULT CALLBACK nativeAbstructWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        if (message == WM_HSCROLL && nativeAbstructObject.count(hWnd) != 0) {
            nativeAbstructObject[hWnd].first->wmNotify(wParam, lParam);
        }
        if (message == WM_COMMAND && nativeAbstructObject.count(hWnd) != 0) {
            nativeAbstructObject[hWnd].first->wmCommand(wParam, lParam);
        }
        /*if (message == WM_NOTIFY && nativeAbstructObject.count(hWnd) != 0) {
        nativeAbstructObject[hWnd].first->wmCommand(wParam, lParam);
        }*/

        if (message == WM_MOUSEMOVE && nativeAbstructObject.count(hWnd) != 0) {
            MouseEventInfo event(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            event.xOnParent += nativeAbstructObject[hWnd].first->getX();
            event.yOnParent += nativeAbstructObject[hWnd].first->getY();
            if (wParam & MK_CONTROL) event.isCtrlPressed = true;
            /*        MouseEventInfo event(GET_X_LPARAM(eventInfo.lParam), GET_Y_LPARAM(eventInfo.lParam));
            if (eventInfo.wParam & MK_CONTROL) event.controlDown = true;
            if (eventInfo.wParam & MK_LBUTTON) event.leftButtonDown = true;
            if (eventInfo.wParam & MK_MBUTTON) event.midButtonDown = true;
            if (eventInfo.wParam & MK_RBUTTON) event.rightButtonDown = true;
            if (eventInfo.wParam & MK_SHIFT)   event.shiftDown = true;*/

            event.dx = nativeAbstructObject[hWnd].first->mousePos.x - event.xOnParent;
            event.dy = nativeAbstructObject[hWnd].first->mousePos.y - event.yOnParent;

            bool fl = true;
            if (nativeAbstructObject[hWnd].first->mousePos.x == 0 && nativeAbstructObject[hWnd].first->mousePos.y == 0) {
                fl = false;
            }

            if (wParam & MK_LBUTTON != 0 && fl) {
                nativeAbstructObject[hWnd].first->runMouseDraggedEvent(event);
            }
            //this->wmMouseEnter(event);
            //this->wmMouseExit(event);

            nativeAbstructObject[hWnd].first->runMouseMovedEvent(event);

            nativeAbstructObject[hWnd].first->mousePos = Point(event.xOnParent, event.yOnParent);
        }

        if (message == WM_LBUTTONDOWN && nativeAbstructObject.count(hWnd) != 0) {
            MouseEventInfo event(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            event.xOnParent += nativeAbstructObject[hWnd].first->getX();
            event.yOnParent += nativeAbstructObject[hWnd].first->getY();

            if (wParam & MK_CONTROL) event.isCtrlPressed = true;
            //alt todo
            //event.causedby = MouseButton::LEFT;
            nativeAbstructObject[hWnd].first->runMousePressedEvent(event);
            //return 0;
        }
        if (message == WM_LBUTTONUP && nativeAbstructObject.count(hWnd) != 0) {
            MouseEventInfo event(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            event.xOnParent += nativeAbstructObject[hWnd].first->getX();
            event.yOnParent += nativeAbstructObject[hWnd].first->getY();

            if (wParam & MK_CONTROL) event.isCtrlPressed = true;
            //alt todo
            //event.causedby = MouseButton::LEFT;
            nativeAbstructObject[hWnd].first->runMouseReleasedEvent(event);
            //return 0;
        }
        if ((message == WM_LBUTTONDBLCLK || message == WM_RBUTTONDBLCLK) && nativeAbstructObject.count(hWnd) != 0)
        {
            MouseEventInfo event(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            event.xOnParent += nativeAbstructObject[hWnd].first->getX();
            event.yOnParent += nativeAbstructObject[hWnd].first->getY();

            if (wParam & MK_CONTROL) event.isCtrlPressed = true;
            //alt todo
            //event.causedby = MouseButton::LEFT;
            nativeAbstructObject[hWnd].first->runMouseDoubleClickedEvent(event);
        }
        if ((message == WM_KEYDOWN || message == WM_RBUTTONDBLCLK) && nativeAbstructObject.count(hWnd) != 0)
        {
            KeyEvent event;
            event.code = KeyCodes(wParam); //Code

            BYTE lpKeyState[256];
            GetKeyboardState(lpKeyState);
            ToUnicode(wParam, HIWORD(lParam) & 0xFF, lpKeyState, &event.key, 1, 0);

            if (lParam && (0x1 << 30) == 0) {
                //this->wmKeyDown(event);
                nativeAbstructObject[hWnd].first->runKeyPressedEvent(event);
            }
            nativeAbstructObject[hWnd].first->runKeyTypedEvent(event);
            //this->wmKeyTyped(event);            
        }
        if ((message == WM_KEYUP || message == WM_RBUTTONDBLCLK) && nativeAbstructObject.count(hWnd) != 0)
        {
            KeyEvent event;
            event.code = KeyCodes(wParam); //Code

            BYTE lpKeyState[256];
            GetKeyboardState(lpKeyState);
            ToUnicode(wParam, HIWORD(lParam) & 0xFF, lpKeyState, &event.key, 1, 0);
            nativeAbstructObject[hWnd].first->runKeyReleasedEvent(event);
            //this->wmKeyUp(event);
        }
        /*if ((message >= 0x0132 && message <= 0x0138) && nativeAbstructObject.count(hWnd) != 0) {
            SetBkColor((HDC)wParam, (COLORREF)RGB(nativeAbstructObject[hWnd].first->background.red, nativeAbstructObject[hWnd].first->background.green, nativeAbstructObject[hWnd].first->background.blue));
            SetTextColor((HDC)wParam, (COLORREF)RGB(nativeAbstructObject[hWnd].first->foreground.red, nativeAbstructObject[hWnd].first->foreground.green, nativeAbstructObject[hWnd].first->foreground.blue));
            return (LRESULT)nativeAbstructObject[hWnd].first->brush;
        }*/
        if (nativeAbstructObject.count(hWnd) != 0) {
            return nativeAbstructObject[hWnd].first->nativeWindowProc(hWnd, message, wParam, lParam);
        }
        return CallWindowProc(nativeAbstructObject[hWnd].second, hWnd, message, wParam, lParam);
        //return DefWindowProc(hWnd, message, wParam, lParam);
    }



}

