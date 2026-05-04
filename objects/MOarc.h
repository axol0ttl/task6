//
// Created by arseny on 04/05/2026.
//

#pragma once
#include <iostream>
#include "object.h"
#include "../arc/arc_selfmade.h"

class MOarc : public object, public arc_selfmade {
public:
    MOarc(float x, float y, float radius, float start_angle, float end_angle, float r, float g, float b)
    :figure_selfmade(x,y,r,g,b), arc_selfmade(x, y, radius, start_angle, end_angle, r, g, b),
    object() {
        draw();
    }

    void print() const override {
        std::cout << "я дуга" << std::endl;
    }
};