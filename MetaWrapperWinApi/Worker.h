#pragma once
#include "String.h"
#include "User.h"

using namespace std;


class Worker {
public:
    Worker();
    Worker(String name, float exp);
    String name;
    float exp;

    User *user;

    ~Worker();
};

