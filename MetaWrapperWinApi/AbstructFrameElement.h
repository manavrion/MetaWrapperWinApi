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
        AbstructFrameElement &add(Button &child);;
        /*template<class TemplateFrameElement>
        AbstructFrameElement &add(TemplateFrameElement &child) {
            TemplateFrameElement *newChild = new TemplateFrameElement(child);
            newChild->parent = this;
            childs.push_back(newChild);
            return *this;
        };*/

    public:
        ~AbstructFrameElement() {
            childs.clear();
            /*for (auto object : childs) {
                delete object;
            }*/
        };

    };

}