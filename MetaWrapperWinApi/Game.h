#pragma once

#include "TextField.h"
#include "Worker.h"
#include "User.h"
#include "PanelRepare.h"
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
    Game(Logger *logger, PanelRepare *panelRepare);

    void log(String str) {
        logger->print(str);
    }



protected:
    Logger *logger;

    PanelRepare *panelRepare;

    vector<Worker> workers;
    queue<User> users;

    bool autoGenClients;


public:
    void addWorker(vector<Worker> workers);
    void addWorker(Worker worker);
    void clearWorkers();

    void addUserToDeque(User user);



    void setAutoGenClients(bool autoGenClients);

    ~Game();
};