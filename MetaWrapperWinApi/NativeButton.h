#pragma once



class NativeButton : public NativeAbstructObject {
public:
    NativeButton() {


    };


    virtual void add(NativeAbstructObject *nativeAbstructObject) {

    };

    virtual void init(HWND hWnd);
protected:
    virtual void registerClass() {};

    int IDC_OF_BUTTON;

public:
    ~NativeButton() {};
};

