#pragma once

#include "NativePanel.h"
#include "Border.h"

namespace MetaFrame {

    class Panel : public NativePanel {
    public:
        Panel() {

        };


        Panel *setBorderText(const String &text) {
            this->borderText = text;
            nativeSetBorderText(borderText);
            return this;
        }

        String getBorderText() {
            return borderText;
        }


        

    protected:
        Border border;
        String borderText;



    public:
        ADD_SET_OF_SETTERS(Panel);
        ~Panel() {};
    };


}

