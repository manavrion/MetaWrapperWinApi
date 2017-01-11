// MetaWrapperWinApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Main.h"
#include "Editor.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    AutoService *autoService = new AutoService(L"Kek Microsystems");
    autoService->run();

    autoService->destrThread();
    
    delete autoService;

    /*Editor *window = new Editor(L"Kek Microsystems editor");
    window->run();*/




   /* Window *w = new Window(L"azazazaza");
    w->setSize(100, 100);
    w->run();*/

    return 0;
}
