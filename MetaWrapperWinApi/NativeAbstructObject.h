#pragma once
#include <memory>
#include <Windowsx.h>
#include <functional>
#include "FrameObject.h"


namespace MetaFrame {

    class NativeAbstructObject : public FrameObject {

    public:
        NativeAbstructObject(DWORD extendedStyle,
                             const String &className,
                             DWORD style) :
            extendedStyle(extendedStyle),
            className(className),
            style(style),
            hbrBkgnd(null),
            hWindow(null),
            mousePos()
        {

        };

        NativeAbstructObject(const String &className, DWORD style) :
            extendedStyle(0),
            className(className),
            style(style),
            hbrBkgnd(null),
            hWindow(null),
            mousePos() 
        {

        };

    protected:
        Point mouseOldPos;
        /* FrameObject declared methods */

        virtual void nativeSetRect(const Rect &rect) override {
            if (!nativeIsInitialzed()) return;
            MoveWindow(hWindow, rect.x, rect.y, rect.width, rect.height, true);
            //SetWindowPos(hWindow, null,rect.x, rect.y, rect.width, rect.height, false);
        }

        virtual void nativeSetBackground(const Color &background) override {
            if (hbrBkgnd != null) {
                DeleteObject(hbrBkgnd);
            }
            hbrBkgnd = CreateSolidBrush(background);

            if (!nativeIsInitialzed()) return;
            SetClassLong(hWindow, GCLP_HBRBACKGROUND, (INT_PTR)hbrBkgnd);
            InvalidateRect(hWindow, NULL, true);
        }

        virtual void nativeSetForeground(const Color &background) override {
            if (!nativeIsInitialzed()) return;
            //todo
        }

        virtual void nativeSetText(const String &text) override {
            if (!nativeIsInitialzed()) return;
            SendMessage(hWindow, WM_SETTEXT, 0, (LPARAM)text.c_str());
        };

        virtual String nativeGetText() const override {
            if (!nativeIsInitialzed()) return String();

            wchar *buf = new wchar[1024 * 16];
            SendMessage(hWindow, WM_GETTEXT, 1024 * 16, (LPARAM)buf);
            String s(buf);
            delete buf;
            return s;
        }

        virtual void nativeSetBorder(Border border) override {
            style &= ~WS_BORDER;
            extendedStyle &= ~WS_EX_STATICEDGE;
            extendedStyle &= ~WS_EX_CLIENTEDGE;
            switch (border) {
                case MetaFrame::Border::NO_BORDER:
                    break;
                case MetaFrame::Border::BORDER:
                    style |= WS_BORDER;
                    break;
                case MetaFrame::Border::SOFT_BEVEL:
                    extendedStyle |= WS_EX_STATICEDGE; //WS_EX_STATICEDGE - Создает окно с трехмерным стилем рамки, предполагается использовать для элементов, которые не принимают вводимую информацию от пользователя.
                    break;
                case MetaFrame::Border::BEVEL: //WS_EX_CLIENTEDGE - Определяет, что окно имеет рамку с углубленным краем.
                    extendedStyle |= WS_EX_CLIENTEDGE;
                    break;
                default:
                    break;
            }

        }

        void nativeSetTransparent(byte transparent)  override {
            if (!nativeIsInitialzed()) return;
        };


        virtual bool nativeIsInitialzed() const override {
            if (hWindow == null) {
                return false;
            } else {
                return true;
            }
        };
        
        void nativeInit(FrameObject *parent) override {
            if (nativeIsInitialzed()) {
                return;
            }
            if (parent != null) {
                createWindow((((const NativeAbstructObject*)parent)->hWindow));
            } else {
                createWindow(null);
            }
            bindWindowProc();
            //nativeSetBackground();
            if (hbrBkgnd != null) {
                SetClassLong(hWindow, GCLP_HBRBACKGROUND, (INT_PTR)hbrBkgnd);
                InvalidateRect(hWindow, NULL, true);
            }
        };

        void nativeDestroy() override {
            if (!nativeIsInitialzed()) return;

            DestroyWindow(hWindow);
            if (hbrBkgnd != null) {
                DeleteObject(hbrBkgnd);
            }
            
            //((NativeAbstructObject*)parent)->nativeRepaint();
        }

        void nativeRepaint() {
            if (!nativeIsInitialzed()) return;
            InvalidateRect(hWindow, NULL, true);
        }
        







        virtual void createWindow(HWND hParentWindow) {
            if (transparent != 255) {
                extendedStyle |= WS_EX_LAYERED;
            }
            hWindow = CreateWindowExW(
            /*_In_ DWORD dwExStyle,         */ extendedStyle,
            /*_In_opt_ LPCWSTR lpClassName, */ className,
            /*_In_opt_ LPCWSTR lpWindowName,*/ text,
            /*_In_ DWORD dwStyle,           */ style,
            /*_In_ int X,                   */ x,
            /*_In_ int Y,                   */ y,
            /*_In_ int nWidth,              */ width,
            /*_In_ int nHeight,             */ height,
            /*_In_opt_ HWND hWndParent,     */ hParentWindow,
            /*_In_opt_ HMENU hMenu,         */ 0,
            /*_In_opt_ HINSTANCE hInstance, */ GetModuleHandle(0),
            /*_In_opt_ LPVOID lpParam);     */ 0);

            //setting standart font
            NONCLIENTMETRICS ncm;
            ncm.cbSize = sizeof(NONCLIENTMETRICS);
            UINT uiParam = sizeof(NONCLIENTMETRICS);
            SystemParametersInfo(SPI_GETNONCLIENTMETRICS, uiParam, &ncm, 0);

            SendMessage(hWindow, WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);

            if (transparent != 255) {
                //SetLayeredWindowAttributes(hWindow, 0, transparent, LWA_ALPHA);

                long extstyle = GetWindowLong(hWindow, GWL_EXSTYLE);
                SetWindowLong(hWindow, GWL_EXSTYLE, extstyle | WS_EX_LAYERED);
                SetLayeredWindowAttributes(hWindow, 0, transparent, LWA_ALPHA);
            }
        }

        virtual void bindWindowProc();





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




        friend LRESULT CALLBACK nativeAbstructWindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

        virtual LRESULT nativeWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);;


    protected:

        DWORD extendedStyle;

        String className;

        DWORD style;

        HBRUSH hbrBkgnd;
        
        HWND hWindow;

        Point mousePos;


    protected:
        virtual ~NativeAbstructObject();
    };


    
}