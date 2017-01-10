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


            editorSpace->add(controlLeft
                ->setPosition(Point(5000, 5000))
                ->setSize(5, 5));
            editorSpace->add(controlRight
                ->setPosition(Point(5000, 5000))
                ->setSize(5, 5));
            editorSpace->add(controlTop
                ->setPosition(Point(5000, 5000))
                ->setSize(5, 5));
            editorSpace->add(controlButtom
                             ->setPosition(Point(5000, 5000))
                             ->setSize(5, 5));


        };


        void createPanel() {
            Panel *panel = new Panel;

            editorSpace->add(panel);
            panel->build();
           // saveUpdate();

            //setBackground(Color(0, 0, 255));

            bindControl(panel->getRect());
        }

        void createButton() {
            Button *button = new Button;

            button->addActionListener([=]() {
                button->setX(button->getX() + 2); 
            });

            button->setPosition(100, 100);

            editorSpace->add(button);
            button->build();
            //saveUpdate();

            //setBackground(Color(0, 0, 255));

            bindControl(button->getRect());
        }

        
    protected:
        Panel *editorSpace;

        Panel *controlLeft = new Panel;
        Panel *controlRight = new Panel;
        Panel *controlTop = new Panel;
        Panel *controlButtom = new Panel;


        void bindControl(Rect rect) {
            
            controlLeft->setPosition(Point(rect.x - 2, rect.y + rect.height/2 - 2));

            controlRight->setPosition(Point(rect.x + rect.width - 2, rect.y + rect.height / 2 - 3));

            controlTop->setPosition(Point(rect.x + rect.width / 2 - 2, rect.y - 2));

            controlButtom->setPosition(Point(rect.x + rect.width / 2 - 2, rect.y + rect.height - 2));
            
            //editorSpace->saveUpdate();
        }


    public:
        ~Editor() {

        };
    };



}