#pragma once


using namespace std;

class Worker {
public:
    Worker();
    Worker(String name, float exp);
    String name;
    float exp;

    ~Worker();
};

