//
// Created by arseny on 04/05/2026.
//
#pragma once
#include <iostream>
#include <string>

class object {
public:
    virtual ~object() {}
    virtual void print(const std::string& suffix = "") const{
        std::cout << "я объект " << suffix << std::endl;
    }

};

class MNumber : public object {
private:
    int value;
public:
    MNumber(int v) : value(v) {}
    void print(const std::string& suffix = "") const override {
        std::cout << "я число: " << value << suffix << std::endl;
    }
};


