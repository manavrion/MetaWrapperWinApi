#pragma once
#include "FrameObject.h"
#include "AbstructFrameAutoSettersAndGetters.h"

namespace MetaFrame {

    class FrameNode : public FrameObject {

    public:
        FrameNode() : parent(null) {};

        FrameNode(const FrameNode &abstructFrameElement) = delete;
    protected:

        FrameNode *parent;
        ArrayList<FrameNode*> childs;

    protected:
        virtual void packImpl();

        void destroyImpl() {
            while (!childs.empty()) {
                childs.back()->destroy();
            }
            childs.clear();
            if (parent != null) {
                for (auto it = parent->childs.begin(); it != parent->childs.end(); it++) {
                    if (*it == this) {
                        parent->childs.erase(it);
                        break;
                    }
                }
            }
            nativeDestroy();
        }

    public:
        virtual FrameNode *add(FrameNode *child) {
            child->parent = this;
            childs.push_back(child);
            return this;
        };

        /* FrameObject declared methods */

        //рекурсивно задаёт элементам их положение и размер в соответствии с правилами, описывающими их
        void pack() override {
            this->packImpl();
            for (auto &ob : childs) {
                ob->pack();
            };
        };

        //рекурсивно создаёт элементы на форме
        void build() override {
            this->nativeInit(parent);
            for (auto object : childs) {
                object->build();
            }
        }


        void destroy() override {
            destroyImpl();
            delete this;
        }

        void repaint() override  {
            nativeRepaint();
        }

    public:
        virtual ~FrameNode() {

        };

    };

}