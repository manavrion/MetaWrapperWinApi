﻿#pragma once
#include "AbstructFrameObject.h"
#include "AbstructFrameAutoSettersAndGetters.h"

namespace MetaFrame {

    class IncorrectDestroy {};

    class AbstructFrameElement : public AbstructFrameObject {

    public:
        AbstructFrameElement() : parent(null) {};

        AbstructFrameElement(const AbstructFrameElement &abstructFrameElement) = delete;
    protected:

        AbstructFrameElement *parent;
        ArrayList<AbstructFrameElement*> childs;


        virtual void nativeInit(AbstructFrameElement *parent) = 0;
        virtual void nativeDestroy() = 0;
        virtual void nativeRepaint() = 0;

    protected:
        virtual void packImpl();

        void destroyImpl() {
            for (auto object : childs) {
                object->destroy();
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

        virtual AbstructFrameElement *add(AbstructFrameElement *child) {
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
        ~AbstructFrameElement() {

        };

    };

}