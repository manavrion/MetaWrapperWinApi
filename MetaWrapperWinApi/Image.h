#pragma once
#include <map>

namespace MetaFrame {

    struct Image {
    public:
        //bmp
        Image() :
            hBitmap(nullptr),
            hOldBitmap(nullptr),
            hCompatibleDC(nullptr)
        {

        };
        Image(String file)
        {
            file = L"res/" + file;
            hBitmap = LoadImage(NULL, file, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);
            hCompatibleDC = CreateCompatibleDC(GetDC(nullptr));
            hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
            this->file = file;
        };

        Image(const Image &image) = delete;

        Size getSize() const {
            return Size(bitmap.bmWidth, bitmap.bmHeight);
        }

        HDC &getHDC() {
            return hCompatibleDC;
        }

        void setImage(String file);

        String file;
    protected:
        
        HANDLE hBitmap;
        HANDLE hOldBitmap;
        BITMAP bitmap;
        HDC hCompatibleDC;


    public:
        ~Image() {
            DeleteDC(hCompatibleDC);
            DeleteObject(hBitmap);
        };

    };


}