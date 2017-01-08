// MetaWrapperWinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

Window window(L"Kek Microsystems");

Panel panelQueue;
Panel panelRepare;

Panel panelController;

Panel panelMenu;
Panel panelUsersCreator;
Panel panelWorkersCreator;
Panel panelLogger;


bool autoGenClients = false;
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
             .setMargin(10, 10, 70, 10)
             .setText(L"Время в симуляции:"))
        .add(labelSimulationTime
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setWidth(120)
             .setMargin(10, 10, 90, 10)
             .setText(L"0 месяц, 0 день, 00:00"))
        .add(Label()
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setWidth(120)
             .setMargin(10, 10, 120, 10)
             .setText(L"Скорость симуляции:"))
        .add(labelspeed
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setWidth(20)
             .setMargin(10, 10, 120, 10)
             .setText(L"x0"))
        .add(sliderspeed
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Center)
             .setWidth(180)
             .setHeight(50)
             .setMargin(10, 10, 140, 10)
             .addActionListener([&](Slider &sl) {
                labelspeed.setText(String(L"x") + String(sl.getPos()));
                logTextField.setText(logTextField.getText() + String({ 13, 10 }) + labelspeed.getText());
                logTextField.setPageDown();
             })
        );




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
        .add(Label().setText(L"Клиент:").setAlignment(Alignment::Absolute).setPosition(5, 60))
        .add(TextField().setVerticalAlignment(VerticalAlignment::Absolute).setY(60)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setAutoWidth(true).setMargin(50, 5, 5, 5))
        .add(Label().setText(L"Модель авто:").setAlignment(Alignment::Absolute).setPosition(5, 90))
        .add(TextField().setVerticalAlignment(VerticalAlignment::Absolute).setY(90)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setAutoWidth(true).setMargin(85, 5, 5, 5))
        .add(Label().setText(L"Цвет авто:").setAlignment(Alignment::Absolute).setPosition(5, 120))
        .add(TextField().setVerticalAlignment(VerticalAlignment::Absolute).setY(120)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setAutoWidth(true).setMargin(80, 5, 5, 5))
        .add(Label().setText(L"Сложность работы:").setAlignment(Alignment::Absolute).setPosition(5, 150).setWidth(120))
        .add(TextField().setVerticalAlignment(VerticalAlignment::Absolute).setY(150)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setAutoWidth(true).setMargin(120, 5, 5, 5))
        .add(Button().setText(L"Спаун").setAlignment(Alignment::Absolute).setPosition(5, 180).setWidth(120));



    panelWorkersCreator
        .add(Label()
             .setAlignment(Alignment::Stretch)
             .setMargin(5, 5, 5, 5)
             .setText(L"Создание работников:"))
        .add(Button()
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setAutoWidth(true)
             .setMargin(5, 5, 30, 5)
             .setText(L"Случайный набор работников")
             .addActionListener([&](Button &cb) {
                //autoGenClients = cb.getState();
             }))
        .add(Label().setText(L"Имя:").setAlignment(Alignment::Absolute).setPosition(5, 60))
        .add(TextField().setVerticalAlignment(VerticalAlignment::Absolute).setY(60)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setAutoWidth(true).setMargin(50, 5, 5, 5))
        .add(Label().setText(L"Опыт:").setAlignment(Alignment::Absolute).setPosition(5, 90))
        .add(TextField().setVerticalAlignment(VerticalAlignment::Absolute).setY(90)
             .setHorizontalAlignment(HorizontalAlignment::Right)
             .setAutoWidth(true).setMargin(50, 5, 5, 5))
        .add(Button().setText(L"Спаун").setAlignment(Alignment::Absolute).setPosition(5, 120).setWidth(120));





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
             .addActionListener([](Button &btn) { DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_ABOUTBOX), null, About);  btn.setX(btn.getX() - 10); }));

    
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


