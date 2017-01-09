// MetaWrapperWinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

Game *game;

DWORD WINAPI threadGame(LPVOID t) {
    Sleep(500);
    while (game->updateThread()) {  
    }
    return 0;
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    Window *window = new Window(L"Kek Microsystems");

    PanelQueue *panelQueue = new PanelQueue;
    PanelRepare *panelRepare = new PanelRepare;

    Panel *panelController = new Panel;

    Logger *logger = new Logger;

    Label *labelSimulationTime = new Label;

    Slider *sliderspeed = new Slider;

    game = new Game(logger, panelRepare, panelQueue, labelSimulationTime, sliderspeed);

    Panel *panelMenu = new Panel;
    PanelUsersCreator *panelUsersCreator = new PanelUsersCreator(game);
    PanelWorkersCreator *panelWorkersCreator = new PanelWorkersCreator(game);
    Panel *panelLogger = new Panel;



    Label *labelspeed = new Label;





    
    panelMenu
        ->add((new Label())
             ->setVerticalAlignment(VerticalAlignment::Top)
             ->setHorizontalAlignment(HorizontalAlignment::Left)
             ->setWidth(120)
             ->setMargin(10, 10, 50, 10)
             ->setText(L"Время в симуляции:"))
        ->add(labelSimulationTime
             ->setVerticalAlignment(VerticalAlignment::Top)
             ->setHorizontalAlignment(HorizontalAlignment::Left)
             ->setAutoWidth(true)
             ->setMargin(10, 10, 70, 10)
             ->setText(L"0 месяц, 0 день, 00:00"))
        ->add((new Label())
             ->setVerticalAlignment(VerticalAlignment::Top)
             ->setHorizontalAlignment(HorizontalAlignment::Left)
             ->setWidth(120)
             ->setMargin(10, 10, 100, 10)
             ->setText(L"Скорость симуляции:"))
        ->add(labelspeed
             ->setVerticalAlignment(VerticalAlignment::Top)
             ->setHorizontalAlignment(HorizontalAlignment::Right)
             ->setWidth(30)
             ->setMargin(10, 10, 100, 10)
             ->setText(L"x0"))
        ->add(sliderspeed
             ->setVerticalAlignment(VerticalAlignment::Top)
             ->setHorizontalAlignment(HorizontalAlignment::Center)
             ->setWidth(180)
             ->setHeight(50)
             ->setMargin(10, 10, 120, 10)
             ->addActionListener([&](Slider &sl) {
                labelspeed->setText(String(L"x") + String(sl.getPos()));
             })
        );



    panelLogger
        ->add((new Label())
             ->setAlignment(Alignment::Stretch)
             ->setMargin(5, 5, 5, 5)
             ->setText(L"Логгер:"))
        ->add(logger);

    window
        ->setAlignment(Alignment::Center)
        ->setSize(820, 420)
        ->add(panelController
             ->setBorder(Border::SOFT_BEVEL)
             ->setHorizontalAlignment(HorizontalAlignment::Stretch)
             ->setVerticalAlignment(VerticalAlignment::Top)
             //.setMargin(10, 10, 10, 220)
             ->setHeight(190)
             ->setLayout(Layout::HorizontalStack)
             ->add(panelMenu->setAlignment(Alignment::Stretch))
             ->add(panelUsersCreator->setAlignment(Alignment::Stretch))
             ->add(panelWorkersCreator->setAlignment(Alignment::Stretch))
             ->add(panelLogger->setAlignment(Alignment::Stretch)))
        ->add(panelQueue)
        ->add(panelRepare)
        ->add((new Button())
             ->setText(L"О программе")
             ->setWidth(100)
             ->setVerticalAlignment(VerticalAlignment::Bottom)
             ->setHorizontalAlignment(HorizontalAlignment::Right)
             ->addActionListener([&]() { DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_ABOUTBOX), window->getHWindow(), About); }))
        ->add((new Label())
             ->setText(L"Выручка: 2000$")
             ->setWidth(100)
             ->setVerticalAlignment(VerticalAlignment::Bottom)
             ->setHorizontalAlignment(HorizontalAlignment::Left));
        ;

    HANDLE threadr = CreateThread(NULL, 0, threadGame, NULL, 0, NULL);
    //window.pack();
    window->run();



    return 0;
}



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


