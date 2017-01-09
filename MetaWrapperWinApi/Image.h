#pragma once


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
            hBitmap = LoadImage(NULL, file, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);
            hCompatibleDC = CreateCompatibleDC(GetDC(nullptr));
            hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
        };

        Image(const Image &image) = delete;

        Size getSize() const {
            return Size(bitmap.bmWidth, bitmap.bmHeight);
        }

        HDC &getHDC() {
            return hCompatibleDC;
        }

        void setImage(String file) {
            DeleteDC(hCompatibleDC);
            DeleteObject(hBitmap);
            DeleteObject(hOldBitmap);

            hBitmap = LoadImage(NULL, file, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);
            hCompatibleDC = CreateCompatibleDC(GetDC(nullptr));
            hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
        }

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