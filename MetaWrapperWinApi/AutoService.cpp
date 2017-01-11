#include "stdafx.h"
#include "AutoService.h"

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


static Game *gamePtr;

DWORD WINAPI threadGame(LPVOID t);

AutoService::AutoService(String taxt) : Window(taxt) {
    game = new Game(logger, panelRepare, panelQueue, labelSimulationTime, sliderspeed, labelMoney);
    gamePtr = game;

    panelUsersCreator = new PanelUsersCreator(game);
    panelWorkersCreator = new PanelWorkersCreator(game);

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
              ->addActionListener([&](NativeAbstructObject *sl) {
                    labelspeed->setText(String(L"x") + String(((Slider*)sl)->getPos()));
                })
        );

    panelLogger
        ->add((new Label())
              ->setHorizontalAlignment(HorizontalAlignment::Stretch)
              ->setVerticalAlignment(VerticalAlignment::Top)
              ->setMargin(5, 5, 5, 5)
              ->setText(L"Логгер:"))
        ->add(logger);

     
    setAlignment(Alignment::Center);
    setSize(820, 420);
    add(panelController
        ->setBorder(Border::SOFT_BEVEL)
        ->setHorizontalAlignment(HorizontalAlignment::Stretch)
        ->setVerticalAlignment(VerticalAlignment::Top)
        //.setMargin(10, 10, 10, 220)
        ->setHeight(190)
        ->setLayout(Layout::HorizontalStack)
        ->add(panelMenu->setAlignment(Alignment::Stretch))
        ->add(panelUsersCreator->setAlignment(Alignment::Stretch))
        ->add(panelWorkersCreator->setAlignment(Alignment::Stretch))
        ->add(panelLogger->setAlignment(Alignment::Stretch)));
    add(panelQueue);
    add(panelRepare);
     
    add(labelMoney
        ->setText(L"Выручка: 0$")
        ->setWidth(300)
        ->setVerticalAlignment(VerticalAlignment::Bottom)
        ->setHorizontalAlignment(HorizontalAlignment::Left));
     add((new Button())
         ->setText(L"О программе")
         ->setWidth(100)
         ->setVerticalAlignment(VerticalAlignment::Bottom)
         ->setHorizontalAlignment(HorizontalAlignment::Right)
         ->addActionListener([&]() {
                   DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_ABOUTBOX), this->getHWindow(), About);
          }));

     HANDLE threadr = CreateThread(NULL, 0, threadGame, NULL, 0, NULL);

}


AutoService::~AutoService() {

}




DWORD WINAPI threadGame(LPVOID t) {
    Sleep(500);
    while (gamePtr->updateThread()) {
        Sleep(1);
    }
    return 0;
};



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