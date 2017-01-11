#pragma once
#include "AbstructFrameObject.h"
#include "AbstructFrameAutoSettersAndGetters.h"

namespace MetaFrame {

    class AbstructFrameElement : public AbstructFrameObject {

    public:
        AbstructFrameElement() 
            : parent(null)
        {};

        AbstructFrameElement(const AbstructFrameElement &abstructFrameElement) = delete;

        void build() {
            this->initializationEvent(parent);
            for (auto object : childs) {
                object->build(this);
            }
        }

        void buildFix() {
            //this->initializationEvent(parent);
            for (auto object : childs) {
                object->build(this);
            }
        }

        virtual void wmUpd() = 0;

        void saveUpdate() {
            wmUpd();
        }

        void destroy() {
            bool fl = true;
            for (auto it = parent->childs.begin(); it != parent->childs.end(); it++) {
                if (*it == this) {
                    parent->childs.erase(it);
                    fl = false;
                    break;
                }
            }
            if (fl) {
                return;
            }
            wmClose();
            delete this;
        }

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

        //virtual AbstructFrameElement *copy() const = 0;
        /*virtual void clearChilds() const {
            childs.clear();
        }*/
        //virtual void nativeCopy(AbstructFrameElement *nw, const AbstructFrameElement &old) const = 0;

        virtual void wmClose() = 0;



    public:
        virtual AbstructFrameElement *add(AbstructFrameElement *child) {
            child->parent = this;
            //AbstructFrameElement *newChild = child.copy();
            //nativeCopy(newChild, child);
            //newChild->parent = this;
            childs.push_back(child);
            return this;
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
        //рекурсивно задаёт элементам их положение и размер в соответствии с правилами, описывающими их
        virtual void pack() {
            this->runPackEvent();
        };

    public:
        ~AbstructFrameElement() {
            for (auto object : childs) {
                //object->destroy();
                delete object;
            }
            childs.clear();
        };

    };

}