#pragma once

#include "Alignment.h"
#include "Point.h"
#include "Rect.h"
#include "Size.h"
#include "Margin.h"
#include "KeyEvent.h"
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
            parent(null),
            transparent(255)
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

        byte transparent;

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
        virtual void nativeSetTransparent(byte transparent) = 0;

    public:

        //setters

        virtual FrameObject *setRect(Rect rect) {
            if (Rect(x, y, width, height) == rect) {
                return this;
            }
            x = rect.x;
            y = rect.y;
            width = rect.width;
            height = rect.height;
            nativeSetRect(rect);
            return this;
        };
        virtual FrameObject *setRect(int x, int y, int width, int height) {
            if (Rect(this->x, this->y, this->width, this->height) == Rect(x, y, width, height)) {
                return this;
            }
            this->width = width;
            this->height = height;
            this->x = x;
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            return this;
        };


        virtual FrameObject *setX(int x) {
            if (this->x == x) {
                return this;
            }
            this->x = x;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setY(int y) {
            if (this->y == y) {
                return this;
            }
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setPosition(int x, int y) {
            if (this->x == x && this->y == y) {
                return this;
            }
            this->x = x;
            this->y = y;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setPosition(Point point) {
            if (Point(x, y) == point) {
                return this;
            }
            this->x = point.x;
            this->y = point.y;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };

        virtual FrameObject *setSize(Size size) {
            if (Size(width, height) == size) {
                return this;
            }
            height = size.height;
            width = size.width;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setSize(int width, int height) {
            if (Size(this->width, this->height) == Size(width, height)) {
                return this;
            }
            this->width = width;
            this->height = height;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setWidth(int width) {
            if (this->width == width) {
                return this;
            }
            this->width = width;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setHeight(int height) {
            if (this->height == height) {
                return this;
            }
            this->height = height;
            nativeSetRect(Rect(x, y, width, height));
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setAutoWidth(bool autoWidth) {
            if (this->autoWidth == autoWidth) {
                return this;
            }
            this->autoWidth = autoWidth;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setAutoHeight(bool autoHeight){
            if (this->autoHeight == autoHeight) {
                return this;
            }
            this->autoHeight = autoHeight;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMinWidth(int minWidth){
            if (this->minWidth == minWidth) {
                return this;
            }
            this->minWidth = minWidth;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMaxWidth(int maxWidth){
            if (this->maxWidth == maxWidth) {
                return this;
            }
            this->maxWidth = maxWidth;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMinHeight(int minHeight){
            if (this->minHeight == minHeight) {
                return this;
            }
            this->minHeight = minHeight;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMaxHeight(int maxHeight){
            if (this->maxHeight == maxHeight) {
                return this;
            }
            this->maxHeight = maxHeight;
            runPropertyChangedEvents();
            return this;
        };
                                 
        virtual FrameObject *setMargin(int left, int right, int top, int bottom) {
            if (this->margin == Margin(left, right, top, bottom)) {
                return this;
            }
            this->margin = Margin(left, right, top, bottom);
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setMargin(Margin margin) {
            if (this->margin == margin) {
                return this;
            }
            this->margin = margin;
            runPropertyChangedEvents();
            return this;
        };
                                 
        virtual FrameObject *setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {
            if (this->horizontalAlignment == horizontalAlignment) {
                return this;
            }
            this->horizontalAlignment = horizontalAlignment;
            runPropertyChangedEvents();
            return this;
        };
        virtual FrameObject *setVerticalAlignment(VerticalAlignment verticalAlignment) {
            if (this->verticalAlignment == verticalAlignment) {
                return this;
            }
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
            if (this->background == background) {
                return this;
            }
            this->background = background;
            nativeSetBackground(background);
            runPropertyChangedEvents();
            return this;
        }
        virtual FrameObject *setForeground(const Color &foreground){
            if (this->foreground == foreground) {
                return this;
            }
            this->foreground = foreground;
            nativeSetForeground(foreground);
            runPropertyChangedEvents();
            return this;
        }

        virtual FrameObject *setText(const String &text){
            if (this->text == text) {
                return this;
            }
            this->text = text;
            nativeSetText(text);
            runPropertyChangedEvents();
            return this;
        }

        virtual FrameObject *setLayout(Layout layout) {
            if (this->layout == layout) {
                return this;
            }
            this->layout = layout;
            runPropertyChangedEvents();
            return this;
        }

        virtual FrameObject *setBorder(Border border) {
            if (this->border == border) {
                return this;
            }
            this->border = border;
            nativeSetBorder(border);
            runPropertyChangedEvents();
            return this;
        }

        virtual FrameObject *setTransparent(byte transparent) {
            if (this->transparent == transparent) {
                return this;
            }
            this->transparent = transparent;
            nativeSetTransparent(transparent);
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

        typedef std::function<void(FrameObject *sender, KeyEvent)> KeyFunction;

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


        virtual FrameObject *addKeyPressedListener(KeyFunction buttonFunction) {
            keyPressedEventFunctions.push_back(buttonFunction);
            return this;
        }
        virtual FrameObject *addKeyReleasedListener(KeyFunction buttonFunction) {
            keyReleasedEventFunctions.push_back(buttonFunction);
            return this;
        }
        virtual FrameObject *addKeyTypedListener(KeyFunction buttonFunction) {
            keyTypedEventFunctions.push_back(buttonFunction);
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


        void clearKeyPressedListeners() {
            keyPressedEventFunctions.clear();
        };
        void clearKeyReleasedListeners() {
            keyReleasedEventFunctions.clear();
        };
        void clearKeyTypedListeners() {
            keyTypedEventFunctions.clear();
        };

        void clearAllListeners() {
            mousePressedEvents.clear();
            mouseReleasedEvents.clear();
            mouseDoubleClickedEvents.clear();
            mouseDraggedEvents.clear();
            mouseMovedEvents.clear();
            actionEventFunctionsVoid.clear();
            actionEventFunctionsSender.clear();
            propertyChangedEventFunctions.clear();
            keyPressedEventFunctions.clear();
            keyReleasedEventFunctions.clear();
            keyTypedEventFunctions.clear();
        }


        protected:

            ArrayList<MouseFunction> mousePressedEvents;
            ArrayList<MouseFunction> mouseReleasedEvents;

            ArrayList<MouseFunction> mouseDoubleClickedEvents;

            ArrayList<MouseFunction> mouseDraggedEvents;
            ArrayList<MouseFunction> mouseMovedEvents;

            ArrayList<ActionFunctionVoid> actionEventFunctionsVoid;
            ArrayList<ActionFunction> actionEventFunctionsSender;

            ArrayList<ActionFunction> propertyChangedEventFunctions;

            ArrayList<KeyFunction> keyPressedEventFunctions;
            ArrayList<KeyFunction> keyReleasedEventFunctions;
            ArrayList<KeyFunction> keyTypedEventFunctions;

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

        void runKeyPressedEvent(KeyEvent event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < keyPressedEventFunctions.size(); i++) {
                auto func = keyPressedEventFunctions[i];
                if (isDestr) { return; }
                func((FrameObject*)this, event);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                parent->runKeyPressedEvent(event);
            }
        };

        void runKeyReleasedEvent(KeyEvent event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < keyReleasedEventFunctions.size(); i++) {
                auto func = keyReleasedEventFunctions[i];
                if (isDestr) { return; }
                func((FrameObject*)this, event);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                parent->runKeyReleasedEvent(event);
            }
        };

        void runKeyTypedEvent(KeyEvent event) {
            bool isDestr = false;
            isDestroyed = &isDestr;
            for (int i = 0; i < keyTypedEventFunctions.size(); i++) {
                auto func = keyTypedEventFunctions[i];
                if (isDestr) { return; }
                func((FrameObject*)this, event);
                if (isDestr) { return; }
            }
            if (isDestr) { return; }
            isDestroyed = null;
            if (parent != null) {
                parent->runKeyTypedEvent(event);
            }
        };

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