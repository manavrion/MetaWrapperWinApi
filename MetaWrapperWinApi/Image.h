#pragma once


namespace MetaFrame {

    struct Image {
    public:
        //bmp
        Image(String file) : file(file){
            hBitmap = LoadImage(NULL, file, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);
            hCompatibleDC = CreateCompatibleDC(GetDC(nullptr));
            hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
        };
        Image(const Image &image) : Image(image.file) {

        };


        Size getSize() const {
            return Size(bitmap.bmWidth, bitmap.bmHeight);
        }

        HDC &getHDC() {
            return hCompatibleDC;
        }

    protected:
        String file;
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