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


    if (layout == MetaFrame::Layout::HorizontalStack && !childs.empty()) {

        for (auto child : childs) {
            child->autoHeight = true;

            if (child->autoHeight) {
                int newHeight = height - child->margin.bottom - child->margin.top;
                newHeight = max(newHeight, child->minHeight);
                newHeight = min(newHeight, child->maxHeight);

                child->setHeight(newHeight);
            }
            int freeSpace = height - child->height;
            child->setY(freeSpace / 2);
        }

        //scaling size
        
        int marginsSize = 0;
        int widthSize = 0;
        ArrayList<AbstructFrameElement*> resizeble;

        auto it = childs.begin();
        auto prev = childs.begin();

        if ((*it)->autoWidth == true) {
            resizeble.push_back(*it);
        }
        marginsSize += (*it)->margin.left;
        widthSize += (*it)->width;
        for (it++; it != childs.end(); it++) {
            widthSize += (*it)->width;
            if ((*it)->autoWidth == true) {
                resizeble.push_back(*it);
            }
            marginsSize += max((*it)->margin.left, (*prev)->margin.right);

            prev = it;
        }

        marginsSize += (*prev)->margin.right;

        
        //resize if possible
        int need = width - marginsSize - widthSize;
        ArrayList<AbstructFrameElement*> resizebleNew;
        while (!resizeble.empty()) {

            int dx = need / (int)resizeble.size();
            if (dx == 0) {
                break;
            }
            for (auto &child : childs) {
                int oldW = child->width;
                child->width += dx;
                child->width = min(child->width, child->maxWidth);
                child->width = max(child->width, child->minWidth);
                int realDx = oldW - child->width;
                need += realDx;
                if (child->width != child->maxWidth && child->width != child->minWidth) {
                    resizebleNew.push_back(child);
                }
            }

            swap(resizeble, resizebleNew);
        }

        //resize proc
        {
            int sizePos = 0;

            auto it = childs.begin();
            auto prev = childs.begin();


            sizePos += (*it)->margin.left;
            (*it)->setX(sizePos);
            (*it)->setWidth((*it)->width);
            sizePos += (*it)->width;

            for (it++; it != childs.end(); it++) {

                if ((*it)->autoWidth == true) {
                    sizePos += max((*it)->margin.left, (*prev)->margin.right);
                    (*it)->setX(sizePos);
                    (*it)->setWidth((*it)->width);
                    sizePos += (*it)->width;
                    prev = it;
                }
                
            }


        }


    }




}
