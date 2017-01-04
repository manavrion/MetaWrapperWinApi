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
            verticalAlignment(VerticalAlignment::Absolute) 
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

    public:
        //setters
        AbstructFrameObject *setRect(Rect rect) {
            x = rect.x;
            y = rect.y;
            width = rect.width;
            height = rect.height;
            return this;
        };

        AbstructFrameObject *setX(int x) {
            this->x = x;
            return this;
        };
        AbstructFrameObject *setY(int y) {
            this->y = y;
            return this;
        };
        AbstructFrameObject *setSize(Size size) {
            height = size.height;
            width = size.width;
            return this;
        };
        AbstructFrameObject *setWidth(int width) {
            this->width = width;
            return this;
        };
        AbstructFrameObject *setHeight(int height) {
            this->height = height;
            return this;
        };
        AbstructFrameObject *setAutoWidth(bool autoWidth) {
            this->autoWidth = autoWidth;
            return this;
        };
        AbstructFrameObject *setAutoHeight(bool autoHeight){
            this->autoHeight = autoHeight;
            return this;
        };
        AbstructFrameObject *setMinWidth(int minWidth){
            this->minWidth = minWidth;
            return this;
        };
        AbstructFrameObject *setMaxWidth(int maxWidth){
            this->maxWidth = maxWidth;
            return this;
        };
        AbstructFrameObject *setMinHeight(int minHeight){
            this->minHeight = minHeight;
            return this;
        };
        AbstructFrameObject *setMaxHeight(int maxHeight){
            this->maxHeight = maxHeight;
            return this;
        };
                                 
        AbstructFrameObject *setMargin(int left, int right, int top, int bottom) {
            this->margin = Margin(left, right, top, bottom);
            return this;
        };
        AbstructFrameObject *setMargin(Margin margin) {
            this->margin = margin;
            return this;
        };
                                 
        AbstructFrameObject *setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {
            this->horizontalAlignment = horizontalAlignment;
            return this;
        };
        AbstructFrameObject *setVerticalAlignment(VerticalAlignment verticalAlignment) {
            this->verticalAlignment = verticalAlignment;
            return this;
        };

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

    public:
        ~AbstructFrameObject() {};

    };

}