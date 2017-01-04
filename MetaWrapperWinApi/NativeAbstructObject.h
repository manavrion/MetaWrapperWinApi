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
        
        void initializationEvent(AbstructFrameElement *parent) {
            if (parent != null) {
                init(((NativeAbstructObject*)parent)->hWnd);
            } else {
                init(null);
            }
        };
        virtual void init(HWND hWnd) = 0;

    protected:
        HWND hWnd;
        String className;

    public:
        ~NativeAbstructObject() {

        };
    };

}