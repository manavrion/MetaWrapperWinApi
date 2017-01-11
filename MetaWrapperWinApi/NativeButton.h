#pragma once

namespace MetaFrame {

    class NativeButton : public NativeAbstructObject {
    public:
        NativeButton() 
            : NativeAbstructObject(L"button")
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;

            className = L"button";
            style = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;


        };



    protected:

        virtual void init(HWND hWnd) {

            className = L"button";
            style = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
            createWindow((((const NativeAbstructObject*)parent)->hWindow));
            /*hWindow = CreateWindow(L"button",
                                   text,
                                   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                   x, y,
                                   width, height,
                                   hWnd,
                                   0,
                                   GetModuleHandle(0),
                                   NULL);*/



            //setting standart font
            NONCLIENTMETRICS ncm;
            ncm.cbSize = sizeof(NONCLIENTMETRICS);
            UINT uiParam = sizeof(NONCLIENTMETRICS);
            SystemParametersInfo(SPI_GETNONCLIENTMETRICS, uiParam, &ncm, 0);

            SendMessage(hWindow, WM_SETFONT, (WPARAM)(CreateFontIndirect(&(ncm.lfMenuFont))), 0);

        }
    

        //int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;


    public:
        ~NativeButton() {};
    };

}