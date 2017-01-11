#pragma once
#include <functional>
#include "AbstructFrameObject.h"
#include "MouseEvent.h"
#include "MFTafx.h"

namespace MetaFrame {



    

    template<class FrameElementT>
    class AbstructFrameEvent {
    public:
        AbstructFrameEvent() : isDestroyed(null) {};

        typedef std::function<void(FrameElementT*, const MouseEventInfo&)> MouseFunction;
        
        typedef std::function<void()> ActionFunctionVoid;
        typedef std::function<void(FrameElementT *sender)> ActionFunction;
        /*
        AbstructFrameEvent *addKeyPressedListener(KeyFunction f);
        AbstructFrameEvent *addKeyReleasedListener(KeyFunction f);
        AbstructFrameEvent *addKeyTypedListener(KeyFunction f);
        AbstructFrameEvent *addMouseDoubleClickedListener(MouseFunction f);
        AbstructFrameEvent *addMouseEnteredListener(MouseFunction f);
        AbstructFrameEvent *addMouseExitedListener(MouseFunction f);*/
        FrameElementT *addMousePressedListener(MouseFunction f) {
            mousePressedEvents.push_back(f);
            return (FrameElementT*)this;
        };
        FrameElementT *addMouseReleasedListener(MouseFunction f) {
            mouseReleasedEvents.push_back(f);
            return (FrameElementT*)this;
        };
        FrameElementT *addMouseDraggedListener(MouseFunction f) {
            mouseDraggedEvents.push_back(f);
            return (FrameElementT*)this;
        };
        FrameElementT *addMouseMovedListener(MouseFunction f) {
            mouseMovedEvents.push_back(f);
            return (FrameElementT*)this;
        };
        //NativeAbstructObject *addMouseWheelMovedListener(MouseFunction f);
        
        FrameElementT *addActionListener(ActionFunctionVoid buttonFunction) {
            actionEventFunctionsVoid.push_back(buttonFunction);
            return (FrameElementT*)this;
        }
        FrameElementT *addActionListener(ActionFunction buttonFunction) {
            actionEventFunctionsSender.push_back(buttonFunction);
            return (FrameElementT*)this;
        }


        FrameElementT *clearMousePressedListeners(MouseFunction f) {
            mousePressedEvents.clear();
            return (FrameElementT*)this;
        };
        FrameElementT *clearMouseReleasedListeners(MouseFunction f) {
            mouseReleasedEvents.clear();
            return (FrameElementT*)this;
        };
        FrameElementT *clearMouseDraggedListeners(MouseFunction f) {
            mouseDraggedEvents.clear();
            return (FrameElementT*)this;
        };
        FrameElementT *clearMouseMovedListeners(MouseFunction f) {
            mouseMovedEvents.clear();
            return (FrameElementT*)this;
        };

    protected:
        
        /*ArrayList<KeyFunction>   keyPressedEvents;
        ArrayList<KeyFunction>   keyReleasedEvents;
        ArrayList<KeyFunction>   keyTypedEvents;*/

        //ArrayList<MouseFunction> mouseDoubleClickedEvents;
        //ArrayList<MouseFunction> mouseEnteredEvents;
        //ArrayList<MouseFunction> mouseExitedEvents;
        ArrayList<MouseFunction> mousePressedEvents;
        ArrayList<MouseFunction> mouseReleasedEvents;

        ArrayList<MouseFunction> mouseDraggedEvents;
        ArrayList<MouseFunction> mouseMovedEvents;

        //ArrayList<MouseFunction> mouseWheelMovedEvents;

        /*void runKeyPressedEvent(const KeyEvent &event);
        void runKeyReleasedEvent(const KeyEvent &event);
        void runKeyTypedEvent(const KeyEvent &event);

        void runMouseDoubleClickedEvent(MouseEventInfo event);*/

        /*void runMouseEnteredEvent(MouseEventInfo event);
        void runMouseExitedEvent(MouseEventInfo event);*/

        ArrayList<ActionFunctionVoid> actionEventFunctionsVoid;
        ArrayList<ActionFunction> actionEventFunctionsSender;

    public:
        void runMousePressedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (auto &func : mousePressedEvents) {
                if (isDestr) { return; }
                func((FrameElementT*)this, event);
                if (isDestr) { return; }
            }
            isDestroyed = null;
        };
        void runMouseReleasedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (auto &func : mouseReleasedEvents) {
                if (isDestr) { return; }
                func((FrameElementT*)this, event);
                if (isDestr) { return; }
            }
            isDestroyed = null;
        };
        void runMouseDraggedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (auto &func : mouseDraggedEvents) {
                if (isDestr) { return; }
                func((FrameElementT*)this, event);
                if (isDestr) { return; }
            }
            isDestroyed = null;
        };
        void runMouseMovedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (auto &func : mouseMovedEvents) {
                if (isDestr) { return;}
                func((FrameElementT*)this, event);
                if (isDestr) { return; }
            }
            isDestroyed = null;
        };

        virtual void runActionEvents() {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (auto &f : actionEventFunctionsVoid) { 
                if (isDestr) { return; }
                f();
                if (isDestr) { return; }
            }
            for (auto &f : actionEventFunctionsSender) { 
                if (isDestr) { return; }
                f((FrameElementT*)this);
                if (isDestr) { return; }
            }
            isDestroyed = null;
        }

        virtual ~AbstructFrameEvent() {
            if (isDestroyed != null) {
                *isDestroyed = true;
            }
        };

    private:
        bool *isDestroyed;
    };



}