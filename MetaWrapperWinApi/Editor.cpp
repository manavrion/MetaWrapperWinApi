#include "stdafx.h"
#include "Editor.h"
#include "Controllers.h"

#include <fstream>

namespace MetaFrame {

    static Controllers *control;

    


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
                  ->addActionListener([=]() {
                        save();
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
                      FrameObject *obj = new Panel;
                      obj->initString = L"(new Panel)";
                      createFrame(obj);
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
                      FrameObject *obj = new Button;
                      obj->initString = L"(new Button)";
                      createFrame(obj);
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
                      FrameObject *obj = new Label;
                      obj->initString = L"(new Label)";
                      createFrame(obj);
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
                      FrameObject *obj = new Slider;
                      obj->initString = L"(new Slider)";
                      createFrame(obj);
                  }))

        );
    }

    void Editor::createFrame(FrameObject *frameObject) {
        frameObject->setPosition(control->insertFrame->getWidth()/2 - frameObject->getWidth()/2, control->insertFrame->getHeight()/2 - frameObject->getHeight() / 2);

        control->insertFrame->add(frameObject);
        frameObject->build();

        control->rebind(frameObject);

    }    


    void Editor::save() {
        editorSpace->setText(L"Generated kek window");
        //std::ifstream cin("sample.h");  
        std::ofstream cout("sample.h");

        control->clearBind();

        //cout.clear();
        String ret;

        ret += L"#include \"MFTafx.h\"\n";

        ret += L"\n";
        ret += L"\n";
        ret += L"\n";
        ret += L"int tmain(){\n";

        ret += L"    Window *gnwindow = new Window(L\"Generated kek window\");\n";

        ret += L"\n";
        ret += L"\n";

        ret += L"    //begin auto gen\n";
        ret += L"    gnwindow" + editorSpace->getInit() + L";\n";
        ret += L"    //end auto gen\n";


        ret += L"\n";
        ret += L"\n";

        ret += L"    gnwindow->run();\n";
        ret += L"    delete gnwindow;\n";
        

        ret += L"\n";
        ret += L"\n";
        ret += L"    return 0;\n";

        ret += L"}\n";

        cout << (std::string)ret;

        cout.close();

        editorSpace->setText(L"");
        editorSpace->repaint();
    }

    Editor::~Editor() {

     }

}