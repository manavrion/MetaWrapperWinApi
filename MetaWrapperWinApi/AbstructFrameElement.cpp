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
                            int newWidth = width - child->margin.right - child->margin.left;
                            newWidth = max(newWidth, child->minWidth);
                            newWidth = min(newWidth, child->maxWidth);

                            child->setWidth(newWidth);
                        }
                        child->setX(child->margin.left);
                        break;
                    }
                    case MetaFrame::HorizontalAlignment::Right:
                    {
                        if (child->autoWidth) {
                            int newWidth = width - child->margin.right - child->margin.left;
                            newWidth = max(newWidth, child->minWidth);
                            newWidth = min(newWidth, child->maxWidth);

                            child->setWidth(newWidth);
                        }
                        child->setX(width - child->width - child->margin.right);
                        break;
                    }
                    case MetaFrame::HorizontalAlignment::Center:
                    {
                        child->autoWidth = false;
                        int freeSpace = width - child->width;
                        child->setX(freeSpace / 2);
                        break;
                    }
                    case MetaFrame::HorizontalAlignment::Stretch:
                    {
                        child->autoWidth = true;
                        if (child->autoWidth) {
                            int newWidth = width - child->margin.right - child->margin.left;
                            newWidth = max(newWidth, child->minWidth);
                            newWidth = min(newWidth, child->maxWidth);

                            child->setWidth(newWidth);
                        }
                        int freeSpace = width - child->width;
                        child->setX(freeSpace / 2);
                        break;
                    }
                }
                //OK
                switch (child->verticalAlignment) {
                    case MetaFrame::VerticalAlignment::Absolute:
                        break;
                    case MetaFrame::VerticalAlignment::Top:
                    {
                        if (child->autoHeight) {
                            int newHeight = height - child->margin.bottom - child->margin.top;
                            newHeight = max(newHeight, child->minHeight);
                            newHeight = min(newHeight, child->maxHeight);

                            child->setHeight(newHeight);
                        }
                        child->setY(child->margin.top);
                        break;
                    }
                    case MetaFrame::VerticalAlignment::Bottom:
                    {
                        if (child->autoHeight) {
                            int newHeight = height - child->margin.bottom - child->margin.top;
                            newHeight = max(newHeight, child->minHeight);
                            newHeight = min(newHeight, child->maxHeight);

                            child->setHeight(newHeight);
                        }
                        child->setY(height - child->height - child->margin.bottom);
                        break;
                    }
                    case MetaFrame::VerticalAlignment::Center:
                    {
                        child->autoHeight = false;
                        int freeSpace = height - child->height;
                        child->setY(freeSpace / 2);
                        break;
                    }
                    case MetaFrame::VerticalAlignment::Stretch:
                    {
                        child->autoHeight = true;

                        if (child->autoHeight) {
                            int newHeight = height - child->margin.bottom - child->margin.top;
                            newHeight = max(newHeight, child->minHeight);
                            newHeight = min(newHeight, child->maxHeight);

                            child->setHeight(newHeight);
                        }
                        int freeSpace = height - child->height;
                        child->setY(freeSpace / 2);
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
