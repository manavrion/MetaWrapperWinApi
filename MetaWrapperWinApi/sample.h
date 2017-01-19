#include "MFTafx.h"



int tmain(){
    Window *gnwindow = new Window(L"Generated kek window");


    //begin auto gen
    gnwindow->setProperty(10, 30, 820, 420, L"Generated kek window")->add((new Panel)->setProperty(79, 103, 166, 156, L"")->add((new Panel)->setProperty(47, 68, 73, 21, L"")))->add((new Button)->setProperty(384, 206, 73, 21, L""))->add((new Button)->setProperty(381, 133, 73, 21, L""));
    //end auto gen


    gnwindow->run();
    delete gnwindow;


    return 0;
}
