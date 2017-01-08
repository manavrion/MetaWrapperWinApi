#pragma once

#include "Worker.h"
#include <vector>
using namespace std;

class Game {
public:
    Game();

protected:
    vector<Worker> workers;

public:
    void addWorker(vector<Worker> workers);

    void addWorker(Worker worker);

    void clearWorkers();

    ~Game();
};