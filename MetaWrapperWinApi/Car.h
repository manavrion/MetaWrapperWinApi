#pragma once


class Car {
public:
    Car(String name, Color color, float workComplexity) 
        : name(name), color(color), workComplexity(workComplexity), oldWorkComplexity(workComplexity)
    {};
    
    String name;
    Color color;
    float workComplexity;//сложность работы
    float oldWorkComplexity;//сложность работы

    ~Car() {};
};