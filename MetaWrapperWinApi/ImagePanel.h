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


        /*virtual AbstructFrameElement *copy() const {
            ImagePanel *ret = new ImagePanel(*this);
            this->clearChilds();
            return ret;
        }*/

        void runActionEvents() {
            //for (auto &f : actionEventFunctions) f();
        }

    public:
        ADD_SET_OF_SETTERS(ImagePanel);
        ~ImagePanel() {};
    };



}