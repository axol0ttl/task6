//
// Created by arseny on 04/05/2026.
//

#pragma once
#include "../arc/arc_selfmade.h"
#include "../line/line_selfmade.h"

// Используем виртуальное наследование, если arc и line наследуются от figure_selfmade
class msegment : virtual public arc_selfmade, virtual public line_selfmade {
public:
    msegment(float x, float y, float rad, float start, float end,
             float r, float g, float b);

    ~msegment() override;

    void draw() override;
    void erase() override;
    void move(float dx, float dy);
};