// MetaWrapperWinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"

#include "Client.h"
#include "Worker.h"

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

Window nativeWindow(L"Kek Microsystems");

Panel panelQueue;
Panel panelRepare;

Panel panelController;

Panel panelMenu;
Panel panelUsersCreator;
Panel panelWorkersCreator;
Panel panelLogger;


bool autoGenClients = false;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    
    panelMenu.add(Label()
                  .setVerticalAlignment(VerticalAlignment::Top)
                  .setHorizontalAlignment(HorizontalAlignment::Center)
                  .setWidth(120)
                  .setMargin(10, 10, 120, 10)
                  .setText(L"Скорость симуляции:"));


    panelUsersCreator
        .add(Label()
             .setAlignment(Alignment::Stretch)
             .setMargin(5, 5, 5, 5)
             .setText(L"Создание клиентов:"))
        .add(CheckBox()
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setAutoWidth(true)
             .setMargin(5, 5, 30, 5)
             .setText(L"Автогенерация клиентов")
             .addActionListener([&](CheckBox &cb) { 
                 autoGenClients = cb.getState(); 
             }))
        .add(Label()
             .setText(L"Клиент:")
             .setAlignment(Alignment::Absolute)
             .setPosition(5, 60))
        .add(TextField()
             .setVerticalAlignment(VerticalAlignment::Absolute)
             .setY(60)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setAutoWidth(true)
             .setMargin(50, 5, 5, 5))


    ;

    panelWorkersCreator.add(Label()
                            .setAlignment(Alignment::Stretch)
                            .setMargin(5, 5, 5, 5)
                          .setText(L"Создание работников:"));

    panelLogger.add(Label()
                    .setAlignment(Alignment::Stretch)
                    .setMargin(5, 5, 5, 5)
                    .setText(L"Логгер:"));

    nativeWindow
        .setAlignment(Alignment::Center)
        .setSize(800, 400)
        .add(panelController
             .setBorder(Border::SOFT_BEVEL)
             .setHorizontalAlignment(HorizontalAlignment::Stretch)
             .setVerticalAlignment(VerticalAlignment::Top)
             .setMargin(10, 10, 10, 180)
             .setAutoHeight(true)
             .setLayout(Layout::HorizontalStack)
             .add(panelMenu.setAlignment(Alignment::Stretch))
             .add(panelUsersCreator.setAlignment(Alignment::Stretch))
             .add(panelWorkersCreator.setAlignment(Alignment::Stretch))
             .add(panelLogger.setAlignment(Alignment::Stretch)))
        .add(panelRepare
             .setText(L"Починка")
             .setHeight(80)
             .setHorizontalAlignment(HorizontalAlignment::Stretch)
             .setVerticalAlignment(VerticalAlignment::Bottom)
             .setMargin(10, 10, 10, 40))
        .add(panelQueue
             .setText(L"Очередь")
             .setHeight(40)
             .setHorizontalAlignment(HorizontalAlignment::Stretch)
             .setVerticalAlignment(VerticalAlignment::Bottom)
             .setMargin(10, 10, 10, 130))
        .add(Button()
             .setText(L"О программе")
             .setWidth(100)
             .setVerticalAlignment(VerticalAlignment::Bottom)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .addActionListener([](Button &btn) { /*DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_ABOUTBOX), null, About);*/  btn.setX(btn.getX() - 10); }));

    
    nativeWindow.pack();
    nativeWindow.run();



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


