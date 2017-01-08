#pragma once

#include "Panel.h"
#include "Worker.h"

class WorkerCard : public Panel  {
public:
    WorkerCard();

    void setWorker(Worker *worker);


protected:

    Image *car;
    Image *worker;
    //
    ImagePanel *carPanel;
    ImagePanel *workerPanel;

    Label *name;
    Label *exp;

public:
    ~WorkerCard();
};

