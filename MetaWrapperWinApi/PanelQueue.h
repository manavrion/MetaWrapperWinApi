#pragma once

#include <queue>
#include <vector>
#include "Panel.h"
#include "Car.h"

using namespace std;

class PanelQueue : public Panel {
public:
    PanelQueue();


    void addCars(queue<Car*> cars) {
        this->cars = cars;
        update();
    }

protected:

    void update() {
        //workerCards
        int i = 0;
        for (; i < cars.size(); i++) {
            if (imagePanels.size() <= i) {
                /*WorkerCard *wcard = new WorkerCard();
                wcard
                    ->setMargin(0, 0, 0, 0)
                    ->setX(128 * i);

                workerCards.push_back(wcard);
                add(workerCards.back());
                workerCards[i]->build();*/
            }

            //imagePanels[i]->setWorker(cars[i]);

            //workerCards[i]->setText(workers[i]->name);
        }

        for (; i < imagePanels.size(); i++) {
            //imagePanels[i]->setWorker(nullptr);
        }
    }

    queue<Car*> cars;
    vector<ImagePanel*> imagePanels;

public:
    ~PanelQueue();
};

