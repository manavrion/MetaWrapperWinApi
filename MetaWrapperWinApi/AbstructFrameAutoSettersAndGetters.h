#pragma once


namespace MetaFrame {
    
    //big macro

#define ADD_SET_OF_SETTERS(FrameType) \
    virtual FrameType *setRect(Rect rect) {\
        AbstructFrameObject::setRect(rect);\
        return this;\
    };\
\
    virtual AbstructFrameObject *setRect(int x, int y, int width, int height) {\
        AbstructFrameObject::setRect(Rect(x, y, width, height));\
        return this;\
    };\
    \
    virtual FrameType *setX(int x) {\
        AbstructFrameObject::setX(x);\
        return this;\
    };\
    virtual FrameType *setY(int y) {\
        AbstructFrameObject::setY(y);\
        return this;\
    };\
    virtual FrameType *setPosition(int x, int y) {\
        AbstructFrameObject::setPosition(x, y);\
        return this;\
    };\
    virtual FrameType *setPosition(Point point) {\
        AbstructFrameObject::setPosition(point);\
        return this;\
    };\
    virtual FrameType *setSize(Size size) {\
        AbstructFrameObject::setSize(size);\
        return this;\
    };\
    virtual FrameType *setSize(int width, int height) {\
        AbstructFrameObject::setSize(width, height);\
        return this;\
    };\
    virtual FrameType *setWidth(int width) {\
        AbstructFrameObject::setWidth(width);\
        return this;\
    };\
    virtual FrameType *setHeight(int height) {\
        AbstructFrameObject::setHeight(height);\
        return this;\
    };\
    virtual FrameType *setAutoWidth(bool autoWidth) {\
        AbstructFrameObject::setAutoWidth(autoWidth);\
        return this;\
    };\
    virtual FrameType *setAutoHeight(bool autoHeight) {\
        AbstructFrameObject::setAutoHeight(autoHeight);\
        return this;\
    };\
    virtual FrameType *setMinWidth(int minWidth) {\
        AbstructFrameObject::setMinWidth(minWidth);\
        return this;\
    };\
    virtual FrameType *setMaxWidth(int maxWidth) {\
        AbstructFrameObject::setMaxWidth(maxWidth);\
        return this;\
    };\
    virtual FrameType *setMinHeight(int minHeight) {\
        AbstructFrameObject::setMinHeight(minHeight);\
        return this;\
    };\
    virtual FrameType *setMaxHeight(int maxHeight) {\
        AbstructFrameObject::setMaxHeight(maxHeight);\
        return this;\
    };\
\
    virtual FrameType *setMargin(int left, int right, int top, int bottom) {\
        AbstructFrameObject::setMargin(left, right, top, bottom);\
        return this;\
    };\
    virtual FrameType *setMargin(Margin margin) {\
        AbstructFrameObject::setMargin(margin);\
        return this;\
    };\
\
    virtual FrameType *setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {\
        AbstructFrameObject::setHorizontalAlignment(horizontalAlignment);\
        return this;\
    };\
    virtual FrameType *setVerticalAlignment(VerticalAlignment verticalAlignment) {\
        AbstructFrameObject::setVerticalAlignment(verticalAlignment);\
        return this;\
    };\
\
    virtual FrameType *setAlignment(Alignment alignment) {\
        AbstructFrameObject::setAlignment(alignment);\
        return this; \
    }\
\
    virtual FrameType *setBackground(const Color &background) {\
        AbstructFrameObject::setBackground(background); \
        return this;\
    }\
    virtual FrameType *setForeground(const Color &foreground) {\
        AbstructFrameObject::setForeground(foreground); \
        return this;\
    }\
    virtual FrameType *setText(const String &text) {\
        AbstructFrameObject::setText(text); \
        return this;\
    }\
    virtual FrameType *setLayout(Layout layout) {\
        AbstructFrameObject::setLayout(layout);\
        return this;\
    }\
    virtual FrameType *setBorder(Border border) {\
            AbstructFrameObject::setBorder(border);\
            return this;\
    }\
typedef std::function<void(FrameType*, const MouseEventInfo&)> MouseFunction ## FrameType;\
\
typedef std::function<void()> ActionFunctionVoid ## FrameType;\
typedef std::function<void(FrameType *sender)> ActionFunction ## FrameType;\
\
        virtual FrameType *addMousePressedListener(MouseFunction ## FrameType f) {\
            AbstructFrameObject::addMousePressedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        };\
\
        virtual FrameType *addMouseReleasedListener(MouseFunction ## FrameType f) {\
            AbstructFrameObject::addMouseReleasedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        };\
\
        virtual FrameType *addMouseDraggedListener(MouseFunction ## FrameType f) {\
            AbstructFrameObject::addMouseDraggedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        };\
\
        virtual FrameType *addMouseMovedListener(MouseFunction ## FrameType f) {\
            AbstructFrameObject::addMouseMovedListener([=](AbstructFrameObject *sender, const MouseEventInfo &event){ f((FrameType*)sender, event); });\
            return this;\
        };\
\
\
        virtual FrameType *addActionListener(ActionFunctionVoid buttonFunction) {\
            AbstructFrameObject::addActionListener(buttonFunction);\
            return this;\
        }\
        virtual FrameType*addActionListener(ActionFunction ## FrameType buttonFunction) {\
            AbstructFrameObject::addActionListener([=](AbstructFrameObject *sender){ buttonFunction((FrameType*)sender); });\
            return this;\
        }

        
}