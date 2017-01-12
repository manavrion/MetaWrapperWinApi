#pragma once

#include "Window.h"
#include "Panel.h"
#include "EditorWrapped.h"

namespace MetaFrame {

    class Editor : public Window {


    public:
        Editor(String text) : Window(text), editorSpace(new Panel), panelTool(new Panel)
        {
            setAlignment(Alignment::Center);
            setSize(820 + 230, 420 + 60); 

            add(editorSpace
                ->setSize(820, 420)
                ->setHorizontalAlignment(HorizontalAlignment::Left)
                ->setVerticalAlignment(VerticalAlignment::Center)
                ->setMargin(10, 10, 30, 30));

            add(panelTool
                ->setWidth(200)
                ->setVerticalAlignment(VerticalAlignment::Stretch)
                ->setHorizontalAlignment(HorizontalAlignment::Right)
                ->add((new Label)
                      ->setText(L"Панель инструментов")
                      ->setHorizontalAlignment(HorizontalAlignment::Stretch)
                      ->setVerticalAlignment(VerticalAlignment::Top))
                ->add((new Label)
                      ->setText(L"Panel")
                      ->setWidth(100)
                      ->setHorizontalAlignment(HorizontalAlignment::Left)
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
                      ->setWidth(100)
                      ->setHorizontalAlignment(HorizontalAlignment::Left)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 90, 10))
                ->add((new Button)
                      ->setText(L"Create")
                      ->setHorizontalAlignment(HorizontalAlignment::Right)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 90, 10)
                      ->addActionListener([&]() { this->createButton(); }))
                ->add((new Label)
                      ->setText(L"Label")
                      ->setWidth(100)
                      ->setHorizontalAlignment(HorizontalAlignment::Left)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 130, 10))
                ->add((new Button)
                      ->setText(L"Create")
                      ->setHorizontalAlignment(HorizontalAlignment::Right)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 130, 10)
                      ->addActionListener([&]() { this->createLabel(); }))
                ->add((new Label)
                      ->setText(L"Slider")
                      ->setWidth(100)
                      ->setHorizontalAlignment(HorizontalAlignment::Left)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 170, 10))
                ->add((new Button)
                      ->setText(L"Create")
                      ->setHorizontalAlignment(HorizontalAlignment::Right)
                      ->setVerticalAlignment(VerticalAlignment::Top)
                      ->setMargin(10, 10, 170, 10)
                      ->addActionListener([&]() { this->createSlider(); }))

            );
        };


        void createPanel() {
            EditPanel *panel = new EditPanel;

            panel->addMouseReleasedListener([=](AbstructFrameObject *panel, const MouseEventInfo &event) {
                this->destroyControl();
                this->bindControl(panel->getRect(), (AbstructFrameElement *)panel);
            });

            editorSpace->add(panel);
            panel->build();


            bindControl(panel->getRect(), panel);
        }

        void createButton() {
            EditButton *button = new EditButton;

            button->addMouseReleasedListener([=](AbstructFrameObject *button, const MouseEventInfo &event) {
                this->destroyControl();
                this->bindControl(button->getRect(), (AbstructFrameElement*)button);
            });

            button->setPosition(100, 100);

            editorSpace->add(button);
            button->build();

            bindControl(button->getRect(), button);
        }

        void createSlider() {
            EditSlider *panel = new EditSlider;

            panel->addMouseReleasedListener([=](AbstructFrameObject *panel, const MouseEventInfo &event) {
                this->destroyControl();
                this->bindControl(panel->getRect(), (AbstructFrameElement*)panel);
            });

            editorSpace->add(panel);
            panel->build();


            bindControl(panel->getRect(), panel);
        }

        void createLabel() {
            EditLabel *panel = new EditLabel;

            panel->addMouseReleasedListener([=](AbstructFrameObject *panel, const MouseEventInfo &event) {
                this->destroyControl();
                this->bindControl(panel->getRect(), (AbstructFrameElement*)panel);
            });

            editorSpace->add(panel);
            panel->build();


            bindControl(panel->getRect(), panel);
        }

        void destroyControl();
    protected:
        Panel *editorSpace;
        Panel *panelTool;

        Panel *controlLeft = null;
        Panel *controlRight = null;
        Panel *controlTop = null;
        Panel *controlButtom = null;

        TextField *controlText = null;
        Label *controlLabelText = null;

        Button *controlDeleteButton = null;


        void bindControl(Rect rect, AbstructFrameElement *element);


        

    public:
        ~Editor() {

        };
    };



}