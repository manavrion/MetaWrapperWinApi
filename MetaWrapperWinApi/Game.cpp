#include "stdafx.h"

#include "Worker.h"
#include "Game.h"
#include "PanelRepare.h"


Game::Game(Logger *logger, PanelRepare *panelRepare, PanelQueue *panelQueue, Label *labelSimulationTime, Slider *sliderspeed)
    : autoGenClients(false), 
    logger(logger), 
    panelRepare(panelRepare), 
    time(0), 
    labelSimulationTime(labelSimulationTime), 
    sliderspeed(sliderspeed), 
    panelQueue(panelQueue)
{
    sliderspeed->addActionListener([&](Slider &sl) {this->sliderPos = sl.getPos(); });
    carsPanelQueue = panelQueue->cars;
}

void Game::addWorker(vector<Worker> workers) {
    this->workers = workers;
    for (auto &worker : workers) {
        log(L"+ " + worker.name + L" [exp " + String(int(worker.exp * 100)) + L"%]");
    }
    panelRepare->addWorkers(workers);
}

void Game::addWorker(Worker worker) {
    workers.push_back(worker);
    log(L"+ " + worker.name + L" [exp " + String(int(worker.exp*100)) + L"%]");
    panelRepare->addWorkers(workers);
}

void Game::clearWorkers() {
    workers.clear(); 
    log(L"");
    log(L"all workers was killed");
}

void Game::addUserToDeque(User user) {
    users.push(user);
    log(L"added car " + user.car.name + L" [" + String(int(user.car.workComplexity * 100)) + L"%] ");
}

void Game::setAutoGenClients(bool autoGenClients) {
    this->autoGenClients = autoGenClients;
}


void Game::spawnCar() {

    if ((*carsPanelQueue) == null) {
        return;
    }

    String names[] = {
        L"Человек разумный",
        L"Австралопитек",
        L"Неандерталец",
        L"Денисовец",
        L"Человек умелый",
        L"Человек рудольфский",
        L"Человек грузинский",
        L"Человек работающий",
        L"Человек прямоходящий",
        L"Питекантроп",
        L"Кроманьонец "
    };
    String carc;
    Color color;
    switch (rand () % 3) {
        case 0:
            color = Color::Green;
            carc = L"green";
            break;
        case 1:
            color = Color::Red;
            carc = L"red";
            break;
        case 2:
            color = Color::Blue;
            carc = L"blue";
            break;
        default:
            color = Color::White;
            carc = L"white";
            break;
    }


    Car car(L"lamb", color, (rand() % 101)/100.0);


    User *user = new User(names[(rand()*rand()) % 11], car);

    if ((*carsPanelQueue) != null) {
        (*carsPanelQueue)->push(user);
        panelQueue->update();
        this->log(L"" );
        this->log(L"<" + user->name+ L">");
        this->log(String(L"пришел с ") + L"lamb " + carc);
        
    }

}

Game::~Game() {}
