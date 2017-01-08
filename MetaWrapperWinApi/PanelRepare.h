#pragma once
#include "Panel.h"
#include "Worker.h"
#include "WorkerCard.h"

class PanelRepare : public Panel {
public:
    PanelRepare();


    void addWorkers(vector<Worker> workers);

    void update();

protected:
    vector<Worker*> workers;

    vector<WorkerCard> workerCards;


public:
    ~PanelRepare();
};

