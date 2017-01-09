#include "stdafx.h"
#include "PanelQueue.h"

Image img1(L"greenlamb.bmp");
Image img2(L"yellowlamb.bmp");

PanelQueue::PanelQueue()
    : cars(new queue<User>*(new queue<User>())) 
{

    setText(L"Очередь");
    setHeight(64);
    setHorizontalAlignment(HorizontalAlignment::Stretch);
    setVerticalAlignment(VerticalAlignment::Bottom);
    setMargin(10, 10, 10, 150);
    //->add(new ImagePanel(&img1))
    //->add((new ImagePanel(&img2))->setX(128));

    for (int i = 0; i < 6; i++) {


        ImagePanel *imagePanel = new ImagePanel(new Image(L""));
        imagePanel->setX(i * 128);
        imagePanel->setSize(128, 64);
        imagePanel->setAlignment(Alignment::Absolute);
        imagePanels.push_back(imagePanel);
        add(imagePanel);
    }

}


void PanelQueue::update() {
    
    int i = 0;



    queue<User> tmpqueue = (**cars);




    for (; i < min(tmpqueue.size(), 6); i++) {
        
        if (tmpqueue.front().car.color == Color::Green) {
            imagePanels[i]->image->setImage(L"greenlamb.bmp");
        } else if (tmpqueue.front().car.color == Color::Red) {
            imagePanels[i]->image->setImage(L"redlamb.bmp");
        } else if (tmpqueue.front().car.color == Color::Blue) {
            imagePanels[i]->image->setImage(L"bluelamb.bmp");
        } else {
            imagePanels[i]->image->setImage(L"nulllamb.bmp");
        }
        

        //imagePanels[i]->image->setImage(L"yellowlamb.bmp");
        //imagePanels[i]->setWorker(cars[i]);

        //workerCards[i]->setText(workers[i]->name);
        imagePanels[i]->invalidateRect();
        //labelPanels[i]->setText(tmpqueue.front()->name);
        tmpqueue.pop();
    }
    //invalidateRect();
    for (; i < imagePanels.size(); i++) {
        imagePanels[i]->image->setImage(L"nulllamb.bmp");
        imagePanels[i]->invalidateRect();
    }
}

PanelQueue::~PanelQueue() {
    delete *cars;
    *cars = null;
    delete cars;
}
