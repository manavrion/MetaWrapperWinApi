#include "stdafx.h"

#include "Worker.h"
#include "Game.h"

Game::Game(Logger &logger) : autoGenClients(false), logger(logger){}

void Game::addWorker(vector<Worker> workers) {
    this->workers = workers;
    for (auto &worker : workers) {
        log(L"Added " + worker.name);
    }
}

void Game::addWorker(Worker worker) {
    workers.push_back(worker);
    log(L"Added " + worker.name);
}

void Game::clearWorkers() {
    workers.clear(); 
    log(L"");
    log(L"All workers killed");
}

void Game::setAutoGenClients(bool autoGenClients) {
    this->autoGenClients = autoGenClients;
}

Game::~Game() {}
