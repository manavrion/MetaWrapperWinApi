#include "stdafx.h"
#include "NativeWindow.h"

namespace MetaFrame {

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        switch (message) {
            case WM_COMMAND:
            {
                switch (LOWORD(wParam)) {
                    /*case IDC_:
                    {
                        editingMode = IDC_RADIOGROUP_EDIT;
                        isselect = false;
                        selectedElem = nullptr;
                        select1.x = -100; select1.y = -100;
                        select2.x = -100; select2.y = -100;
                        graphics->update(store);
                        break;
                    }*/
                }
            }
            /*case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                // TODO: Add any drawing code that uses hdc here...
                EndPaint(hWnd, &ps);
            }
            break;
            case WM_DESTROY:
                PostQuitMessage(0);
                break;*/
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
        }
        return 0;
    }

    void NativeWindow::registerClass() {
        WNDCLASSEXW wcex;

        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WindowProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hInstance;
        wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_METAWRAPPERWINAPI));
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        //wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_METAWRAPPERWINAPI);
        wcex.lpszMenuName = null;
        wcex.lpszClassName = className;
        wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

        RegisterClassExW(&wcex);
    }

}