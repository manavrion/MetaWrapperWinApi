#include "stdafx.h"
#include "Editor.h"
#include "Controllers.h"

#include <fstream>

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
        case WM_INITDIALOG:
            return (INT_PTR)TRUE;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;
            }
            break;
    }
    return (INT_PTR)FALSE;
}





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
                  ->addActionListener([=]() {
                      load();
                  })
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
            ->add((new Button)
                  ->setText(L"О программе")
                  ->setHorizontalAlignment(HorizontalAlignment::Right)
                  ->setVerticalAlignment(VerticalAlignment::Top)
                  ->setWidth(130)
                  ->setMargin(10, 10, 220, 10)
                  ->addActionListener([=]() { 
                      DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_ABOUTBOX), this->getHWindow(), About);
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




    String s;
    struct Prop {
        int x, y, w, h;
        String text;
    };


    int nextInt() {
        String ret;
        while (!s.empty()) {
            if (!isalnum(s.front())) {
                s.erase(0, 1);
            } else {
                break;
            }
        }
        while (!s.empty()) {            
            if (isalnum(s.front())) {
                ret += s.front();
                s.erase(0, 1);
            } else {
                break;
            }
        }
        return ret.toValueInt();
    }

    String nextStr() {
        String ret;
        while (!s.empty()) {
            if (s.front() != L'L') {
                s.erase(0, 1);
            } else {
                s.erase(0, 1);
                s.erase(0, 1);
                break;
            }
        }
        while (!s.empty()) {
            if (s.front() != L'\"') {
                ret += s.front();
                s.erase(0, 1);
            } else {
                s.erase(0, 1);
                s.erase(0, 1);
                break;
            }
        }
        return ret;
    }


    Prop nextProperty() {
        s.erase(0, s.find(L"setProperty(") + 12);

        Prop p;

        p.x = nextInt();
        p.y = nextInt();
        p.w = nextInt();
        p.h = nextInt();
        p.text = nextStr();
        return p;
    }


    void loadelem(FrameObject *editorSpace) {
        FrameObject *obj;

        s.erase(0, 5);
        if (s.front() == L'P') {
            obj = new Panel;
            obj->initString = L"(new Panel)";
        } else
        if (s.front() == L'B') {
            obj = new Button;
            obj->initString = L"(new Button)";
        } else
        if (s.front() == L'L') {
            obj = new Label;
            obj->initString = L"(new Label)";
        } else
        if (s.front() == L'S') {
            obj = new Slider;
            obj->initString = L"(new Slider)";
        } else {
            return;
        }

        Prop p = nextProperty();

        obj->setRect(Rect(p.x, p.y, p.w, p.h));
        obj->setText(p.text);

        editorSpace->add(obj);

        if (s.front() != L';') {
            while (s.front() == L'-') {
                s.erase(0, s.find(L"->add(") + 6);

                loadelem(obj);
            }
        }
        s.erase(0, 1);

    };

    void Editor::load() {
        control->clearBind();
        while (!editorSpace->getChilds().empty()) {
            delete editorSpace->getChilds().front();
        }

        std::ifstream cin("sample.h");

        //begin auto gen

        std::string ss;
        while (cin.eof()== false) {
            std::string t;
            cin >> t;
            ss += t + " ";
        }
        
        s.clear();
        for (auto ch : ss) {
            s.push_back(ch);
        }

        s.erase(0, s.find(L"begin auto gen") + 15);
        s.erase(s.find(L"//end auto gen"), s.size() - s.find(L"//end auto gen"));
             

        Prop p = nextProperty();        
        editorSpace->setRect(Rect(p.x, p.y, p.w, p.h));

        if (s.front() != L';') {
            while (s.front() == L'-') {
                s.erase(0, s.find(L"->add(") + 6);

                loadelem(editorSpace);
            }
        }
        s.erase(0, 1);

        editorSpace->build();
        editorSpace->repaint();

        cin.close();


        control->allBind();
    }








    Editor::~Editor() {

     }

}