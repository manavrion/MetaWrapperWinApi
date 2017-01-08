#include "stdafx.h"
#include "PanelRepare.h"
#include "Worker.h"
#include "WorkerCard.h"

PanelRepare::PanelRepare() {
    setText(L"Починка");
    setHeight(64 + 32);
    setHorizontalAlignment(HorizontalAlignment::Stretch);
    setVerticalAlignment(VerticalAlignment::Bottom);
    setMargin(10, 10, 10, 40);
    //add(WorkerCard().setMargin(0, 0, 0, 0));
}

void PanelRepare::addWorkers(vector<Worker> workers) {
    this->workers.clear();
    for (auto &worker : workers) {
        this->workers.push_back(&worker);
    }
    update();
}

void PanelRepare::update() {
    //workerCards
    int i = 0;
    for (; i < workers.size(); i++) {
        if (workerCards.size() >= i) {
            WorkerCard wcard = WorkerCard();
            wcard.setMargin(0, 0, 0, 0).setX(128 * i);
            workerCards.push_back(wcard);
            add(workerCards.back());
            workerCards[i].build();
        }

        //workerCards[i].setText(workers[i]->name);
    }


}


PanelRepare::~PanelRepare() {

}
