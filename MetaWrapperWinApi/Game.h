#pragma once

#include "TextField.h"
#include "Worker.h"
#include "User.h"
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
        setText(getText() + String({ 13, 10 }) + str);
        setPageDown();
    }

    ~Logger() {

    };

private:
};

class Game {
public:
    Game(Logger &logger);

    void log(String str) {
        logger.print(str);
    }



protected:
    Logger logger;
    vector<Worker> workers;
    queue<User> users;

    bool autoGenClients;


public:
    void addWorker(vector<Worker> workers);
    void addWorker(Worker worker);
    void clearWorkers();

    void addUserToDeque(User user) {
        users.push(user);
    }



    void setAutoGenClients(bool autoGenClients);

    ~Game();
};