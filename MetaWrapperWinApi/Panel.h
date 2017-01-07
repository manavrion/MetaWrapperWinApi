#pragma once

#include "NativePanel.h"
#include "Border.h"

namespace MetaFrame {

    class Panel : public NativePanel {
    public:
        Panel() : border(Border::BORDER) {

        };


        Panel &setBorderText(const String &text) {
            this->borderText = text;
            nativeSetBorderText(borderText);
            return *this;
        }

        String getBorderText() {
            return borderText;
        }

        Panel &setBorder(Border border) {
            this->border = border;
            nativeSetBorder(border);
            return *this;
        }

        Border getBorder() {
            return border;
        }

    protected:
        Border border;
        String borderText;


        virtual AbstructFrameElement *copy() const {
            Panel *ret = new Panel(*this);
            this->clearChilds();
            return ret;
        }

        void runActionEvents() {
            //for (auto &f : actionEventFunctions) f();
        }

    public:
        ADD_SET_OF_SETTERS(Panel);
        ~Panel() {};
    };


}

