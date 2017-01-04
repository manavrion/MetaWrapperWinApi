#pragma once

class NativeAbstructObject {

public:
    NativeAbstructObject() : 
        x(), 
        y(), 
        width(), 
        height(), 
        hWnd() 
    {

    };


    virtual void add(NativeAbstructObject *nativeAbstructObject) = 0;

protected:
    virtual void init(HWND hWnd) = 0;

    virtual void registerClass() = 0;

protected:
    HWND hWnd;
    String className;

    int x;
    int y;
    int width;
    int height;

public:
    ~NativeAbstructObject() {

    };
};

