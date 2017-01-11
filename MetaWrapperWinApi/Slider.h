#pragma once

#include "NativeSlider.h"

namespace MetaFrame {

    class Slider;
    typedef std::function<void()> SliderFunctionVoid;
    typedef std::function<void(Slider &sender)> SliderFunctionSender;

    class Slider : public NativeSlider {
    public:
        Slider() : minPos(0), maxPos(100){};







        Slider *setPos(int pos) {
            return this;
        }
        Slider *setMinMax(int minPos, int maxPos) {
            nativeSetMinMax(minPos, maxPos);
            this->minPos = minPos;
            this->maxPos = maxPos;
            return this;
        }
        Slider *setMin(int minPos) {
            nativeSetMinMax(minPos, maxPos);
            this->minPos = minPos;
            return this;
        }
        Slider *setMax(int maxPos) {
            nativeSetMinMax(minPos, maxPos);
            this->maxPos = maxPos;
            return this;
        }

        int getPos() {
            return nativeGetPos();
        }
        int getMin() {
            return minPos;
        }
        int getMax() {
            return maxPos;
        }







    protected:

        int maxPos;
        int minPos;





    public:
        ADD_SET_OF_SETTERS(Slider);

        ~Slider() {};
    };

}