#pragma once

#include "Alignment.h"
#include "Point.h"
#include "Rect.h"
#include "Size.h"
#include "Margin.h"

#include "AbstructFrameAutoSettersAndGetters.h"

namespace MetaFrame {

    class FrameObject {
    public:
        FrameObject() :
            x(10), y(10),
            width(73), height(21),
            autoWidth(false), autoHeight(false),
            minWidth(0), maxWidth(0x7fffFFFF),
            minHeight(0), maxHeight(0x7fffFFFF),
            margin(10, 10, 10, 10),
            horizontalAlignment(HorizontalAlignment::Absolute),
            verticalAlignment(VerticalAlignment::Absolute),
            background(),
            foreground(),
            text(),
            layout(Layout::Simple),
            isDestroyed(null),
            parent(null)
        {};

        FrameObject(const FrameObject &abstructFrameObject) = delete;

    protected:
        /* fields */
        int x;//location in parent
        int y;//location in parent

        int width;
        int height;

        bool autoWidth;
        bool autoHeight;

        int minWidth;
        int maxWidth;
        int minHeight;
        int maxHeight;

        Margin margin;

        HorizontalAlignment horizontalAlignment;
        VerticalAlignment verticalAlignment;

        Color background;
        Color foreground;

        String text;

        Layout layout;

        Border border;


        FrameObject *parent;
        ArrayList<FrameObject*> childs;


    protected:
        virtual void packImpl();

        void destroyImpl();

    public:

        ArrayList<FrameObject*> &getChilds() {
            return childs;
        }


        virtual FrameObject *add(FrameObject *child) {
            child->parent = this;
            childs.push_back(child);
            return this;
        };

        virtual void clearChilds() {
            while (!childs.empty()) {
                delete childs.front();
            }
        };

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


        void destroy() {
            destroyImpl();
            delete this;
        }

        void repaint() {
            nativeRepaint();
        }

    protected:
        //NativeObject must have
        virtual void nativeSetRect(const Rect &rect) = 0;
        virtual void nativeSetBackground(const Color &rect) = 0;
        virtual void nativeSetForeground(const Color &rect) = 0;
        virtual void nativeSetText(const String &text) = 0;
        virtual String nativeGetText() const = 0;
        virtual void nativeSetBorder(Border border) = 0;

        virtual void nativeInit(FrameObject *parent) = 0;
        virtual bool nativeIsInitialzed() const = 0;
        virtual void nativeDestroy() = 0;
        virtual void nativeRepaint() = 0;

    public:

        //setters

        virtual FrameObject *setRect(Rect rect) {
            x = rect.x;
            y = rect.y;
            width = rect.width;
            height = rect.height;
            nativeSetRect(rect);
            return this;
        };
        virtual FrameObject *setRect(int x, int y, int width, int height) {
            this->width = width;
            this->height = height;
            this->x = x;
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };


        virtual FrameObject *setX(int x) {
            this->x = x;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setY(int y) {
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setPosition(int x, int y) {
            this->x = x;
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setPosition(Point point) {
            this->x = point.x;
            this->y = point.y;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };

        virtual FrameObject *setSize(Size size) {
            height = size.height;
            width = size.width;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setSize(int width, int height) {
            this->width = width;
            this->height = height;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setWidth(int width) {
            this->width = width;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setHeight(int height) {
            this->height = height;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setAutoWidth(bool autoWidth) {
            this->autoWidth = autoWidth;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setAutoHeight(bool autoHeight){
            this->autoHeight = autoHeight;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMinWidth(int minWidth){
            this->minWidth = minWidth;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMaxWidth(int maxWidth){
            this->maxWidth = maxWidth;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMinHeight(int minHeight){
            this->minHeight = minHeight;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMaxHeight(int maxHeight){
            this->maxHeight = maxHeight;
            runPropertyChangedEvents();
            return this;
        };
                                 
        virtual FrameObject *setMargin(int left, int right, int top, int bottom) {
            this->margin = Margin(left, right, top, bottom);
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMargin(Margin margin) {
            this->margin = margin;
            runPropertyChangedEvents();
            return this;
        };
                                 
        virtual FrameObject *setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {
            this->horizontalAlignment = horizontalAlignment;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setVerticalAlignment(VerticalAlignment verticalAlignment) {
            this->verticalAlignment = verticalAlignment;
            runPropertyChangedEvents();
            return this;
        };

        virtual FrameObject *setAlignment(Alignment alignment) {
            switch (alignment) {
                case MetaFrame::Alignment::Absolute:
                    verticalAlignment = VerticalAlignment::Absolute;
                    horizontalAlignment = HorizontalAlignment::Absolute;
                    break;
                case MetaFrame::Alignment::Center:
                    verticalAlignment = VerticalAlignment::Center;
                    horizontalAlignment = HorizontalAlignment::Center;
                    break;
                case MetaFrame::Alignment::Stretch:
                    autoWidth = true;
                    horizontalAlignment = HorizontalAlignment::Stretch;
                    autoHeight = true;
                    verticalAlignment = VerticalAlignment::Stretch;
                    break;
                default:
                    break;
            }
            runPropertyChangedEvents();
            return this;
        };

        virtual FrameObject *setBackground(const Color &background){
            this->background = background;
            nativeSetBackground(background);
            runPropertyChangedEvents();
            return this;
        }
        virtual FrameObject *setForeground(const Color &foreground){
            this->foreground = foreground;
            nativeSetForeground(foreground);
            runPropertyChangedEvents();
            return this;
        }

        virtual FrameObject *setText(const String &text){
            this->text = text;
            nativeSetText(text);
            runPropertyChangedEvents();
            return this;
        }

        virtual FrameObject *setLayout(Layout layout) {
            this->layout = layout;
            runPropertyChangedEvents();
            return this;
        }

        virtual FrameObject *setBorder(Border border) {
            this->border = border;
            nativeSetBorder(border);
            runPropertyChangedEvents();
            return this;
        }

        //getters
        int getX() const {
            return x;
        };
        int getY() const {
            return y;
        };

        Point getPosition() {
            return Point(x, y);
        }

        Rect getRect() const {
            return Rect(x, y, width, height);
        };

        int getWidth() const {
            return width;
        };
        int getHeight() const {
            return height;
        };

        Size getSize() const {
            return Size(width, height);
        };
        bool getAutoWidth() const {
            return autoWidth;
        };
        bool getAutoHeight() const {
            return autoHeight;
        };
        int getMinWidth() const {
            return minWidth;
        };
        int getMaxWidth() const {
            return maxWidth;
        };
        int getMinHeight() const {
            return minHeight;
        };
        int getMaxHeight() const {
            return maxHeight;
        };

        Margin getMargin() const {
            return margin;
        };

        HorizontalAlignment getHorizontalAlignment() const {
            return horizontalAlignment;
        };
        VerticalAlignment getVerticalAlignment() const {
            return verticalAlignment;
        };

        Color getBackground() const {
            return background;
        }
        Color getForeground() const {
            return foreground;
        }

        String getText() {
            if (nativeIsInitialzed()) {
                text = nativeGetText();
            }
            return text;
        }

        Layout getLayout() const {
            return layout;
        }

        Border getBorder() const {
            return border;
        }

        /* EVENTS */



        typedef std::function<void(FrameObject*, const MouseEventInfo&)> MouseFunction;

        typedef std::function<void()> ActionFunctionVoid;
        typedef std::function<void(FrameObject *sender)> ActionFunction;


        virtual FrameObject *addMousePressedListener(MouseFunction f) {
            mousePressedEvents.push_back(f);
            return this;
        };

        virtual FrameObject *addMouseReleasedListener(MouseFunction f) {
            mouseReleasedEvents.push_back(f);
            return this;
        };

        virtual FrameObject *addMouseDraggedListener(MouseFunction f) {
            mouseDraggedEvents.push_back(f);
            return this;
        };

        virtual FrameObject *addMouseMovedListener(MouseFunction f) {
            mouseMovedEvents.push_back(f);
            return this;
        };

        virtual FrameObject *addMouseDoubleClickedListener(MouseFunction f) {
            mouseDoubleClickedEvents.push_back(f);
            return this;
        };


        virtual FrameObject *addActionListener(ActionFunctionVoid buttonFunction) {
            actionEventFunctionsVoid.push_back(buttonFunction);
            return this;
        }
        virtual FrameObject *addActionListener(ActionFunction buttonFunction) {
            actionEventFunctionsSender.push_back(buttonFunction);
            return this;
        }

        virtual FrameObject *addPropertyChangedListener(ActionFunction buttonFunction) {
            propertyChangedEventFunctions.push_back(buttonFunction);
            return this;
        }


        void clearMousePressedListeners() {
            mousePressedEvents.clear();
        };
        void clearMouseReleasedListeners() {
            mouseReleasedEvents.clear();            
        };
        void clearMouseDraggedListeners() {
            mouseDraggedEvents.clear();            
        };
        void clearMouseMovedListeners() {
            mouseMovedEvents.clear();            
        };

        void clearMouseDoubleClickedListeners() {
            mouseMovedEvents.clear();
        };

        void clearMouseActionListeners() {
            actionEventFunctionsVoid.clear();
            actionEventFunctionsSender.clear();
        };

        void clearPropertyChangedListeners() {
            propertyChangedEventFunctions.clear();
        };

        protected:

            ArrayList<MouseFunction> mousePressedEvents;
            ArrayList<MouseFunction> mouseReleasedEvents;

            ArrayList<MouseFunction> mouseDoubleClickedEvents;

            ArrayList<MouseFunction> mouseDraggedEvents;
            ArrayList<MouseFunction> mouseMovedEvents;

            ArrayList<ActionFunctionVoid> actionEventFunctionsVoid;
            ArrayList<ActionFunction> actionEventFunctionsSender;

            ArrayList<ActionFunction> propertyChangedEventFunctions;

    protected:
        void runMousePressedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < mousePressedEvents.size(); i++) {
                auto func = mousePressedEvents[i];
                if (isDestr) { return; }
                func((FrameObject*)this, event);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                event.x += x;
                event.y += y;
                parent->runMousePressedEvent(event);
            }
        };
        void runMouseReleasedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < mouseReleasedEvents.size(); i++) {
                auto func = mouseReleasedEvents[i];
                if (isDestr) { return; }
                func((FrameObject*)this, event);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                event.x += x;
                event.y += y;
                parent->runMouseReleasedEvent(event);
            }
        };
        void runMouseDraggedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < mouseDraggedEvents.size(); i++) {
                auto func = mouseDraggedEvents[i];
                if (isDestr) { return; }
                func((FrameObject*)this, event);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                event.x += x;
                event.y += y;
                parent->runMouseDraggedEvent(event);
            }
        };
        void runMouseMovedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < mouseMovedEvents.size(); i++) {
                auto func = mouseMovedEvents[i];
                if (isDestr) { return; }
                func((FrameObject*)this, event);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                event.x += x;
                event.y += y;
                parent->runMouseMovedEvent(event);
            }
        };

        void runMouseDoubleClickedEvent(MouseEventInfo event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < mouseDoubleClickedEvents.size(); i++) {
                auto func = mouseDoubleClickedEvents[i];
                if (isDestr) { return; }
                func((FrameObject*)this, event);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                event.x += x;
                event.y += y;
                parent->runMouseDoubleClickedEvent(event);
            }
        };


        virtual void runActionEvents() {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < actionEventFunctionsVoid.size(); i++) {
                auto func = actionEventFunctionsVoid[i];
                if (isDestr) { return; }
                func();
                if (isDestr) { return; }
            }
            for (int i = 0; i < actionEventFunctionsSender.size(); i++) {
                auto func = actionEventFunctionsSender[i];
                if (isDestr) { return; }
                func((FrameObject*)this);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                parent->runActionEvents();
            }
        }

        virtual void runPropertyChangedEvents() {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < propertyChangedEventFunctions.size(); i++) {
                auto func = propertyChangedEventFunctions[i];
                if (isDestr) { return; }
                func((FrameObject*)this);
                if (isDestr) { return; }
            }
            isDestroyed = null;
        }

    private:
        bool *isDestroyed;

    public:
        virtual ~FrameObject() {
            if (isDestroyed != null) {
                *isDestroyed = true;
            }
        };

    };

   

}