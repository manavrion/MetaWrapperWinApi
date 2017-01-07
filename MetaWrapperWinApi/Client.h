#pragma once
#include "Car.h"

class Client {
public:
    Client(String name, Car car)
        : name(name), car(car)
    {};


    String name;
    Car car;

    ~Client() {};
};