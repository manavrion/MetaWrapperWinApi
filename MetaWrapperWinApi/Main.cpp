// MetaWrapperWinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"





// Global Variables:
//HINSTANCE hInst;                                // current instance

// Forward declarations of functions included in this code module:
/*ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);*/
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
 
    Window nativeWindow(L"Kek Microsystems");

    nativeWindow
        .setX(400)
        .setY(400)
        .setWidth(800)
        .setHeight(400)
        .add(Button()
             .setText(L"О программе")
             .setX(100)
             .setY(130)
             .addActionListener([]() { DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_ABOUTBOX), null, About); })
        )
        .add(Panel()
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setMaxWidth(600)
             .setMinWidth(300)
             .setWidth(500)
             .setX(100)
             .setAutoWidth(true)
             .setVerticalAlignment(VerticalAlignment::Top)
             .setMaxHeight(600)
             .setMinHeight(300)
             .setHeight(150)
             .setY(100)
             .setAutoHeight(true)
             .setMargin(10, 10, 10, 10)
             .add(Button()
                  .setText(L"azzaza")
                  .setX(10)
                  .setY(10)
                  .addActionListener([](Button &btn) {
                      btn.setX(btn.getX() + 10);
                  })
             )
             .add(Panel()
                  .setX(50)
                  .setY(50)
                  .setWidth(100)
                  .setHeight(100)
                  .setHorizontalAlignment(HorizontalAlignment::Stretch)
                  .setAutoWidth(false)
                  .setMargin(20, 20, 20, 20)
                  .add(Button()
                       .setText(L"eeeee")
                       .setX(10)
                       .setY(10)
                       .addActionListener([](Button &btn) {
                      btn.setX(btn.getX() + 10);
                  })
                  )
             )
        );
    
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


