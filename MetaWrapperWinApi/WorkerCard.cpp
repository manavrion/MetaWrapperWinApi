#include "stdafx.h"
#include "Worker.h"
#include "WorkerCard.h"
#include "Margin.h"

WorkerCard::WorkerCard() {
    car = new Image(L"nulllamb.bmp");
    carPanel = new ImagePanel(car);

    worker = new Image(L"master00.bmp");
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
        ->setHeight(16)
        ->setText(L"146%")
        ->setCenter());

    add(carPanel
        ->setPosition(0, 32));

    add(workerPanel
        ->setPosition(0, 32));
}

void WorkerCard::setWorker(Worker *worker) {
    if (worker == nullptr) {
        name->setText(L"");
        exp->setText(L"");
        return;
    }
    if (name->getText() != worker->name) {
        name->setText(worker->name);
    }
    String expStr = L"exp " + String(int(worker->exp * 100)) + L"." + String(int((worker->exp * 10000)) % 100) + L"%";
    if (exp->getText() != expStr) {
        exp->setText(expStr);
    }


    if (worker->user != null) {
        String newCarImage;
        if (worker->user->car.color == Color::Green) {
            newCarImage = L"greenlamb.bmp";
        } else if (worker->user->car.color == Color::Red) {
            newCarImage = L"redlamb.bmp";
        } else if (worker->user->car.color == Color::Blue) {
            newCarImage = L"bluelamb.bmp";
        } else {
            newCarImage = L"nulllamb.bmp";
        }
        if (carPanel->image->file != newCarImage) {
            carPanel->image->setImage(newCarImage);
            carPanel->repaint();
        }
        


        if (worker->user->car.workComplexity < 0.25) {
            workerPanel->image->setImage(L"master00.bmp");
        } else if (worker->user->car.workComplexity < 0.50) {
            workerPanel->image->setImage(L"master25.bmp");
        } else if (worker->user->car.workComplexity < 0.75) {
            workerPanel->image->setImage(L"master50.bmp");
        } else if (worker->user->car.workComplexity < 0.95) {
            workerPanel->image->setImage(L"master75.bmp");
        } else {
            workerPanel->image->setImage(L"master95.bmp");
        }
        workerPanel->repaint();
    } else {
        if (carPanel->image->file != L"nulllamb.bmp") {
            carPanel->image->setImage(L"nulllamb.bmp");
            carPanel->repaint();
        }
        
        workerPanel->image->setImage(L"master00.bmp");
        workerPanel->repaint();
    }

}


WorkerCard::~WorkerCard() {

}
