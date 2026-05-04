//
// Created by arseny on 04/05/2026.
//

#pragma once
#include <iostream>
#include "object.h"
#include "../line/line_selfmade.h"

class MOline : public line_selfmade, public object {
public:
    MOline(float x, float y, float dx1, float dy1, float dx2, float dy2, float r, float g, float b)
    :figure_selfmade(x,y,r,g,b), line_selfmade(x, y, dx1, dy1, dx2, dy2, r, g, b),
    object() {
        draw();
    }

    void print() const override {
        std::cout << "я линия" << std::endl;
    }
};