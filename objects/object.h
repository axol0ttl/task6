//
// Created by arseny on 04/05/2026.
//
#pragma once
#include <iostream>

class object {
public:
    virtual ~object() {}
    virtual void print() const {
        std::cout << "я объедок." << std::endl;
    }

};

class MNumber : public object {
private:
    int value;
public:
    MNumber(int v) : value(v) {}
    void print() const override {
        std::cout << "я число: " << value << std::endl;
    }
};


