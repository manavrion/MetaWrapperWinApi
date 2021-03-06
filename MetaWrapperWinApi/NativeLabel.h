#pragma once

#include "NativeAbstructObject.h"

namespace MetaFrame {

    class NativeLabel : public NativeAbstructObject {
    public:
        NativeLabel()
            : NativeAbstructObject(L"static",
              WS_CLIPCHILDREN | WS_CHILD | WS_VISIBLE | SS_NOTIFY) 
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;
        };

    protected:

        void nativeSetCenter() {
            this->style |= SS_CENTER;
        };


    public:
        virtual ~NativeLabel() {};
    };



}