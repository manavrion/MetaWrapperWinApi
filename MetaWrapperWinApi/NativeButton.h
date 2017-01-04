#pragma once

namespace MetaFrame {

    class NativeButton : public NativeAbstructObject {
    public:
        NativeButton() 
            : NativeAbstructObject(L"button")
        {

        };




        virtual void init(HWND hWnd);
    protected:

        int IDC_OF_BUTTON;

    public:
        ~NativeButton() {};
    };

}