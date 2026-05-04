//
// Created by arseny on 26/04/2026.
//

#include "arc_selfmade.h"

#include "../graphlib.h"

arc_selfmade::arc_selfmade(float x, float y, float radius, float start_angle, float end_angle, float r, float g, float b): figure_selfmade(x, y, r, g, b), radius(radius), start_angle(start_angle), end_angle(end_angle) {
    draw();
}

arc_selfmade::~arc_selfmade() {
    erase();
}

void arc_selfmade::draw() {
    draw_arc(x, y, radius, start_angle, end_angle, r, g, b);
}

void arc_selfmade::erase() {
    draw_arc(x, y, radius, start_angle, end_angle, 0, 0, 0);
}