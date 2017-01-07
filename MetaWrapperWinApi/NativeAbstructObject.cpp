#include "stdafx.h"
#include "NativeAbstructObject.h"

namespace MetaFrame {


    HashMap<HWND, Pair<NativeAbstructObject*, WNDPROC>> nativeAbstructObject;

    void NativeAbstructObject::postInit() {
        nativeAbstructObject[*(this->hWindow)] = { this, (WNDPROC)SetWindowLong(*(this->hWindow), GWL_WNDPROC, (LONG)nativeAbstructWindowProc) };
    }

}

