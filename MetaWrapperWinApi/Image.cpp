#include "stdafx.h"


static std::map<String, std::pair<HDC, BITMAP>> mp;

void MetaFrame::Image::setImage(String file) {
    file = L"res/" + file;
    this->file = file;
    if (file == L"res/") {
        hCompatibleDC = nullptr;
        return;
    }
    

    if (mp.count(file) != 0) {
        hCompatibleDC = mp[file].first;
        bitmap = mp[file].second;
        return;
    }


    hBitmap = LoadImage(NULL, file, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    GetObject(hBitmap, sizeof(BITMAP), &bitmap);
    hCompatibleDC = CreateCompatibleDC(GetDC(nullptr));
    mp[file].first = hCompatibleDC;
    mp[file].second = bitmap;
    hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
}
