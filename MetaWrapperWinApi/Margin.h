#pragma once

namespace MetaFrame {

    struct Margin {
        int left;
        int right;
        int top;
        int bottom;
        Margin(int left,
               int right,
               int top,
               int bottom) :
            left(left),
            right(right),
            top(top),
            bottom(bottom) {};
        Margin() :
            left(0),
            right(0),
            top(0),
            bottom(0) {};
    };

}