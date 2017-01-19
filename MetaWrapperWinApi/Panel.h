#pragma once

#include "NativePanel.h"
#include "Border.h"

namespace MetaFrame {

    class Panel : public NativePanel {
    public:
        Panel() {

        };   


    public:
        ADD_SET_OF_SETTERS(Panel);
        virtual ~Panel() {};
    };


}

