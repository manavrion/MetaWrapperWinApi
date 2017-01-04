#pragma once

#include <math.h>

namespace MetaFrame {

    struct Point {
        Point() : x(0), y(0) {}
        Point(const Point &point) : x(point.x), y(point.y) {}
        Point(int x, int y) : x(x), y(y) {}

        int x;
        int y;

        Point &operator+=(const Point& point) {
            x += point.x;
            y += point.y;
            return *this;
        };
        Point &operator-=(const Point& point) {
            x -= point.x;
            y -= point.y;
            return *this;
        }

        Point operator-() const {
            return Point(-x, -y);
        };
        Point operator+() const {
            return Point(x, y);
        };

        //platform
        /*operator const Gdiplus::Point() const {
            return Gdiplus::Point(x, y);
        };*/
    };

    Point operator+(const Point &a, const Point &b) {
        return Point(a.x + b.x, a.y + b.y);
    };
    Point operator-(const Point &a, const Point &b) {
        return Point(a.x - b.x, a.y - b.y);
    };
    bool operator==(const Point &a, const Point &b) {
        return (a.x == b.x) && (a.y == b.y);
    };
    bool operator!=(const Point &a, const Point &b) {
        return !(a == b);
    };


    struct PointF {
        PointF() : x(), y() {}
        PointF(const PointF &pointF) : x(pointF.x), y(pointF.y) {}
        PointF(const Point &point) : x(point.x), y(point.y) {}
        PointF(float x, float y) : x(x), y(y) {}

        float x;
        float y;

        PointF &operator+=(const PointF& point) {
            x += point.x;
            y += point.y;
            return *this;
        };
        PointF &operator-=(const PointF& point) {
            x -= point.x;
            y -= point.y;
            return *this;
        }

        PointF operator-() const {
            return PointF(-x, -y);
        };
        PointF operator+() const {
            return PointF(x, y);
        };

        explicit operator const Point() const {
            return Point(int(x), int(y));
        }

        //platform
        /*operator const Gdiplus::PointF() const {
            return Gdiplus::PointF(x, y);
        };*/

    };

    PointF operator+(const PointF &a, const PointF &b) {
        return PointF(a.x + b.x, a.y + b.y);
    };
    PointF operator-(const PointF &a, const PointF &b) {
        return PointF(a.x - b.x, a.y - b.y);
    };
    bool operator==(const PointF &a, const PointF &b) {
        return (abs(a.x - b.x) < 0.00001) && (abs(a.y - b.y) < 0.00001);
    };
    bool operator!=(const PointF &a, const PointF &b) {
        return !(a == b);
    };

}