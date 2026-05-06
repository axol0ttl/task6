//
// Created by arseny on 24/04/2026.
//

#include "figure_selfmade.h"

figure_selfmade::figure_selfmade(float x, float y, float r, float g, float b): x(x), y(y), r(r/255.0f), g(g/255.0f), b(b/255.0f) {}

figure_selfmade::~figure_selfmade() {}

void figure_selfmade::move(float dx, float dy) {
    erase();
    x += dx;
    y += dy;
    draw();
}

void figure_selfmade::change_color(float r, float g, float b) {
    erase();
    this->r = r/255.0f;
    this->g = g/255.0f;
    this->b = b/255.0f;
    draw();
}

