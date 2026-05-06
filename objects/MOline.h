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

    static void print_impl(const std::string& suffix = "") {
        std::cout << "я линия" << suffix << std::endl;
    }

    void print(const std::string& suffix = "") const override {
       print_impl(suffix);
    }
};