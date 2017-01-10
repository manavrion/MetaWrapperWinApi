#pragma once

#include "Worker.h"
#include "Car.h"
#include "User.h"
#include "Game.h"
#include "PanelWorkersCreator.h"
#include "PanelUsersCreator.h"
#include "PanelRepare.h"
#include "WorkerCard.h"
#include "PanelQueue.h"

class AutoService : public Window {
public:
    AutoService(String taxt);

protected:
    Game *game;

    PanelQueue *panelQueue = new PanelQueue;
    PanelRepare *panelRepare = new PanelRepare;

    Panel *panelController = new Panel;

    Logger *logger = new Logger;

    Label *labelSimulationTime = new Label;

    Slider *sliderspeed = new Slider;

    Label *labelMoney = new Label;

    Panel *panelMenu = new Panel;
    PanelUsersCreator *panelUsersCreator;
    PanelWorkersCreator *panelWorkersCreator;
    Panel *panelLogger = new Panel;
    Label *labelspeed = new Label;

public:
    ~AutoService();
};

