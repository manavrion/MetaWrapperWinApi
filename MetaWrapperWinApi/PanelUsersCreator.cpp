#include "stdafx.h"
#include "PanelUsersCreator.h"


PanelUsersCreator::PanelUsersCreator(Game &game) : game(game) {

    
    add(Label()
        .setAlignment(Alignment::Stretch)
        .setMargin(5, 5, 5, 5)
        .setText(L"Создание клиентов:"));
        add(CheckBox()
             .setVerticalAlignment(VerticalAlignment::Top)
             .setHorizontalAlignment(HorizontalAlignment::Left)
             .setAutoWidth(true)
             .setMargin(5, 5, 20, 5)
             .setText(L"Автогенерация клиентов")
             .addActionListener([&](CheckBox &cb) {
                 this->setAutoGen(cb.getState()); 
             }));

        add(Label()
            .setText(L"Клиент:")
            .setAlignment(Alignment::Absolute)
            .setPosition(5, 50));

        add(name
            .setVerticalAlignment(VerticalAlignment::Absolute)
            .setY(50)
            .setHorizontalAlignment(HorizontalAlignment::Right)
            .setAutoWidth(true)
            .setMargin(50, 5, 5, 5));

        add(Label()
            .setText(L"Модель авто:")
            .setAlignment(Alignment::Absolute)
            .setPosition(5, 70));

        add(carName
            .setVerticalAlignment(VerticalAlignment::Absolute)
            .setY(70)
            .setHorizontalAlignment(HorizontalAlignment::Right)
            .setAutoWidth(true)
            .setMargin(85, 5, 5, 5));

        add(Label()
            .setText(L"Цвет авто:")
            .setAlignment(Alignment::Absolute)
            .setPosition(5, 90));

        add(carColor
            .setVerticalAlignment(VerticalAlignment::Absolute)
            .setY(90)
            .setHorizontalAlignment(HorizontalAlignment::Right)
            .setAutoWidth(true)
            .setMargin(80, 5, 5, 5));

        add(Label()
            .setText(L"Сложность работы:")
            .setAlignment(Alignment::Absolute)
            .setPosition(5, 110)
            .setWidth(120));

        add(carWorkComplexity
            .setVerticalAlignment(VerticalAlignment::Absolute)
            .setY(110)
            .setHorizontalAlignment(HorizontalAlignment::Right)
            .setAutoWidth(true)
            .setMargin(120, 5, 5, 5));

        add(Button()
            .setText(L"Спаун")
            .setAlignment(Alignment::Absolute)
            .setPosition(5, 130)
            .setWidth(120)
            .addActionListener([&]() {this->spawnUser(); }));



}

void PanelUsersCreator::setAutoGen(bool fl) {
    game.setAutoGenClients(fl);
}

void PanelUsersCreator::spawnUser() {
    if (!name.getText().empty() && !carName.getText().empty() && !carColor.getText().empty() && !carWorkComplexity.getText().empty()) {
        Color color;
        if (carColor.getText() == L"green") {
            color = Color::Green;
        } else if (carColor.getText() == L"red") {
            color = Color::Red;
        } else if (carColor.getText() == L"Blue") {
            color = Color::Blue;
        } else {
            color = Color::White;
        }

        Car car(carName.getText(), color, carWorkComplexity.getText().toValueInt());

        User user(name.getText(), car);
        game.addUserToDeque(user);
    }
}


PanelUsersCreator::~PanelUsersCreator() {}
