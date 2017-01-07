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
        virtual void nativeCopy(AbstructFrameElement *nw, const AbstructFrameElement &old) const = 0;

    public:
        AbstructFrameElement &add(const AbstructFrameElement &child) {
            AbstructFrameElement *newChild = child.copy();
            //nativeCopy(newChild, child);
            newChild->parent = this;
            childs.push_back(newChild);
            return *this;
        };









        /* pack */
    protected:
        virtual void packEvent();

        void runPackEvent() {
            this->packEvent();
            for (auto &ob : childs) {
                ob->runPackEvent();
            }
        }

    public:
        virtual void pack() {
            this->runPackEvent();
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