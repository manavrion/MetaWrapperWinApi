#pragma once
#include "AbstructFramePositioning.h"

namespace MetaFrame {

    class AbstructFrameElement : public AbstructFramePositioning {

    public:
        AbstructFrameElement() 
            : parent(null)
        {};

    protected:

        AbstructFrameElement *parent;
        ArrayList<AbstructFrameElement*> childs;

        void build(AbstructFrameElement *parent) {
            this->parent = parent;
            this->initializationEvent(parent);
            for (auto object : childs) {
                object->build(this);
            }
        }
        virtual void initializationEvent(AbstructFrameElement *parent) = 0;

    public:
        AbstructFrameElement *add(AbstructFrameElement *child) {
            childs.push_back(child);
            child->parent = this;
            return this;
        };


    public:
        ~AbstructFrameElement() {};

    };

}