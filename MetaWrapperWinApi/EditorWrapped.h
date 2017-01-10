#pragma once

#include "Panel.h"
#include "Button.h"
#include "Slider.h"
#include "Label.h"


class EditAbstructElement {
public:
    EditAbstructElement() {

    }
    String name;




    ~EditAbstructElement() {

    }
};

class EditPanel : public Panel, EditAbstructElement {
public:
    EditPanel() {
        name = L"Panel";
    };
    ~EditPanel() {};

};


class EditButton : public Button, EditAbstructElement {
public:
    EditButton() {
        name = L"Edit";
    };
    ~EditButton() {};

};

class EditSlider : public Slider, EditAbstructElement {
public:
    EditSlider() {
        name = L"Slider";
    };
    ~EditSlider() {};

};

class EditLabel : public Label, EditAbstructElement {
public:
    EditLabel() {
        name = L"Label";
    };
    ~EditLabel() {};
};