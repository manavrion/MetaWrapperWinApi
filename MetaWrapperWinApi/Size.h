#pragma once

#include "Point.h"

namespace MetaFrame {

    struct Size {
        Size() : width(0), height(0) {}
        Size(const Size& size) : width(size.width), height(size.height) {}
        explicit Size(const Point& point) : width(point.x), height(point.y) {}
        Size(int width, int height) : width(width), height(height) {}

        int width;
        int height;

        Size operator+(const Size &sz) const {
            return Size(width + sz.width, height + sz.height);
        };
        Size operator-(const Size &sz) const {
            return Size(width - sz.width, height - sz.height);
        };
        bool operator==(const Size &sz) const {
            return (width == sz.width) && (height == sz.height);
        };
        bool empty() const {
            return (width == 0 && height == 0);
        };

        //platform
        /* operator const Gdiplus::Size() const {
        return Gdiplus::Size(width, height);
        }
        operator const Gdiplus::Rect() const {
        return Gdiplus::Rect(0, 0, width, height);
        };*/
    };

    struct SizeF {
        SizeF() : width(0.0), height(0.0) {}
        SizeF(const SizeF& size) : width(size.width), height(size.height) {}
        SizeF(const Size& size) : width(size.width), height(size.height) {}
        explicit SizeF(const PointF& point) : width(point.x), height(point.y) {}
        explicit SizeF(const Point& point) : width(point.x), height(point.y) {}
        SizeF(float width, float height) : width(width), height(height) {}

        float width;
        float height;

        explicit operator const Size() const {
            return Size(int(width), int(height));
        }

        SizeF operator+(const SizeF &sz) const {
            return SizeF(width + sz.width, height + sz.height);
        };
        SizeF operator-(const SizeF &sz) const {
            return SizeF(width - sz.width, height - sz.height);
        };
        bool operator==(const SizeF &sz) const {
            return (width == sz.width) && (height == sz.height);
        };
        bool empty() const {
            return (width == 0.0 && height == 0.0);
        };
    };
}