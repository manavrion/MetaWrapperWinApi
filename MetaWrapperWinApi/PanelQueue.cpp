#include "stdafx.h"
#include "PanelQueue.h"

Image img1(L"greenlamb.bmp");
Image img2(L"yellowlamb.bmp");

PanelQueue::PanelQueue()
    : cars(new queue<User*>*(new queue<User*>()))
{

    setText(L"Очередь")
        ->setHeight(64)
        ->setHorizontalAlignment(HorizontalAlignment::Stretch)
        ->setVerticalAlignment(VerticalAlignment::Bottom)
        ->setMargin(10, 10, 10, 150)
        ->add(new ImagePanel(&img1))
        ->add((new ImagePanel(&img2))->setX(128));

}


PanelQueue::~PanelQueue() {
    delete *cars;
    *cars = null;
    delete cars;
}
