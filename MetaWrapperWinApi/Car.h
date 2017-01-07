#pragma once


class Car {
public:
    Car(String name, Color color, float workComplexity) 
        : name(name), color(color), workComplexity(workComplexity)
    {};
    
    String name;
    Color color;
    float workComplexity;//сложность работы

    ~Car() {};
};