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

    public:
        ~NativeButton() {};
    };

}