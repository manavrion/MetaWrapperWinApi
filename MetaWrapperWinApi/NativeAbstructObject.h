#pragma once
#include <memory>
#include "AbstructFrameElement.h"

namespace MetaFrame {

    class NativeAbstructObject : public AbstructFrameElement {

    public:
        NativeAbstructObject(const String className) :
            hWindow(new HWND), className(className),
            dwExStyle(), dwStyle()
        {

        };


    protected:

        virtual void nativeCopy(AbstructFrameElement *nw, const AbstructFrameElement &old) const {
            ((NativeAbstructObject*)nw)->hWindow.reset();
            ((NativeAbstructObject*)nw)->hWindow = ((const NativeAbstructObject*)&old)->hWindow;
        };

        void initializationEvent(const AbstructFrameElement *parent) {
            if (parent != null) {
                init(*(((const NativeAbstructObject*)parent)->hWindow));
            } else {
                init(null);
            }
        };
        virtual void init(HWND hWnd) = 0;

        bool wmCommand(WPARAM wParam, LPARAM lParam) {
            HWND hwndTarget = (HWND)lParam;
            //bfs
            Queue<NativeAbstructObject*> q;
            q.push(this);

            while (!q.empty()) {
                NativeAbstructObject *cur = q.front();
                q.pop();
                if (*(cur->hWindow) == hwndTarget) {
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



        /* resize methods */
        void nativeSetRect(Rect &rect) {
            if (hWindow != null) {
                MoveWindow(*hWindow, rect.x, rect.y, rect.width, rect.height, true);
            }
        }





    protected:
        std::shared_ptr<HWND> hWindow;
        //HWND hWnd;
        String className;

        //options
        DWORD dwExStyle;
        DWORD dwStyle;



    public:
        ~NativeAbstructObject() {
            if (hWindow.use_count() == 1) {
                //DestroyWindow(*hWindow);
                //CloseHandle(*hWindow);
            }
            
        };
    };

}