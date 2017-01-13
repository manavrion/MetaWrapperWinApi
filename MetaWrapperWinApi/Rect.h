#pragma once
#include "Point.h"
#include "Size.h"

//todo rewrite
namespace MetaFrame {
    struct Rect {
        Rect() : x(0), y(0), width(0), height(0) {}
        Rect(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
        Rect(const Point& location, const Size& size) : x(location.x), y(location.y), width(size.width), height(size.height) {}

        explicit Rect(const Size& size) : x(), y(), width(size.width), height(size.height) {}

        
        Rect(const Rect &a, const Rect &b) {
            int right = min(a.getRightPos(), b.getRightPos());
            int bottom = min(a.getBottomPos(), b.getBottomPos());
            int left = max(a.getLeftPos(), b.getLeftPos());
            int top = max(a.getTopPos(), b.getTopPos());
            this->x = left;
            this->y = top;
            this->width = max(right - left, 0);
            this->height = max(bottom - top, 0);
        }

        //platform
        Rect(RECT lprect) : x(lprect.left), y(lprect.top), width(lprect.right - x), height(lprect.bottom - y) {}

        int x;
        int y;
        int width;
        int height;

        Point getLocation() const {
            return Point(x, y);
        }
        Size getSize() const {
            return Size(width, height);
        }

        Rect getBounds() const {
            return *this;
        }
        int getLeftPos() const {
            return x;
        }
        int getTopPos() const {
            return y;
        }
        int getRightPos() const {
            return x + width;
        }
        int getBottomPos() const {
            return y + height;
        }


        void setSize(const Size &size) {
            this->width = size.width;
            this->height = size.height;
        }
        void setPoint(const Point &point) {
            x = point.x;
            y = point.y;
        }

        bool empty() const {
            return (width <= 0) || (height <= 0);
        }

        virtual bool contains(int x, int y) const {
            return (x >= this->x && x < this->x + this->width) &&
                (y >= this->y && y < this->y + this->height);
        }
        virtual bool contains(const Point& pt) const {
            return contains(pt.x, pt.y);
        }
        virtual bool contains(const PointF& pt) const {
            return (pt.x >= this->x && pt.x < this->x + this->width) &&
                (pt.y >= this->y && pt.y < this->y + this->height);
        }
        virtual bool contains(Rect& rect) const {
            return (x <= rect.x) && (rect.getRightPos() <= getRightPos()) &&
                (y <= rect.y) && (rect.getBottomPos() <= getBottomPos());
        }
        virtual void inflate(int dx, int dy) {
            x -= dx;
            y -= dy;
            width += 2 * dx;
            height += 2 * dy;
        }
        virtual void inflate(const Point& point) {
            inflate(point.x, point.y);
        }

        virtual bool intersect(const Rect& rect) const {
            const Rect &a = *this;
            const Rect &b = rect;
            Rect c;
            int right = min(a.getRightPos(), b.getRightPos());
            int bottom = min(a.getBottomPos(), b.getBottomPos());
            int left = max(a.getLeftPos(), b.getLeftPos());
            int top = max(a.getTopPos(), b.getTopPos());
            c.x = left;
            c.y = top;
            c.width = right - left;
            c.height = bottom - top;
            return !c.empty();
        }

        virtual void offset(const Point& point) {
            offset(point.x, point.y);
        }
        virtual void offset(int dx, int dy) {
            x += dx;
            y += dy;
        }

        virtual void shiftTo(Point point) {
            x += point.x;
            y += point.y;
        }


        friend bool operator==(const Rect &a, const Rect &b) {
            return (a.x == b.x) && (a.y == b.y) && (a.width == b.width) && (a.height == b.height);
        }

        friend bool operator!=(const Rect &a, const Rect &b) {
            return (a.x != b.x) || (a.y != b.y) || (a.width != b.width) || (a.height != b.height);
        }

        //platform
        /*operator const Gdiplus::Rect() const;
        explicit operator const Gdiplus::RectF() const;*/
        operator const RECT() const {
            RECT a;
            a.left = x;
            a.top = y;
            a.right = this->getRightPos();
            a.bottom = this->getBottomPos();
            return a;
        }
    };

}