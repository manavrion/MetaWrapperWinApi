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
            x(10), y(10),
            width(73), height(21),
            autoWidth(false), autoHeight(false),
            minWidth(0), maxWidth(0x7fffFFFF),
            minHeight(0), maxHeight(0x7fffFFFF),
            margin(10, 10, 10, 10),
            horizontalAlignment(HorizontalAlignment::Absolute),
            verticalAlignment(VerticalAlignment::Absolute),
            background(),
            foreground(),
            text(),
            layout(Layout::Simple)
        {};

        AbstructFrameObject(const AbstructFrameObject &abstructFrameObject) = delete;

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

        Layout layout;

    protected:

        virtual void nativeSetRect(const Rect &rect) = 0;
        virtual void nativeSetBackground(const Color &rect) = 0;
        virtual void nativeSetForeground(const Color &rect) = 0;
        virtual void nativeSetText(const String &text) = 0;
        virtual String nativeGetText() const = 0;
        virtual bool nativeIsInitialzed() const = 0;


    public:

        //setters

        virtual AbstructFrameObject *setRect(Rect rect) {
            x = rect.x;
            y = rect.y;
            width = rect.width;
            height = rect.height;
            nativeSetRect(rect);
            return this;
        };
        virtual AbstructFrameObject *setRect(int x, int y, int width, int height) {
            this->width = width;
            this->height = height;
            this->x = x;
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };


        virtual AbstructFrameObject *setX(int x) {
            this->x = x;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };
        virtual AbstructFrameObject *setY(int y) {
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };
        virtual AbstructFrameObject *setPosition(int x, int y) {
            this->x = x;
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };
        virtual AbstructFrameObject *setPosition(Point point) {
            this->x = point.x;
            this->y = point.y;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };

        virtual AbstructFrameObject *setSize(Size size) {
            height = size.height;
            width = size.width;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };
        virtual AbstructFrameObject *setSize(int width, int height) {
            this->width = width;
            this->height = height;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };
        virtual AbstructFrameObject *setWidth(int width) {
            this->width = width;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };
        virtual AbstructFrameObject *setHeight(int height) {
            this->height = height;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };
        virtual AbstructFrameObject *setAutoWidth(bool autoWidth) {
            this->autoWidth = autoWidth;
            return this;
        };
        virtual AbstructFrameObject *setAutoHeight(bool autoHeight){
            this->autoHeight = autoHeight;
            return this;
        };
        virtual AbstructFrameObject *setMinWidth(int minWidth){
            this->minWidth = minWidth;
            return this;
        };
        virtual AbstructFrameObject *setMaxWidth(int maxWidth){
            this->maxWidth = maxWidth;
            return this;
        };
        virtual AbstructFrameObject *setMinHeight(int minHeight){
            this->minHeight = minHeight;
            return this;
        };
        virtual AbstructFrameObject *setMaxHeight(int maxHeight){
            this->maxHeight = maxHeight;
            return this;
        };
                                 
        virtual AbstructFrameObject *setMargin(int left, int right, int top, int bottom) {
            this->margin = Margin(left, right, top, bottom);
            return this;
        };
        virtual AbstructFrameObject *setMargin(Margin margin) {
            this->margin = margin;
            return this;
        };
                                 
        virtual AbstructFrameObject *setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {
            this->horizontalAlignment = horizontalAlignment;
            return this;
        };
        virtual AbstructFrameObject *setVerticalAlignment(VerticalAlignment verticalAlignment) {
            this->verticalAlignment = verticalAlignment;
            return this;
        };

        virtual AbstructFrameObject *setAlignment(Alignment alignment) {
            switch (alignment) {
                case MetaFrame::Alignment::Absolute:
                    verticalAlignment = VerticalAlignment::Absolute;
                    horizontalAlignment = HorizontalAlignment::Absolute;
                    break;
                case MetaFrame::Alignment::Center:
                    verticalAlignment = VerticalAlignment::Center;
                    horizontalAlignment = HorizontalAlignment::Center;
                    break;
                case MetaFrame::Alignment::Stretch:
                    autoWidth = true;
                    horizontalAlignment = HorizontalAlignment::Stretch;
                    autoHeight = true;
                    verticalAlignment = VerticalAlignment::Stretch;
                    break;
                default:
                    break;
            }
            return this;
        };

        virtual AbstructFrameObject *setBackground(const Color &background){
            this->background = background;
            nativeSetBackground(background);
            return this;
        }
        virtual AbstructFrameObject *setForeground(const Color &foreground){
            this->foreground = foreground;
            nativeSetForeground(foreground);
            return this;
        }

        virtual AbstructFrameObject *setText(const String &text){
            this->text = text;
            nativeSetText(text);
            return this;
        }

        virtual AbstructFrameObject *setLayout(Layout layout) {
            this->layout = layout;
            return this;
        }

        //getters
        int getX() const {
            return x;
        };
        int getY() const {
            return y;
        };

        Rect getRect() const {
            return Rect(x, y, width, height);
        };

        int getWidth() const {
            return width;
        };
        int getHeight() const {
            return height;
        };

        Size getSize() const {
            return Size(width, height);
        };
        bool getAutoWidth() const {
            return autoWidth;
        };
        bool getAutoHeight() const {
            return autoHeight;
        };
        int getMinWidth() const {
            return minWidth;
        };
        int getMaxWidth() const {
            return maxWidth;
        };
        int getMinHeight() const {
            return minHeight;
        };
        int getMaxHeight() const {
            return maxHeight;
        };

        Margin getMargin() const {
            return margin;
        };

        HorizontalAlignment getHorizontalAlignment() const {
            return horizontalAlignment;
        };
        VerticalAlignment getVerticalAlignment() const {
            return verticalAlignment;
        };

        Color getBackground() const {
            return background;
        }
        Color getForeground() const {
            return foreground;
        }

        String getText() {
            if (nativeIsInitialzed()) {
                text = nativeGetText();
            }
            return text;
        }

        Layout getLayout() const {
            return layout;
        }

    public:
        virtual ~AbstructFrameObject() {};

    };

   

}