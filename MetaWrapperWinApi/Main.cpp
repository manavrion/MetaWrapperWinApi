// MetaWrapperWinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

Game game;


Window window(L"Kek Microsystems");

Panel panelQueue;
Panel panelRepare;

Panel panelController;

Panel panelMenu;
PanelUsersCreator panelUsersCreator(game);
PanelWorkersCreator panelWorkersCreator(game);
Panel panelLogger;



Label labelspeed;
Label labelSimulationTime;

Slider sliderspeed;
TextField logTextField;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    
    panelMenu
        .add(Label()
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setWidth(120)
             .setMargin(10, 10, 50, 10)
             .setText(L"Время в симуляции:"))
        .add(labelSimulationTime
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setWidth(120)
             .setMargin(10, 10, 70, 10)
             .setText(L"0 месяц, 0 день, 00:00"))
        .add(Label()
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setWidth(120)
             .setMargin(10, 10, 100, 10)
             .setText(L"Скорость симуляции:"))
        .add(labelspeed
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setWidth(20)
             .setMargin(10, 10, 100, 10)
             .setText(L"x0"))
        .add(sliderspeed
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Center)
             .setWidth(180)
             .setHeight(50)
             .setMargin(10, 10, 120, 10)
             .addActionListener([&](Slider &sl) {
                labelspeed.setText(String(L"x") + String(sl.getPos()));
                logTextField.setText(logTextField.getText() + String({ 13, 10 }) + labelspeed.getText());
                logTextField.setPageDown();
             })
        );



    panelLogger
        .add(Label()
             .setAlignment(Alignment::Stretch)
             .setMargin(5, 5, 5, 5)
             .setText(L"Логгер:"))
        .add(logTextField
             .setAlignment(Alignment::Stretch)
             .setMargin(5, 5, 35, 5)
             .setBackground(Color(18, 18, 18))
             .setText(L"")
             .setMultiLine(true)
             .setWritable(false)
        );




    window
        .setAlignment(Alignment::Center)
        .setSize(820, 420)
        .add(panelController
             .setBorder(Border::SOFT_BEVEL)
             .setHorizontalAlignment(HorizontalAlignment::Stretch)
             .setVerticalAlignment(VerticalAlignment::Top)
             //.setMargin(10, 10, 10, 220)
             .setHeight(190)
             .setLayout(Layout::HorizontalStack)
             .add(panelMenu.setAlignment(Alignment::Stretch))
             .add(panelUsersCreator.setAlignment(Alignment::Stretch))
             .add(panelWorkersCreator.setAlignment(Alignment::Stretch))
             .add(panelLogger.setAlignment(Alignment::Stretch)))
        .add(panelQueue
             .setText(L"Очередь")
             .setHeight(64)
             .setHorizontalAlignment(HorizontalAlignment::Stretch)
             .setVerticalAlignment(VerticalAlignment::Bottom)
             .setMargin(10, 10, 10, 150)
             .add(ImagePanel(Image(L"greenlamb.bmp")))
             .add(ImagePanel(Image(L"yellowlamb.bmp")).setX(128)))
        .add(panelRepare
             .setText(L"Починка")
             .setHeight(64 + 32)
             .setHorizontalAlignment(HorizontalAlignment::Stretch)
             .setVerticalAlignment(VerticalAlignment::Bottom)
             .setMargin(10, 10, 10, 40)
             .add(Label().setPosition(0, 0).setWidth(128).setText(L"твой бухой батя").setCenter())
             .add(Label().setPosition(0, 16).setWidth(128).setText(L"статус: 146%").setCenter())
             .add(ImagePanel(Image(L"greenlamb.bmp")).setPosition(0, 32))
             .add(ImagePanel(Image(L"worker_master.bmp")).setPosition(0, 32))

        )
        //worker_master.bmp
        .add(Button()
             .setText(L"О программе")
             .setWidth(100)
             .setVerticalAlignment(VerticalAlignment::Bottom)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .addActionListener([&]() { DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_ABOUTBOX), window.getHWindow(), About); }))
        .add(Label()
             .setText(L"Выручка: 2000$")
             .setWidth(100)
             .setVerticalAlignment(VerticalAlignment::Bottom)
             .setHorizontalAlignment(HorizontalAlignment::Left));

    
    window.pack();
    window.run();



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


