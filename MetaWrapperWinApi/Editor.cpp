#include "stdafx.h"
#include "Editor.h"
#include "Controllers.h"

#include <fstream>

namespace MetaFrame {

    static Controllers *control;

    std::ifstream cin("main.h");  std::ofstream cout("main.h");


    Editor::Editor(String text) 
        : Window(text), 
        editorSpace(new Panel), 
        panelTool(new Panel) 
    {

        control = new Controllers(this, editorSpace, panelTool);

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
            ->add((new Button)
                  ->setText(L"Сохранить")
                  ->setPosition(10, 26)
                  ->addActionListener([]() {
                        
                  })
            )
            ->add((new Button)
                  ->setText(L"Загрузить")
                  ->setPosition(90, 26)
            )
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
                  ->addActionListener([&]() {
                      createFrame(new EditPanel);
                  }))
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
                  ->addActionListener([&]() { 
                      createFrame(new EditButton);
                  }))
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
                  ->addActionListener([&]() { 
                      createFrame(new EditLabel);
                  }))
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
                  ->addActionListener([&]() { 
                      createFrame(new EditSlider);
                  }))

        );
    }

    void Editor::createFrame(FrameObject *frameObject) {
        frameObject->setPosition(100, 100);

        control->insertFrame->add(frameObject);
        frameObject->build();

        control->rebind(frameObject);

    }    


     Editor::~Editor() {

     }

}