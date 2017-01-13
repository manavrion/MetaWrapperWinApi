#pragma once

#include "Panel.h"

namespace MetaFrame {

    class PanelProperty : public Panel {
    public:
        PanelProperty(FrameObject *captured) {
            captures.push_back(captured);
            createPanel();
        };
        PanelProperty(vector<FrameObject *> captured) {
            captures = captured;
            createPanel();
        };

    private:
        vector<FrameObject *> captures;

        
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
                ->setText(captures.size() == 1 ? captures.front()->getText() : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for(auto ob : captures){
                        ob->setText(tf->getText());
                    }
                })
            );
            if (captures.size() == 1) {
                captures.front()->addPropertyChangedListener([=](FrameObject *ob) {
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
                ->setText(captures.size() == 1 ? String(captures.front()->getX()) : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for (auto ob : captures) {
                        ob->setX(tf->getText().toValueInt());
                    }
                })
            );
            add(textFieldPosY
                ->setPosition(140, 50)
                ->setWidth(30)
                ->setBorder(Border::SOFT_BEVEL)
                ->setText(captures.size() == 1 ? String(captures.front()->getY()) : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for (auto ob : captures) {
                        ob->setY(tf->getText().toValueInt());
                    }
                })
            );
            if (captures.size() == 1) {
                captures.front()->addPropertyChangedListener([=](FrameObject *ob) {
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
                ->setText(captures.size() == 1 ? String(captures.front()->getWidth()) : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for (auto ob : captures) {
                        ob->setWidth(tf->getText().toValueInt());
                    }
                })
            );
            add(textFieldHeight
                ->setPosition(140, 70)
                ->setWidth(30)
                ->setBorder(Border::SOFT_BEVEL)
                ->setText(captures.size() == 1 ? String(captures.front()->getHeight()) : L"--")
                ->addActionListener([=](TextField *tf) {
                    if (tf->getText() == L"--") {
                        return;
                    }
                    for (auto ob : captures) {
                        ob->setHeight(tf->getText().toValueInt());
                    }
                })
            );

            if (captures.size() == 1) {
                captures.front()->addPropertyChangedListener([=](FrameObject *ob) {
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