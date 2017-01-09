#pragma once

#include "TextField.h"
#include "Worker.h"
#include "User.h"
#include "PanelRepare.h"
#include "PanelQueue.h"
#include <vector>
#include <queue>
using namespace std;

class Logger : public TextField {
public:
    Logger() {
        setAlignment(Alignment::Stretch);
        setMargin(5, 5, 35, 5);
        setBackground(Color(18, 18, 18));
        setText(L"");
        setMultiLine(true);
        setWritable(false);
    }

    void print(String str) {
        String nw = getText() + String({ 13, 10 }) + str;
        if (nw.size() > 200) {
            nw.erase(0, nw.size() - 200);
        }
        setText(nw);
        setPageDown();
    }

    ~Logger() {

    };

private:
};

class Game {
public:
    Game(Logger *logger, PanelRepare *panelRepare, PanelQueue *panelQueue, Label *labelSimulationTime, Slider *sliderspeed);

    void log(String str) {
        logger->print(str);
    }



protected:
    Logger *logger;

    Label *labelSimulationTime;

    PanelRepare *panelRepare;

    PanelQueue *panelQueue;
    queue<User*> **carsPanelQueue;

    Slider *sliderspeed;

    vector<Worker> workers;
    queue<User> users;

    bool autoGenClients;

    long long time;

public:
    void addWorker(vector<Worker> workers);
    void addWorker(Worker worker);
    void clearWorkers();

    void addUserToDeque(User user);



    void setAutoGenClients(bool autoGenClients);

    int updateTime() {
        int oldTime = time;

        time += 1;

        labelSimulationTime->setText(
            //L"0 месяц, 0 день, 00:00"+
            String((time / 24)/30) +
            L" месяц, "+
            String((time / 24)%30) +
            L" день, "+
            String(time%24)+
            L":00"
        );

        return oldTime;
    }


    int sliderPos = 0;

    bool updateThread() {
        if (sliderPos == 0) {
            return true;
        }
        updateTime();
        //1 hour
        if (rand()%10 == 0) {
            spawnCar();
        }
        





        
        Sleep(1000 / sliderPos);
        return true;
    }


    void spawnCar();



    ~Game();
};