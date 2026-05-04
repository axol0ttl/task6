//
// Created by arseny on 04/05/2026.
//

#pragma once
#include "../arc/arc_selfmade.h"
#include "../line/line_selfmade.h"

class msector : virtual public arc_selfmade, virtual public line_selfmade {
private:
    float r1, r2; // два радиуса для границ сектора

public:
    msector(float x, float y, float rad, float start, float end,
        float r1_len, float r2_len, float r, float g, float b);
    ~msector() override;

    void draw() override;
    void erase() override;

    void move(float dx, float dy);
};
