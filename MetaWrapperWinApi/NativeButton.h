#pragma once

namespace MetaFrame {

    class NativeButton : public NativeAbstructObject {
    public:
        NativeButton() 
            : NativeAbstructObject(L"button", 
              WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON)
        {
            x = 10;
            y = 10;
            width = 73;
            height = 21;
        };



    protected:
        virtual void command(WPARAM wParam, LPARAM lParam) override {
            runActionEvents();
        };

    public:
        virtual ~NativeButton() {};
    };

}