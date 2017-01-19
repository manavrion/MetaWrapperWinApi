#pragma once

#include "NativeAbstructObject.h"
#include <Winuser.h>
namespace MetaFrame {

    class NativePanel : public NativeAbstructObject {
    public:
        NativePanel()
            : NativeAbstructObject(L"static", 
              SS_CENTER | SS_CENTERIMAGE | WS_CHILD | WS_VISIBLE | SS_NOTIFY) 
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;
            nativeSetBorder(Border::BORDER);
        };


        virtual ~NativePanel() {};
    };

}