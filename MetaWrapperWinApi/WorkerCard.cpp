#include "stdafx.h"
#include "WorkerCard.h"
#include "Margin.h"

WorkerCard::WorkerCard() {
    car = new Image(L"greenlamb.bmp");
    carPanel = new ImagePanel(car);

    worker = new Image(L"worker_master.bmp");
    workerPanel = new ImagePanel(worker);

    name = new Label;
    exp = new Label;

    x = 0;
    y = 0;
    margin = Margin(0, 0, 0, 0);
    height = 64 + 32;
    width = 128;
    setBorder(Border::NO_BORDER);
    add(name
        ->setPosition(0, 0)
        ->setWidth(128)
        ->setText(L"worker")
        ->setCenter());

    add(exp
        ->setPosition(0, 16)
        ->setWidth(128)
        ->setText(L"146%")
        ->setCenter());

    /*add(carPanel
        ->setPosition(0, 32));

    add(workerPanel
        ->setPosition(0, 32));*/
}

void WorkerCard::setWorker(Worker *worker) {
    if (worker == nullptr) {
        name->setText(L"");
        exp->setText(L"");
        return;
    }
    name->setText(worker->name);
    exp->setText(L"exp " + String(int(worker->exp*100)) + L"%");
}


WorkerCard::~WorkerCard() {

}
