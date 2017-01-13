#pragma once

#include "Panel.h"
#include "Control.h"

namespace MetaFrame {

    class PanelProperty : public Panel {
    public:
        PanelProperty(ArrayList<Control *> *controls) : controls(controls) {
            createPanel();
        };

    private:
        ArrayList<Control *> *controls;

        
        void createPanel() {

            add((new Label)
                ->setText(L"Свойства")
                ->setHorizontalAlignment(HorizontalAlignment::Center)
                ->setHeight(14)
            );

            TextField *textFieldText = new TextField;
            add((new Label)
                ->setText(L"Текст:")
                ->setHorizontalAlignment(HorizontalAlignment::Left)
                ->setY(30)
                ->setWidth(34)
            );
            add(textFieldText
                ->setHorizontalAlignment(HorizontalAlignment::Right)
                ->setY(30)
                ->setWidth(100)
                ->setBorder(Border::SOFT_BEVEL)
                ->setText(controls->size() == 1 ? controls->front()->captured->getText() : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for(auto ob : *controls){
                        ob->captured->setText(tf->getText());
                    }
                })
            );

            if (controls->size() == 1) {
                controls->front()->captured->addPropertyChangedListener([=](FrameObject *ob) {
                    textFieldText->setText(ob->getText());
                });
            }



            TextField *textFieldPosX = new TextField;
            TextField *textFieldPosY = new TextField;

            add((new Label)
                ->setText(L"Положение:")
                ->setHorizontalAlignment(HorizontalAlignment::Left)
                ->setY(50)
            );
            add(textFieldPosX
                ->setPosition(100,50)
                ->setWidth(30)
                ->setBorder(Border::SOFT_BEVEL)
                ->setText(controls->size() == 1 ? String(controls->front()->captured->getX()) : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for (auto ob : *controls) {
                        ob->captured->setX(tf->getText().toValueInt());
                    }
                })
            );
            add(textFieldPosY
                ->setPosition(140, 50)
                ->setWidth(30)
                ->setBorder(Border::SOFT_BEVEL)
                ->setText(controls->size() == 1 ? String(controls->front()->captured->getY()) : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for (auto ob : *controls) {
                        ob->captured->setY(tf->getText().toValueInt());
                    }
                })
            );
            if (controls->size() == 1) {
                controls->front()->captured->addPropertyChangedListener([=](FrameObject *ob) {
                    textFieldPosX->setText(ob->getX());
                    textFieldPosY->setText(ob->getY());
                });
            }
            


            TextField *textFieldWidth = new TextField;
            TextField *textFieldHeight = new TextField;

            add((new Label)
                ->setText(L"Размер:")
                ->setHorizontalAlignment(HorizontalAlignment::Left)
                ->setY(70)
            );
            add(textFieldWidth
                ->setPosition(100, 70)
                ->setWidth(30)
                ->setBorder(Border::SOFT_BEVEL)
                ->setText(controls->size() == 1 ? String(controls->front()->captured->getWidth()) : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for (auto ob : *controls) {
                        ob->captured->setWidth(tf->getText().toValueInt());
                    }
                })
            );
            add(textFieldHeight
                ->setPosition(140, 70)
                ->setWidth(30)
                ->setBorder(Border::SOFT_BEVEL)
                ->setText(controls->size() == 1 ? String(controls->front()->captured->getHeight()) : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for (auto ob : *controls) {
                        ob->captured->setHeight(tf->getText().toValueInt());
                        
                    }
                })
            );


            for (auto ob : *controls) {
                ob->captured->addPropertyChangedListener([=](FrameObject *frameObject) {
                    for (auto ob : *controls) {
                        if (frameObject->getWidth() != ob->captured->getWidth()) {
                            return;
                        }
                    }
                    textFieldWidth->setText(ob->captured->getWidth());
                    textFieldHeight->setText(ob->captured->getHeight());
                });
            }

            if (controls->size() == 1) {
                controls->front()->captured->addPropertyChangedListener([=](FrameObject *ob) {
                    textFieldWidth->setText(ob->getWidth());
                    textFieldHeight->setText(ob->getHeight());
                });
            }




        };




    public:
        ~PanelProperty() {

        };

    };



}