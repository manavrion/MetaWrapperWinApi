#pragma once




class AbstructFrameElement {

public:
    AbstructFrameElement() {};



protected:
    //location in parent
    int x;
    int y;

    int width;
    int height;
    bool autoWidth;
    bool autoHeight;

    int minWidth;
    int maxWidth;
    int minHeight;
    int maxHeight;

    //Margin margin;
    //
    //HorizontalAlignment horizontalAlignment;
    //VerticalAlignment verticalAlignment;

    ~AbstructFrameElement() {};

};

