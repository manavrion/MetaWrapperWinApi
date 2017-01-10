#pragma once

namespace MetaFrame {

    struct MouseEvent {
        MouseEvent(int x, int y)
            : x(x), y(y),
            xOnScreen(xOnScreen), yOnScreen(yOnScreen) {}
        int x;
        int y;
        int xOnScreen;
        int yOnScreen;
    };

}