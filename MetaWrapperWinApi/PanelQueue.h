#pragma once

#include <queue>
#include <vector>
#include "Panel.h"
#include "Car.h"

using namespace std;

class PanelQueue : public Panel {
public:
    PanelQueue();

    queue<User*> **cars;





    void update() {

        int i = 0;
        for (; i < min((*cars)->size(), 10); i++) {
            if (imagePanels.size() <= i) {

                ImagePanel *imagePanel = new ImagePanel(new Image(L"yellowlamb.bmp"));
                imagePanel->setX(i*128);
                imagePanel->setAlignment(Alignment::Absolute);
                imagePanels.push_back(imagePanel);
                add(imagePanel);
                imagePanels[i]->build();
            }

            //imagePanels[i]->image->setImage(L"yellowlamb.bmp");

            //imagePanels[i]->setWorker(cars[i]);

            //workerCards[i]->setText(workers[i]->name);
        }

        for (; i < imagePanels.size(); i++) {
            //imagePanels[i]->setWorker(nullptr);
        }
    }

protected:
    vector<ImagePanel*> imagePanels;

public:
    ~PanelQueue();
};

