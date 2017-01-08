#pragma once
#include "Car.h"

class User {
public:
    User(String name, Car car);


    String name;
    Car car;

    ~User();
};