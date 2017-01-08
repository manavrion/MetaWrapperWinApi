#pragma once

#include "Panel.h"
#include "Game.h"
#include "Car.h"

class PanelUsersCreator : public Panel{
public:
    PanelUsersCreator(Game &game);

    void setAutoGen(bool fl);

    void spawnUser();

protected:
    Game &game;

    TextField name;
    TextField carName;
    TextField carColor;
    TextField carWorkComplexity;

public:
    ~PanelUsersCreator();
};

