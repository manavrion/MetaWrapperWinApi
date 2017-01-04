#pragma once
#include "AbstructFrameObject.h"

namespace MetaFrame {

    class AbstructFrameElement : public AbstructFrameObject {

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
        AbstructFrameElement *add(AbstructFrameObject *child) {
            childs.push_back((AbstructFrameElement *)child);
            ((AbstructFrameElement *)child)->parent = this;
            return this;
        };


    public:
        ~AbstructFrameElement() {
            for (auto object : childs) {
                delete object;
            }
        };

    };

}