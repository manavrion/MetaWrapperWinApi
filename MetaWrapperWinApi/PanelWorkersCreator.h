#pragma once

#include "Panel.h"

class PanelWorkersCreator : public Panel {
public:
    PanelWorkersCreator(Game &game);

protected:

    TextField exp;
    TextField name;

    Game &game;

    void createRandomWorkersSet();

    void createWorker();


public:
    ~PanelWorkersCreator();
};