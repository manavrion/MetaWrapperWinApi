#pragma once

#include "Worker.h"
#include "User.h"
#include <vector>
#include <queue>
using namespace std;

class Game {
public:
    Game();

protected:
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