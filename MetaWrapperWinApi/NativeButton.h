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
        };



    protected:

        virtual void init(HWND hWnd);
    

        int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;

    public:
        ~NativeButton() {};
    };

}