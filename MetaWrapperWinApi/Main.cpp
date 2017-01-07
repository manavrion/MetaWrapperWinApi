// MetaWrapperWinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"



INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

Window nativeWindow(L"Kek Microsystems");

Panel panelQueue;
Panel panelRepare;

Panel panelController;

Panel panelMenu;
Panel panelUsersCreator;
Panel panelWorkersCreator;
Panel panelLogger;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    

    nativeWindow
        .setAlignment(Alignment::Center)
        .setSize(800, 400)
        .add(panelController
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


