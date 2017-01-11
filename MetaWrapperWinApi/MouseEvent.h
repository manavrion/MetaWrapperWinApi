#pragma once

namespace MetaFrame {

    struct MouseEventInfo {
        MouseEventInfo(int x, int y)
            : x(x), y(y),
            xOnParent(x), yOnParent(y) {}
        int x;
        int y;
        int xOnParent;
        int yOnParent;
    };

}