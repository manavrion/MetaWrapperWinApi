#pragma once

#include "Window.h"
#include "Panel.h"

namespace MetaFrame {

    class Editor : public Window {


    public:
        Editor(String text) : Window(text), editorSpace(new Panel)
        {
            setAlignment(Alignment::Center);
            setSize(820 + 230, 420 + 60); 

            add(editorSpace
                ->setSize(820, 420)
                ->setHorizontalAlignment(HorizontalAlignment::Left)
                ->setVerticalAlignment(VerticalAlignment::Center)
                ->setMargin(10, 10, 30, 30));

            add((new Panel)
                ->setWidth(200)
                ->setVerticalAlignment(VerticalAlignment::Stretch)
                ->setHorizontalAlignment(HorizontalAlignment::Right)
                ->add((new Label)
                      ->setText(L"Панель инструментов")
                      ->setHorizontalAlignment(HorizontalAlignment::Stretch)
                      ->setVerticalAlignment(VerticalAlignment::Top))
                ->add((new Label)
                      ->setText(L"Panel")
                      ->setHorizontalAlignment(HorizontalAlignment::Stretch)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 50, 10))
                ->add((new Button)
                      ->setText(L"Create")
                      ->setHorizontalAlignment(HorizontalAlignment::Right)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 50, 10)
                      ->addActionListener([&]() {this->createPanel(); }))
                ->add((new Label)
                      ->setText(L"Button")
                      ->setHorizontalAlignment(HorizontalAlignment::Stretch)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 90, 10))
                ->add((new Button)
                      ->setText(L"Create")
                      ->setHorizontalAlignment(HorizontalAlignment::Right)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 90, 10)
                      ->addActionListener([&]() { this->createButton(); })));
        };


        void createPanel() {
            Panel *panel = new Panel;

            /*panel->addMouseMovedListener([](NativeAbstructObject &panel, const MouseEvent &event) {
                panel.setX(event.x);
                panel.setY(event.y);
            });*/

            editorSpace->add(panel);
            panel->build();
           // saveUpdate();

            //setBackground(Color(0, 0, 255));

            bindControl(panel->getRect(), panel);
        }

        void createButton() {
            Button *button = new Button;

            button->addActionListener([=]() {
                button->setX(button->getX() + 2); 
            });

            button->setPosition(100, 100);

            editorSpace->add(button);
            button->build();

            bindControl(button->getRect(), button);
        }

        
    protected:
        Panel *editorSpace;

        Panel *controlLeft = null;
        Panel *controlRight = null;
        Panel *controlTop = null;
        Panel *controlButtom = null;


        void bindControl(Rect rect, AbstructFrameElement *element);


    public:
        ~Editor() {

        };
    };



}