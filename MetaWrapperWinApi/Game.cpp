#include "stdafx.h"

#include "Worker.h"
#include "Game.h"

Game::Game() : autoGenClients(false) {}

void Game::addWorker(vector<Worker> workers) {
    this->workers = workers;
}

void Game::addWorker(Worker worker) {
    workers.push_back(worker);
}

void Game::clearWorkers() {
    workers.clear();
}

void Game::setAutoGenClients(bool autoGenClients) {
    this->autoGenClients = autoGenClients;
}

Game::~Game() {}
