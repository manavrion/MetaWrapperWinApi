#pragma once


using namespace std;

class Worker {
public:
    Worker() {};
    Worker(String name, float exp): name(name), exp(exp){};
    String name;
    float exp;

    ~Worker() {};
};

