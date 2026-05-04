//
// Created by arseny on 26/04/2026.
//

#pragma once
#include "../figure/figure_selfmade.h"


class arc_selfmade : virtual public figure_selfmade {
public:
    float radius, start_angle, end_angle;
public:
    arc_selfmade(float x, float y, float radius, float start_angle, float end_angle, float r, float g, float b);
    ~arc_selfmade() override;

    void draw() override;
    void erase() override;
};
