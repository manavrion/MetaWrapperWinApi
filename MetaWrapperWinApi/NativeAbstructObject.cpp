#include "stdafx.h"
#include "NativeAbstructObject.h"

namespace MetaFrame {

#define GWL_WNDPROC         (-4)
    HashMap<HWND, Pair<NativeAbstructObject*, WNDPROC>> nativeAbstructObject;

    void NativeAbstructObject::postInit() {
        nativeAbstructObject[this->hWindow] = { this, (WNDPROC)SetWindowLong(hWindow, GWL_WNDPROC, (LONG)nativeAbstructWindowProc) };
    }

}

