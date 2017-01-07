#include "stdafx.h"
#include "AbstructFrameElement.h"

#include "Button.h"

void MetaFrame::AbstructFrameElement::packEvent() {

    for (auto &child : childs) {
        switch (layout) {
            case MetaFrame::Layout::Absolute:
            {
                break;
            }
            case MetaFrame::Layout::Simple:
            {

                switch (child->horizontalAlignment) {
                    case MetaFrame::HorizontalAlignment::Absolute:
                        break;
                    case MetaFrame::HorizontalAlignment::Left:
                    {
                        if (child->autoWidth) {


                        } else {
                            child->y = child->margin.left;
                        }
                        break;
                    }
                    case MetaFrame::HorizontalAlignment::Center:
                    {
                        if (child->autoWidth) {
                            child->x = child->margin.left;
                            child->width = width - child->margin.right - child->margin.left;
                        } else {
                            int freeSpace = abs(width - child->width);
                            child->x = freeSpace / 2;
                        }
                        break;
                    }
                    case MetaFrame::HorizontalAlignment::Right:
                    {
                        if (child->autoWidth) {


                        } else {
                            child->x = width - child->width - child->margin.right;
                        }
                        break;
                    }
                    case MetaFrame::HorizontalAlignment::Stretch:
                    {
                        if (child->autoWidth) {
                            child->x = child->margin.left;
                            child->width = width - child->margin.right - child->margin.right;
                        } else {

                        }
                        break;
                    }
                }

                switch (child->verticalAlignment) {
                    case MetaFrame::VerticalAlignment::Absolute:
                        break;
                    case MetaFrame::VerticalAlignment::Top:
                    {
                        /*if (child->autoHeight) {
                        child->y = child->margin.top;
                        child->height = height - child->margin.bottom - child->margin.top;
                        } else {
                        int freeSpace = abs(height - child->height);
                        child->y = freeSpace / 2;
                        }*/
                    }
                    case MetaFrame::VerticalAlignment::Center:
                    {
                        if (child->autoHeight) {
                            child->y = child->margin.top;
                            child->height = height - child->margin.bottom - child->margin.top;
                        } else {
                            int freeSpace = abs(height - child->height);
                            child->y = freeSpace / 2;
                        }
                        break;
                    }
                    case MetaFrame::VerticalAlignment::Bottom:
                    {
                        if (child->autoHeight) {
                            /*child->y = child->margin.top;
                            child->height = height - child->margin.bottom - child->margin.top;*/
                        } else {
                            child->y = height - child->height - child->margin.bottom;
                        }
                        break;
                    }
                    case MetaFrame::VerticalAlignment::Stretch:
                    {
                        if (child->autoHeight) {
                            child->y = child->margin.top;
                            child->height = height - child->margin.bottom - child->margin.top;
                        } else {

                        }
                        break;
                    }
                }

                break;
            }
            default:
                break;
        }
    }


}
