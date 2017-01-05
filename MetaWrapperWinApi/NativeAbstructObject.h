#pragma once
#include "AbstructFrameElement.h"

namespace MetaFrame {

    class NativeAbstructObject : public AbstructFrameElement {

    public:
        NativeAbstructObject(const String className) :
            hWnd(), className(className)
        {

        };


    protected:

        void initializationEvent(const AbstructFrameElement *parent) {
            if (parent != null) {
                init(((const NativeAbstructObject*)parent)->hWnd);
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
                if (cur->hWnd == hwndTarget) {
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

    protected:
        HWND hWnd;
        String className;

    public:
        ~NativeAbstructObject() {

        };
    };

}