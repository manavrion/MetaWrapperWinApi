#pragma once
#include "AbstructFrameObject.h"

namespace MetaFrame {

    class AbstructFrameElement : public AbstructFrameObject {

    public:
        AbstructFrameElement() 
            : parent(null)
        {};

    protected:

        const AbstructFrameElement *parent;
        mutable ArrayList<AbstructFrameElement*> childs;

        void build(const AbstructFrameElement *parent) {
            this->parent = parent;
            this->initializationEvent(parent);
            for (auto object : childs) {
                object->build(this);
            }
        }
        virtual void initializationEvent(const AbstructFrameElement *parent) = 0;

        virtual AbstructFrameElement *copy() const = 0;
        virtual void clearChilds() const {
            childs.clear();
        }

    public:
        AbstructFrameElement &add(const AbstructFrameElement &child) {
            AbstructFrameElement *newChild = child.copy();
            newChild->parent = this;
            childs.push_back(newChild);
            return *this;
        };

    public:
        ~AbstructFrameElement() {
            for (auto object : childs) {
                delete object;
            }
            childs.clear();
        };

    };

}