//
// Created by arseny on 26/04/2026.
//

#pragma once
#include <iostream>
#include "../figure/figure_selfmade.h"
#include "../objects/object.h"

class line_selfmade : virtual public figure_selfmade {
private:
    float dx1, dy1;//?????
    float dx2, dy2;

public:
    line_selfmade(float x, float y, float dx1, float dy1, float dx2, float dy2, float r, float g, float b);
    ~line_selfmade() override;

    void draw() override;
    void erase() override;
};