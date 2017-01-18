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

    String initString;


    ~EditAbstructElement() {

    }
};

class EditPanel : public Panel, EditAbstructElement {
public:
    EditPanel() {
        name = L"Panel";


        initString = L"(new Panel)";
    };
    ~EditPanel() {};

};


class EditButton : public Button, EditAbstructElement {
public:
    EditButton() {
        name = L"Edit";

        initString = L"(new Button)";
    };
    ~EditButton() {};

};

class EditSlider : public Slider, EditAbstructElement {
public:
    EditSlider() {
        name = L"Slider";

        initString = L"(new Slider)";
    };
    ~EditSlider() {};

};

class EditLabel : public Label, EditAbstructElement {
public:
    EditLabel() {
        name = L"Label";

        initString = L"(new Label)";
    };
    ~EditLabel() {};
};