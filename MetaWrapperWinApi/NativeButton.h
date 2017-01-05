#pragma once

namespace MetaFrame {

    class NativeButton : public NativeAbstructObject {
    public:
        NativeButton() 
            : NativeAbstructObject(L"button")
        {
            width = 73;
            height = 21;
        };




        virtual void init(HWND hWnd);
    protected:

        int IDC_OF_BUTTON;

        virtual void command(WPARAM wParam, LPARAM lParam) {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;

    public:
        ~NativeButton() {};
    };

}