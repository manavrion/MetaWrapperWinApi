#pragma once
#include "Point.h"

namespace MetaFrame {

    struct Color {
        Color() : red(0), green(0), blue(0), alpha(255) {}
        Color(byte red, byte green, byte blue) : red(red), green(green), blue(blue), alpha(255) {}
        Color(byte red, byte green, byte blue, byte alpha) : red(red), green(green), blue(blue), alpha(alpha) {}
        Color(const Color &color) : red(color.red), green(color.green), blue(color.blue), alpha(color.alpha) {}

        Color(unsigned long argb) : red(byte(argb >> 16)), green(byte(argb >> 8)), blue(byte(argb >> 0)), alpha(byte(argb >> 24)) {}

        byte red;
        byte green;
        byte blue;
        byte alpha;

        bool operator==(const Color &color) const {
            return (red == color.red) && (green == color.green) && (blue == color.blue) && (alpha == color.alpha);
        }

        bool operator!=(const Color &color) const {
            return (red != color.red) || (green != color.green) || (blue != color.blue) || (alpha != color.alpha);
        }

        //platform
        operator const COLORREF() const {
            return RGB(red, green, blue);
        }

        //platform
        /*operator const Gdiplus::Color() const {
            return Gdiplus::Color(alpha, red, green, blue);
        }*/

        /*enum {
            Aqua = 0xFF00FFFF,
            Black = 0xFF000000,
            Blue = 0xFF0000FF,
            Green = 0xFF00FF00,
            Cyan = 0xFF00FFFF,
            Fuchsia = 0xFFFF00FF,
            Lime = 0xFF00FF00,
            Magenta = 0xFFFF00FF,
            Red = 0xFFFF0000,
            Transparent = 0x00FFFFFF,
            White = 0xFFFFFFFF,
            Yellow = 0xFFFFFF00,
        };*/

        static const Color Green;
        static const Color Red;
        static const Color Blue;
        static const Color White;

    };
    
}