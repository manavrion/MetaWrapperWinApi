#include "stdafx.h"

#include "PanelWorkersCreator.h"

PanelWorkersCreator::PanelWorkersCreator(Game & game) : game(game) {

    add(Label()
        .setAlignment(Alignment::Stretch)
        .setMargin(5, 5, 5, 5)
        .setText(L"Создание работников:"))
        .add(Button()
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setAutoWidth(true)
             .setMargin(5, 5, 30, 5)
             .setText(L"Случайный набор работников")
             .addActionListener([&](Button &cb) { this->createRandomWorkersSet(); }));

    add(Label()
        .setText(L"Имя:")
        .setAlignment(Alignment::Absolute)
        .setPosition(5, 60));

    add(name
        .setVerticalAlignment(VerticalAlignment::Absolute)
        .setY(60)
        .setHorizontalAlignment(HorizontalAlignment::Right)
        .setAutoWidth(true)
        .setMargin(50, 5, 5, 5));

    add(Label()
        .setText(L"Опыт:")
        .setAlignment(Alignment::Absolute)
        .setPosition(5, 90));

    add(exp
        .setVerticalAlignment(VerticalAlignment::Absolute)
        .setY(90)
        .setHorizontalAlignment(HorizontalAlignment::Right)
        .setAutoWidth(true)
        .setMargin(50, 5, 5, 5));

    add(Button()
        .setText(L"Спаун")
        .setAlignment(Alignment::Absolute)
        .setPosition(5, 130)
        .setWidth(120)
        .addActionListener([&](Button &cb) { this->createWorker(); }));
}

void PanelWorkersCreator::createRandomWorkersSet() {
    game.clearWorkers();
    String firstnames[] = { L"Вася",    L"Юрий",        L"Иван",    L"Илья",    L"Андрей" };
    String secondnames[] = { L"Пупкин", L"Хованский",   L"Иванов",  L"Медисон", L"Нифёдов" };

    vector<Worker> workers;
    int n = 2 + rand() % 6;
    while (n--) {
        Worker w = {
            firstnames[rand() % 5] + L" " + secondnames[rand() % 5],
            float((rand() % 100) / 100.0)
        };

        workers.push_back(w);
    }
    game.addWorker(workers);
}

void PanelWorkersCreator::createWorker() {
    if (!name.getText().empty()) {
        Worker w = {
            name.getText(),
            float((exp.getText().toValueInt() % 100) / 100.0)
        };

        game.addWorker(w);
    }

}

PanelWorkersCreator::~PanelWorkersCreator() {}
