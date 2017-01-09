#pragma once

#include <queue>
#include <vector>
#include "Panel.h"
#include "Car.h"

using namespace std;

class PanelQueue : public Panel {
public:
    PanelQueue();

    queue<User*> **cars;





    void update();

protected:
    vector<ImagePanel*> imagePanels;
    vector<Label*> labelPanels;

public:
    ~PanelQueue();
};

