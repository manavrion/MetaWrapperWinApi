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
        ~AbstructFramePositioning() {};

    };

}