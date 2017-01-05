#pragma once
#include "AbstructFrameObject.h"

namespace MetaFrame {

    class Button;

    class AbstructFrameElement : public AbstructFrameObject {

    public:
        AbstructFrameElement() 
            : parent(null)
        {};

    protected:

        const AbstructFrameElement *parent;
        ArrayList<AbstructFrameElement*> childs;

        void build(const AbstructFrameElement *parent) {
            this->parent = parent;
            this->initializationEvent(parent);
            for (auto object : childs) {
                object->build(this);
            }
        }
        virtual void initializationEvent(const AbstructFrameElement *parent) = 0;

    public:
        AbstructFrameElement &add(const Button &child);

    public:
        ~AbstructFrameElement() {
            for (auto object : childs) {
                delete object;
            }
            childs.clear();
        };

    };

}