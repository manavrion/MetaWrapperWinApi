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

        void setImage(String file) {
            this->file = file;
            if (file == L"") {
                hCompatibleDC = nullptr;
                return;
            }
            static std::map<String, std::pair<HDC, BITMAP>> mp;
            
            if (mp.count(file) != 0) {
                hCompatibleDC = mp[file].first;
                bitmap = mp[file].second;
                return;
            }


            //DeleteDC(hCompatibleDC);
            //DeleteObject(hBitmap);
            //DeleteObject(hOldBitmap);

            hBitmap = LoadImage(NULL, file, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            GetObject(hBitmap, sizeof(BITMAP), &bitmap);
            hCompatibleDC = CreateCompatibleDC(GetDC(nullptr));
            mp[file].first = hCompatibleDC;
            mp[file].second = bitmap;
            hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
        }

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