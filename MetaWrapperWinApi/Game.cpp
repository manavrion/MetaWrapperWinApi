#include "stdafx.h"

#include "Game.h"
#include "Worker.h"

Game::Game() {}

void Game::addWorker(vector<Worker> workers) {
    this->workers = workers;
}

void Game::addWorker(Worker worker) {
    workers.push_back(worker);
}

void Game::clearWorkers() {
    workers.clear();
}

Game::~Game() {}
