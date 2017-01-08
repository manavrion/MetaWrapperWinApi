#include "stdafx.h"

#include "Worker.h"
#include "Game.h"
#include "PanelRepare.h"


Game::Game(Logger &logger, PanelRepare *panelRepare) 
    : autoGenClients(false), logger(logger), panelRepare(panelRepare)
{}

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

Game::~Game() {}
