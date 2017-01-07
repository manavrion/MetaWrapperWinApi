#pragma once

#include "Alignment.h"
#include "Point.h"
#include "Rect.h"
#include "Size.h"
#include "Margin.h"

namespace MetaFrame {
    class AbstructFrameObject {
    public:
        AbstructFrameObject() :
            x(), y(),
            width(), height(),
            autoWidth(true), autoHeight(true),
            minWidth(0), maxWidth(0x7fffFFFF),
            minHeight(0), maxHeight(0x7fffFFFF),
            margin(),
            horizontalAlignment(HorizontalAlignment::Absolute),
            verticalAlignment(VerticalAlignment::Absolute),
            background(),
            foreground(),
            text()
        {};

    protected:
        /* fields */
        int x;//location in parent
        int y;//location in parent

        int width;
        int height;

        bool autoWidth;
        bool autoHeight;

        int minWidth;
        int maxWidth;
        int minHeight;
        int maxHeight;

        Margin margin;

        HorizontalAlignment horizontalAlignment;
        VerticalAlignment verticalAlignment;

        Color background;
        Color foreground;

        String text;

    public:


        virtual void nativeSetRect(Rect &rect) = 0;
        virtual void nativeSetBackground(const Color &rect) = 0;

        //setters
        virtual AbstructFrameObject &setRect(Rect rect) {
            x = rect.x;
            y = rect.y;
            width = rect.width;
            height = rect.height;
            nativeSetRect(rect);
            return *this;
        };

        virtual AbstructFrameObject &setX(int x) {
            this->x = x;
            nativeSetRect(Rect(x, y, width, height));
            return *this;
        };
        virtual AbstructFrameObject &setY(int y) {
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            return *this;
        };
        virtual AbstructFrameObject &setSize(Size size) {
            height = size.height;
            width = size.width;
            nativeSetRect(Rect(x, y, width, height));
            return *this;
        };
        virtual AbstructFrameObject &setWidth(int width) {
            this->width = width;
            nativeSetRect(Rect(x, y, width, height));
            return *this;
        };
        virtual AbstructFrameObject &setHeight(int height) {
            this->height = height;
            nativeSetRect(Rect(x, y, width, height));
            return *this;
        };
        virtual AbstructFrameObject &setAutoWidth(bool autoWidth) {
            this->autoWidth = autoWidth;
            return *this;
        };
        virtual AbstructFrameObject &setAutoHeight(bool autoHeight){
            this->autoHeight = autoHeight;
            return *this;
        };
        virtual AbstructFrameObject &setMinWidth(int minWidth){
            this->minWidth = minWidth;
            return *this;
        };
        virtual AbstructFrameObject &setMaxWidth(int maxWidth){
            this->maxWidth = maxWidth;
            return *this;
        };
        virtual AbstructFrameObject &setMinHeight(int minHeight){
            this->minHeight = minHeight;
            return *this;
        };
        virtual AbstructFrameObject &setMaxHeight(int maxHeight){
            this->maxHeight = maxHeight;
            return *this;
        };
                                 
        virtual AbstructFrameObject &setMargin(int left, int right, int top, int bottom) {
            this->margin = Margin(left, right, top, bottom);
            return *this;
        };
        virtual AbstructFrameObject &setMargin(Margin margin) {
            this->margin = margin;
            return *this;
        };
                                 
        virtual AbstructFrameObject &setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {
            this->horizontalAlignment = horizontalAlignment;
            return *this;
        };
        virtual AbstructFrameObject &setVerticalAlignment(VerticalAlignment verticalAlignment) {
            this->verticalAlignment = verticalAlignment;
            return *this;
        };

        virtual AbstructFrameObject &setBackground(const Color &background){
            this->background = background;
            nativeSetBackground(background);
            return *this;
        }
        virtual AbstructFrameObject &setForeground(const Color &foreground){
            this->foreground = foreground;
            return *this;
        }

        virtual AbstructFrameObject &setText(const String &text){
            this->text = text;
            return *this;
        }

        //getters
        int getX() {
            return x;
        };
        int getY() {
            return y;
        };

        Rect getRect() {
            return Rect(x, y, width, height);
        };

        int getWidth() {
            return width;
        };
        int getHeight() {
            return height;
        };

        Size getSize() {
            return Size(width, height);
        };
        bool getAutoWidth() {
            return autoWidth;
        };
        bool getAutoHeight() {
            return autoHeight;
        };
        int getMinWidth() {
            return minWidth;
        };
        int getMaxWidth() {
            return maxWidth;
        };
        int getMinHeight() {
            return minHeight;
        };
        int getMaxHeight() {
            return maxHeight;
        };

        Margin getMargin() {
            return margin;
        };

        HorizontalAlignment getHorizontalAlignment() {
            return horizontalAlignment;
        };
        VerticalAlignment getVerticalAlignment() {
            return verticalAlignment;
        };

        Color getBackground() {
            return background;
        }
        Color getForeground() {
            return foreground;
        }

        String getText() {
            return text;
        }

    public:
        ~AbstructFrameObject() {};

    };

    //big macro

#define ADD_SET_OF_SETTERS(FrameType) \
    virtual FrameType &setRect(Rect rect) {\
        AbstructFrameObject::setRect(rect);\
        return *this;\
    };\
\
    virtual FrameType &setX(int x) {\
        AbstructFrameObject::setX(x);\
        return *this;\
    };\
    virtual FrameType &setY(int y) {\
        AbstructFrameObject::setY(y);\
        return *this;\
    };\
    virtual FrameType &setSize(Size size) {\
        AbstructFrameObject::setSize(size);\
        return *this;\
    };\
    virtual FrameType &setWidth(int width) {\
        AbstructFrameObject::setWidth(width);\
        return *this;\
    };\
    virtual FrameType &setHeight(int height) {\
        AbstructFrameObject::setHeight(height);\
        return *this;\
    };\
    virtual FrameType &setAutoWidth(bool autoWidth) {\
        AbstructFrameObject::setAutoWidth(autoWidth);\
        return *this;\
    };\
    virtual FrameType &setAutoHeight(bool autoHeight) {\
        AbstructFrameObject::setAutoHeight(autoHeight);\
        return *this;\
    };\
    virtual FrameType &setMinWidth(int minWidth) {\
        AbstructFrameObject::setMinWidth(minWidth);\
        return *this;\
    };\
    virtual FrameType &setMaxWidth(int maxWidth) {\
        AbstructFrameObject::setMaxWidth(maxWidth);\
        return *this;\
    };\
    virtual FrameType &setMinHeight(int minHeight) {\
        AbstructFrameObject::setMinHeight(minHeight);\
        return *this;\
    };\
    virtual FrameType &setMaxHeight(int maxHeight) {\
        AbstructFrameObject::setMaxHeight(maxHeight);\
        return *this;\
    };\
\
    virtual FrameType &setMargin(int left, int right, int top, int bottom) {\
        AbstructFrameObject::setMargin(left, right, top, bottom);\
        return *this;\
    };\
    virtual FrameType &setMargin(Margin margin) {\
        AbstructFrameObject::setMargin(margin);\
        return *this;\
    };\
\
    virtual FrameType &setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {\
        AbstructFrameObject::setHorizontalAlignment(horizontalAlignment);\
        return *this;\
    };\
    virtual FrameType &setVerticalAlignment(VerticalAlignment verticalAlignment) {\
        AbstructFrameObject::setVerticalAlignment(verticalAlignment);\
        return *this;\
    };\
\
    virtual FrameType &setBackground(const Color &background) {\
        AbstructFrameObject::setBackground(background); \
        return *this;\
    }\
    virtual FrameType &setForeground(const Color &foreground) {\
        AbstructFrameObject::setForeground(foreground); \
        return *this;\
    }\
    virtual FrameType &setText(const String &text) {\
        AbstructFrameObject::setText(text); \
        return *this;\
    }


}