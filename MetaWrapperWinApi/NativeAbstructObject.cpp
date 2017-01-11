#include "stdafx.h"
#include "NativeAbstructObject.h"

namespace MetaFrame {

#define GWL_WNDPROC         (-4)



    HashMap<HWND, Pair<NativeAbstructObject*, WNDPROC>> nativeAbstructObject;

    void NativeAbstructObject::postInit() {
        nativeAbstructObject[this->hWindow] = { this, (WNDPROC)SetWindowLong(hWindow, GWL_WNDPROC, (LONG)nativeAbstructWindowProc) };
    }

    LRESULT NativeAbstructObject::nativeWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        //default
        return CallWindowProc(nativeAbstructObject[hWnd].second, hWnd, message, wParam, lParam);
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
            MouseEvent event(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            event.xOnParent += nativeAbstructObject[hWnd].first->getX();
            event.yOnParent += nativeAbstructObject[hWnd].first->getY();
            /*        MouseEvent event(GET_X_LPARAM(eventInfo.lParam), GET_Y_LPARAM(eventInfo.lParam));
            if (eventInfo.wParam & MK_CONTROL) event.controlDown = true;
            if (eventInfo.wParam & MK_LBUTTON) event.leftButtonDown = true;
            if (eventInfo.wParam & MK_MBUTTON) event.midButtonDown = true;
            if (eventInfo.wParam & MK_RBUTTON) event.rightButtonDown = true;
            if (eventInfo.wParam & MK_SHIFT)   event.shiftDown = true;*/




            if (wParam & MK_LBUTTON != 0) {
                nativeAbstructObject[hWnd].first->runMouseDraggedEvent(event);
            }
            //this->wmMouseEnter(event);
            //this->wmMouseExit(event);

            nativeAbstructObject[hWnd].first->runMouseMovedEvent(event);
            //this->wmMouseMove(event);
            //return 0;
        }

        if (message == WM_LBUTTONDOWN && nativeAbstructObject.count(hWnd) != 0) {
            MouseEvent event(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            event.xOnParent += nativeAbstructObject[hWnd].first->getX();
            event.yOnParent += nativeAbstructObject[hWnd].first->getY();
            //alt todo
            //event.causedby = MouseButton::LEFT;
            nativeAbstructObject[hWnd].first->runMousePressedEvent(event);
            //return 0;
        }
        if (message == WM_LBUTTONUP && nativeAbstructObject.count(hWnd) != 0) {
            MouseEvent event(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            event.xOnParent += nativeAbstructObject[hWnd].first->getX();
            event.yOnParent += nativeAbstructObject[hWnd].first->getY();
            //alt todo
            //event.causedby = MouseButton::LEFT;
            nativeAbstructObject[hWnd].first->runMouseReleasedEvent(event);
            //return 0;
        }
        if (nativeAbstructObject.count(hWnd) != 0) {
            return nativeAbstructObject[hWnd].first->nativeWindowProc(hWnd, message, wParam, lParam);
        }
        //return CallWindowProc(nativeAbstructObject[hwnd].second, hwnd, message, wParam, lParam);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }



}

