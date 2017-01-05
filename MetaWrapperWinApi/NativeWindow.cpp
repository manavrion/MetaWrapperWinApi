#include "stdafx.h"
#include "NativeWindow.h"
#include <queue>

namespace MetaFrame {

    static HashMap<HWND, NativeWindow*> nativeWindowMap;

    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        if (message == WM_CREATE || message == WM_GETMINMAXINFO || message == WM_NCCREATE || message == WM_NCCALCSIZE) {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        return nativeWindowMap[hWnd]->windowProcLocal(hWnd, message, wParam, lParam);
    }

    void NativeWindow::init(HWND hWnd) {
        this->hWnd = CreateWindow(className, title, WS_OVERLAPPEDWINDOW,
                                  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, hWnd, nullptr, hInstance, nullptr);
        if (!this->hWnd) {
            throw L"Error in creating window";
        }
        nativeWindowMap[this->hWnd] = this;
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

    LRESULT NativeWindow::windowProcLocal(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        switch (message) {
            case WM_COMMAND:
            {
                if (!wmCommand(wParam, lParam)) {
                    return DefWindowProc(hWnd, message, wParam, lParam);
                }
                /*
                HWND hwndTarget = (HWND)lParam;

                std::queue<NativeAbstructObject*> q;

                q.push(this);

                //bfs
                while (!q.empty()) {
                    NativeAbstructObject *cur = q.front();
                    q.pop();
                    this->hWnd;
                    if (cur->hWnd == hwndTarget) {

                    }

                }
                */

                /*switch (LOWORD(wParam)) {
                    case IDC_:
                    {
                        editingMode = IDC_RADIOGROUP_EDIT;
                        isselect = false;
                        selectedElem = nullptr;
                        select1.x = -100; select1.y = -100;
                        select2.x = -100; select2.y = -100;
                        graphics->update(store);
                        break;
                    }
                }*/
                break;
            }
            case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);
                // TODO: Add any drawing code that uses hdc here...
                EndPaint(hWnd, &ps);
            }
            break;
            case WM_DESTROY:
                PostQuitMessage(0);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }

}