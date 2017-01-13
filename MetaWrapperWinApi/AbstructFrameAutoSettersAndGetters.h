#pragma once


namespace MetaFrame {
    
    //big macro

#define ADD_SET_OF_SETTERS(FrameType) \
    virtual FrameType *setRect(Rect rect) {\
        FrameObject::setRect(rect);\
        return this;\
    };\
\
    virtual FrameObject *setRect(int x, int y, int width, int height) {\
        FrameObject::setRect(Rect(x, y, width, height));\
        return this;\
    };\
    \
    virtual FrameType *setX(int x) {\
        FrameObject::setX(x);\
        return this;\
    };\
    virtual FrameType *setY(int y) {\
        FrameObject::setY(y);\
        return this;\
    };\
    virtual FrameType *setPosition(int x, int y) {\
        FrameObject::setPosition(x, y);\
        return this;\
    };\
    virtual FrameType *setPosition(Point point) {\
        FrameObject::setPosition(point);\
        return this;\
    };\
    virtual FrameType *setSize(Size size) {\
        FrameObject::setSize(size);\
        return this;\
    };\
    virtual FrameType *setSize(int width, int height) {\
        FrameObject::setSize(width, height);\
        return this;\
    };\
    virtual FrameType *setWidth(int width) {\
        FrameObject::setWidth(width);\
        return this;\
    };\
    virtual FrameType *setHeight(int height) {\
        FrameObject::setHeight(height);\
        return this;\
    };\
    virtual FrameType *setAutoWidth(bool autoWidth) {\
        FrameObject::setAutoWidth(autoWidth);\
        return this;\
    };\
    virtual FrameType *setAutoHeight(bool autoHeight) {\
        FrameObject::setAutoHeight(autoHeight);\
        return this;\
    };\
    virtual FrameType *setMinWidth(int minWidth) {\
        FrameObject::setMinWidth(minWidth);\
        return this;\
    };\
    virtual FrameType *setMaxWidth(int maxWidth) {\
        FrameObject::setMaxWidth(maxWidth);\
        return this;\
    };\
    virtual FrameType *setMinHeight(int minHeight) {\
        FrameObject::setMinHeight(minHeight);\
        return this;\
    };\
    virtual FrameType *setMaxHeight(int maxHeight) {\
        FrameObject::setMaxHeight(maxHeight);\
        return this;\
    };\
\
    virtual FrameType *setMargin(int left, int right, int top, int bottom) {\
        FrameObject::setMargin(left, right, top, bottom);\
        return this;\
    };\
    virtual FrameType *setMargin(Margin margin) {\
        FrameObject::setMargin(margin);\
        return this;\
    };\
\
    virtual FrameType *setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {\
        FrameObject::setHorizontalAlignment(horizontalAlignment);\
        return this;\
    };\
    virtual FrameType *setVerticalAlignment(VerticalAlignment verticalAlignment) {\
        FrameObject::setVerticalAlignment(verticalAlignment);\
        return this;\
    };\
\
    virtual FrameType *setAlignment(Alignment alignment) {\
        FrameObject::setAlignment(alignment);\
        return this; \
    }\
\
    virtual FrameType *setBackground(const Color &background) {\
        FrameObject::setBackground(background); \
        return this;\
    }\
    virtual FrameType *setForeground(const Color &foreground) {\
        FrameObject::setForeground(foreground); \
        return this;\
    }\
    virtual FrameType *setText(const String &text) {\
        FrameObject::setText(text); \
        return this;\
    }\
    virtual FrameType *setLayout(Layout layout) {\
        FrameObject::setLayout(layout);\
        return this;\
    }\
    virtual FrameType *setBorder(Border border) {\
            FrameObject::setBorder(border);\
            return this;\
    }\
typedef std::function<void(FrameType*, const MouseEventInfo&)> MouseFunction ## FrameType;\
\
typedef std::function<void()> ActionFunctionVoid ## FrameType;\
typedef std::function<void(FrameType *sender)> ActionFunction ## FrameType;\
\
        virtual FrameType *addMousePressedListener(MouseFunction ## FrameType f) {\
            FrameObject::addMousePressedListener([=](FrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        };\
\
        virtual FrameType *addMouseReleasedListener(MouseFunction ## FrameType f) {\
            FrameObject::addMouseReleasedListener([=](FrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        };\
\
        virtual FrameType *addMouseDraggedListener(MouseFunction ## FrameType f) {\
            FrameObject::addMouseDraggedListener([=](FrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        };\
\
        virtual FrameType *addMouseMovedListener(MouseFunction ## FrameType f) {\
            FrameObject::addMouseMovedListener([=](FrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        };\
\
\
        virtual FrameType *addActionListener(ActionFunctionVoid buttonFunction) {\
            FrameObject::addActionListener(buttonFunction);\
            return this;\
        }\
        virtual FrameType*addActionListener(ActionFunction ## FrameType buttonFunction) {\
            FrameObject::addActionListener([=](FrameObject *sender){ buttonFunction((FrameType*)sender); });\
            return this;\
        }\
        virtual FrameType*addMouseDoubleClickedListener(MouseFunction f) {\
            FrameObject::addMouseDoubleClickedListener([=](FrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        }\
        virtual FrameObject *addPropertyChangedListener(ActionFunction ## FrameType buttonFunction) {\
            FrameObject::addActionListener([=](FrameObject *sender){ buttonFunction((FrameType*)sender); });\
            return this;\
        }\
        
}