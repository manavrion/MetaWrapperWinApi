#pragma once
#include "FrameObject.h"
#include "AbstructFrameAutoSettersAndGetters.h"

namespace MetaFrame {

    class IncorrectDestroy {};

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
        //рекурсивно задаёт элементам их положение и размер в соответствии с правилами, описывающими их
        void pack() {
            this->packImpl();
            for (auto &ob : childs) {
                ob->pack();
            };
        };

        //рекурсивно создаёт элементы на форме
        void build() {
            this->nativeInit(parent);
            for (auto object : childs) {
                object->build();
            }
        }

        virtual FrameNode *add(FrameNode *child) {
            child->parent = this;
            childs.push_back(child);
            return this;
        };

        void destroy() {
            destroyImpl();
            delete this;
        }

        void repaint() {
            nativeRepaint();
        }

    public:
        virtual ~FrameNode() {

        };

    };

}