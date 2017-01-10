#pragma once
#include <memory>
#include <Windowsx.h>
#include <functional>
#include "AbstructFrameElement.h"

namespace MetaFrame {

#define WM_UPDATETHREADADD (WM_USER + 1) 

    class NativeAbstructObject;

    typedef std::function<void(NativeAbstructObject&, const MouseEvent&)> MouseFunction;

    class NativeAbstructObject : public AbstructFrameElement {

    public:
        NativeAbstructObject(const String className) :
            hWindow(NULL), className(className),
            dwExStyle(), dwStyle(),
            hbrBkgnd(null)
        {

        };

        void invalidateRect() {
            InvalidateRect(hWindow, NULL, true);
        }

    protected:

        void wmClose(){
            DestroyWindow(hWindow);
            ((NativeAbstructObject*)parent)->invalidateRect();
        }

        /*virtual void nativeCopy(AbstructFrameElement *nw, const AbstructFrameElement &old) const {
            ((NativeAbstructObject*)nw)->hWindow.reset();
            ((NativeAbstructObject*)nw)->hWindow = ((const NativeAbstructObject*)&old)->hWindow;
        };*/

        void initializationEvent(const AbstructFrameElement *parent) {
            if (parent != null) {
                init((((const NativeAbstructObject*)parent)->hWindow));
            } else {
                init(null);
            }
            postInit();
            //nativeSetBackground();
            if (hbrBkgnd != null) {
                SetClassLong(hWindow, GCLP_HBRBACKGROUND, (INT_PTR)hbrBkgnd);
                InvalidateRect(hWindow, NULL, true);
            }
        };
        virtual void init(HWND hWnd) = 0;
        virtual void postInit();

        bool wmCommand(WPARAM wParam, LPARAM lParam) {
            HWND hwndTarget = (HWND)lParam;
            //bfs
            Queue<NativeAbstructObject*> q;
            q.push(this);

            while (!q.empty()) {
                NativeAbstructObject *cur = q.front();
                q.pop();
                if (cur->hWindow == hwndTarget) {
                    cur->command(wParam, lParam);
                    return true;
                }
                for (auto &obj : cur->childs) {
                    q.push((NativeAbstructObject*)obj);
                }
            }
            return false;
        };
        virtual void command(WPARAM wParam, LPARAM lParam) = 0;


        bool wmNotify(WPARAM wParam, LPARAM lParam) {
            //NMHDR *pnmhdr = (NMHDR *)lParam;
            //HWND hWndCtrl = pnmhdr->hwndFrom;
            /*NMHDR *pnmhdr = (NMHDR *)lParam;
            UINT uiCtrlID = pnmhdr->idFrom; //
            HWND hWndCtrl = pnmhdr->hwndFrom; // */

            HWND hwndTarget = (HWND)lParam;
            //bfs
            Queue<NativeAbstructObject*> q;
            q.push(this);

            while (!q.empty()) {
                NativeAbstructObject *cur = q.front();
                q.pop();
                if (cur->hWindow == hwndTarget) {
                    cur->command(wParam, lParam);
                    return true;
                }
                for (auto &obj : cur->childs) {
                    q.push((NativeAbstructObject*)obj);
                }
            }
            return false;
        };


        /* AbstructFrameObject declared methods */
        virtual void nativeSetRect(Rect &rect) override {
            if (hWindow != null) {
                MoveWindow(hWindow, rect.x, rect.y, rect.width, rect.height, true);
                //SetWindowPos(*hWindow, null,rect.x, rect.y, rect.width, rect.height, false);
            }
        }


        virtual void nativeSetBackground(const Color &background) override {
            DeleteObject(hbrBkgnd);
            hbrBkgnd = CreateSolidBrush(background);
            if (hWindow != null) {
                SetClassLong(hWindow, GCLP_HBRBACKGROUND, (INT_PTR)hbrBkgnd);
                InvalidateRect(hWindow, NULL, true);
            }
        }

        virtual void nativeSetForeground(const Color &background) override {
            //todo
        }

        virtual void nativeSetText(const String &text) override {
            SendMessage(hWindow, WM_SETTEXT, 0, (LPARAM)text.c_str());

        };

        virtual String nativeGetText() override {
            wchar *buf = new wchar[1024*16];
            SendMessage(hWindow, WM_GETTEXT, 1024 * 16, (LPARAM)buf);
            String s(buf);
            delete buf;
            return s;
        }




        friend static LRESULT CALLBACK nativeAbstructWindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

        virtual LRESULT nativeWindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) = 0;

    protected:
        HWND hWindow;
        //HWND hWnd;
        String className;

        //options
        DWORD dwExStyle;
        DWORD dwStyle;

        HBRUSH hbrBkgnd;


        void wmUpd() override {
            SendMessage(hWindow, WM_UPDATETHREADADD, 0, 0);
        }
        


    public:
        /*
        NativeAbstructObject *addKeyPressedListener(KeyFunction f);
        NativeAbstructObject *addKeyReleasedListener(KeyFunction f);
        NativeAbstructObject *addKeyTypedListener(KeyFunction f);
        NativeAbstructObject *addMouseDoubleClickedListener(MouseFunction f);
        NativeAbstructObject *addMouseEnteredListener(MouseFunction f);
        NativeAbstructObject *addMouseExitedListener(MouseFunction f);*/
        NativeAbstructObject *addMousePressedListener(MouseFunction f) {
            mousePressedEvents.push_back(f);
            return this;
        };
        NativeAbstructObject *addMouseReleasedListener(MouseFunction f) {
            mouseReleasedEvents.push_back(f);
            return this;
        };
        NativeAbstructObject *addMouseDraggedListener(MouseFunction f) {
            mouseDraggedEvents.push_back(f);
            return this;
        };
        NativeAbstructObject *addMouseMovedListener(MouseFunction f) {
            mouseMovedEvents.push_back(f);
            return this;
        };
        //NativeAbstructObject *addMouseWheelMovedListener(MouseFunction f);

    protected:
        /*ArrayList<KeyFunction>   keyPressedEvents;
        ArrayList<KeyFunction>   keyReleasedEvents;
        ArrayList<KeyFunction>   keyTypedEvents;*/

        //ArrayList<MouseFunction> mouseDoubleClickedEvents;
        //ArrayList<MouseFunction> mouseEnteredEvents;
        //ArrayList<MouseFunction> mouseExitedEvents;
        ArrayList<MouseFunction> mousePressedEvents;
        ArrayList<MouseFunction> mouseReleasedEvents;

        ArrayList<MouseFunction> mouseDraggedEvents;
        ArrayList<MouseFunction> mouseMovedEvents;

        //ArrayList<MouseFunction> mouseWheelMovedEvents;

        /*void runKeyPressedEvent(const KeyEvent &event);
        void runKeyReleasedEvent(const KeyEvent &event);
        void runKeyTypedEvent(const KeyEvent &event);

        void runMouseDoubleClickedEvent(MouseEvent event);*/

        /*void runMouseEnteredEvent(MouseEvent event);
        void runMouseExitedEvent(MouseEvent event);*/

        void runMousePressedEvent(MouseEvent event) {
            for (auto &func : mousePressedEvents) {
                func(*this, event);
            }
        };
        void runMouseReleasedEvent(MouseEvent event) {
            for (auto &func : mouseReleasedEvents) {
                func(*this, event);
            }
        };
        void runMouseDraggedEvent(MouseEvent event){
            for (auto &func : mouseDraggedEvents) {
                func(*this, event);
            }
        };
        void runMouseMovedEvent(MouseEvent event) {
            for (auto &func : mouseMovedEvents) {
                func(*this, event);
            }
        };
        //void runMouseWheelMovedEvent(MouseEvent event);



    public:
        ~NativeAbstructObject() {
            if (hWindow != null) {
                DestroyWindow(hWindow);
                DeleteObject(hbrBkgnd);
                //CloseHandle(*hWindow);
            }
            
        };
    };
    extern HashMap<HWND, Pair<NativeAbstructObject*, WNDPROC>> nativeAbstructObject;

    LRESULT CALLBACK nativeAbstructWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        if (message == WM_HSCROLL && nativeAbstructObject.count(hWnd) != 0) {
            nativeAbstructObject[hWnd].first->wmNotify(wParam, lParam);
        }
        if (message == WM_UPDATETHREADADD && nativeAbstructObject.count(hWnd) != 0) {
            //nativeAbstructObject[hWnd].first->
            nativeAbstructObject[hWnd].first->buildFix();
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

        if(message == WM_LBUTTONDOWN && nativeAbstructObject.count(hWnd) != 0) {
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