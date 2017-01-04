#pragma once

namespace MetaFrame {

    class AbstructFrameElement  {

    public:
        AbstructFrameElement() 
            : x(), y() ,
            width(), height(),
            autoWidth(true), autoHeight(true),
            minWidth(0),  maxWidth(0x7fffFFFF),
            minHeight(0), maxHeight(0x7fffFFFF),
            margin(),
            horizontalAlignment(HorizontalAlignment::Absolute),
            verticalAlignment(VerticalAlignment::Absolute),
            parent(null)
        {};

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
        AbstructFrameElement *add(AbstructFrameElement *child) {
            childs.push_back(child);
            child->parent = this;
            return this;
        };


    public:
        ~AbstructFrameElement() {};

    };

}