#pragma once
#include "../figure/figure_selfmade.h"

class line_selfmade : virtual public figure_selfmade {
public:
    line_selfmade(float x, float y, float dx1, float dy1, float dx2, float dy2, float r, float g, float b);
    ~line_selfmade() override;

    void draw() override;
    void erase() override;
};