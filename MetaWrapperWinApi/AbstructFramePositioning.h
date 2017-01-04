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

        /*AbstructFramePositioning *setRect(Rect rect);

        AbstructFramePositioning *setX(int x);
        AbstructFramePositioning *setY(int y);
        AbstructFramePositioning *setSize(Size size);
        AbstructFramePositioning *setWidth(int width);
        AbstructFramePositioning *setHeight(int height);
        AbstructFramePositioning *setAutoWidth(bool autoWidth);
        AbstructFramePositioning *setAutoHeight(bool autoHeight);
        AbstructFramePositioning *setMinWidth(int minWidth);
        AbstructFramePositioning *setMaxWidth(int maxWidth);
        AbstructFramePositioning *setMinHeight(int minHeight);
        AbstructFramePositioning *setMaxHeight(int maxHeight);
                                 
        AbstructFramePositioning *setMargin(int left, int right, int top, int bottom);
        AbstructFramePositioning *setMargin(Margin margin);
                                 
        AbstructFramePositioning *setHorizontalAlignment(HorizontalAlignment horizontalAlignment);
        AbstructFramePositioning *setVerticalAlignment(VerticalAlignment verticalAlignment);*/



    public:
        ~AbstructFramePositioning() {};

    };

}