//
// Created by arseny on 04/05/2026.
//

#pragma once
#include <iostream>
#include "object.h"
#include "../square/square_selfmade.h"

class MOsquare : public object, public square_selfmade {
    public:
    MOsquare(float x, float y, float w, float h, float r, float g, float b):
    figure_selfmade(x,y,r,g,b), square_selfmade(x, y, w, h, r, g, b),
    object() {
        draw();
    }

    void print(const std::string& suffix = "") const override {
        std::cout << "я квадрат" << suffix << std::endl;
    }
};