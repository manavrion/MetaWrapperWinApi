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

        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };

        virtual void runActionEvents() = 0;


    public:
        ~NativeButton() {};
    };

}