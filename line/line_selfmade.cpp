//
// Created by arseny on 26/04/2026.
//

#include "line_selfmade.h"
#include "../graphlib.h"

line_selfmade::line_selfmade(float x, float y, float dx1, float dy1, float dx2, float dy2, float r, float g, float b): figure_selfmade(x,y,r,g,b), dx1(dx1), dy1(dy1), dx2(dx2), dy2(dy2) {
    draw();
}

line_selfmade::~line_selfmade() {
    erase();
}

void line_selfmade::draw() {
    draw_line(x+dx1, y+dy1, x+dx2, y+dy2, r, g, b);
}

void line_selfmade::erase() {
    draw_line(x+dx1, y+dy1, x+dx2, y+dy2, 0, 0, 0);
}

