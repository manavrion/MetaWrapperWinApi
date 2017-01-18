#pragma once

namespace MetaFrame {

    struct MouseEventInfo {
        MouseEventInfo(int x, int y)
            : x(x), y(y),
            xOnParent(x), yOnParent(y),
            dx(), dy()

        {}
        int x;
        int y;
        int xOnParent;
        int yOnParent;
        int dx;
        int dy;
        bool isCtrlPressed = false;
    };

}