#pragma once


namespace MetaFrame {
    typedef char byte;
    struct Color {
        Color() : red(0), green(0), blue(0), alpha(255) {}
        Color(byte red, byte green, byte blue) : red(red), green(green), blue(blue), alpha(255) {}
        Color(byte red, byte green, byte blue, byte alpha) : red(red), green(green), blue(blue), alpha(alpha) {}
        Color(const Color &color) : red(color.red), green(color.green), blue(color.blue), alpha(color.alpha) {}

        byte red;
        byte green;
        byte blue;
        byte alpha;

        bool operator==(const Color &color) const {
            return (red == color.red) && (green == color.green) && (blue == color.blue) && (alpha == color.alpha);
        }

        //platform
        /*operator const Gdiplus::Color() const {
            return Gdiplus::Color(alpha, red, green, blue);
        }*/

    };

}