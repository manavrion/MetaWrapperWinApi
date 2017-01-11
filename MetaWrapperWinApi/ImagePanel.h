#pragma once

#include "Image.h"
#include "NativeImagePanel.h"

namespace MetaFrame {


    class ImagePanel : public NativeImagePanel {
    public:
        ImagePanel(Image *image) : NativeImagePanel(*image), image(image){
            x = 0;
            y = 0;
            width = image->getSize().width;
            height = image->getSize().height;
        };

        Image *image;
    protected:




    public:
        ADD_SET_OF_SETTERS(ImagePanel);
        ~ImagePanel() {};
    };



}