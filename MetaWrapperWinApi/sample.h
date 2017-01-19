#include "MFTafx.h"



int tmain(){
    Window *gnwindow = new Window(L"Generated kek window");


    //begin auto gen
    gnwindow->setProperty(10, 30, 820, 420, L"Generated kek window")->add((new Panel)->setProperty(548, 255, 73, 21, L"")->add((new Button)->setProperty(-152, 27, 73, 21, L"")))->add((new Label)->setProperty(195, 254, 73, 21, L""))->add((new Button)->setProperty(432, 305, 73, 21, L""));
    //end auto gen


    gnwindow->run();
    delete gnwindow;


    return 0;
}
