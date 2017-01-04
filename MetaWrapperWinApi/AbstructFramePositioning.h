#pragma once
namespace MetaFrame {
    class AbstructFramePositioning {
    public:
        AbstructFramePositioning() :
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
        AbstructFramePositioning *setRect(Rect rect) {
            x = rect.x;
            y = rect.y;
            width = rect.width;
            height = rect.height;
            return this;
        };

        AbstructFramePositioning *setX(int x) {
            this->x = x;
            return this;
        };
        AbstructFramePositioning *setY(int y) {
            this->y = y;
            return this;
        };
        AbstructFramePositioning *setSize(Size size) {
            height = size.height;
            width = size.width;
            return this;
        };
        AbstructFramePositioning *setWidth(int width) {
            this->width = width;
            return this;
        };
        AbstructFramePositioning *setHeight(int height) {
            this->height = height;
            return this;
        };
        AbstructFramePositioning *setAutoWidth(bool autoWidth) {
            this->autoWidth = autoWidth;
            return this;
        };
        AbstructFramePositioning *setAutoHeight(bool autoHeight){
            this->autoHeight = autoHeight;
            return this;
        };
        AbstructFramePositioning *setMinWidth(int minWidth){
            this->minWidth = minWidth;
            return this;
        };
        AbstructFramePositioning *setMaxWidth(int maxWidth){
            this->maxWidth = maxWidth;
            return this;
        };
        AbstructFramePositioning *setMinHeight(int minHeight){
            this->minHeight = minHeight;
            return this;
        };
        AbstructFramePositioning *setMaxHeight(int maxHeight){
            this->maxHeight = maxHeight;
            return this;
        };
                                 
        AbstructFramePositioning *setMargin(int left, int right, int top, int bottom) {
            this->margin = Margin(left, right, top, bottom);
            return this;
        };
        AbstructFramePositioning *setMargin(Margin margin) {
            this->margin = margin;
            return this;
        };
                                 
        AbstructFramePositioning *setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {
            this->horizontalAlignment = horizontalAlignment;
            return this;
        };
        AbstructFramePositioning *setVerticalAlignment(VerticalAlignment verticalAlignment) {
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
        ~AbstructFramePositioning() {};

    };

}