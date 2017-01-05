#include "stdafx.h"
#include "AbstructFrameElement.h"

#include "Button.h"

AbstructFrameElement & MetaFrame::AbstructFrameElement::add(const Button &child) {
    Button *newChild = new Button(child);
    newChild->parent = this;
    childs.push_back(newChild);
    return *this;
}
