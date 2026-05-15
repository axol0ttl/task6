#pragma once
#include "../arc/arc_selfmade.h"
#include "../line/line_selfmade.h"

class msector : virtual public arc_selfmade, virtual public line_selfmade {
public:
    msector(float x, float y, float rad, float start, float end,
        float r1_len, float r2_len, float r, float g, float b);
    ~msector() override;

    void draw() override;
    void erase() override;
};