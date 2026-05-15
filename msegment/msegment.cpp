//
// Created by arseny on 04/05/2026.
//

#include "msegment.h"
#include <cmath>
#include "../graphlib.h"

msegment::msegment(float x, float y, float rad, float start, float end,
                   float r, float g, float b)
    : figure_selfmade(x, y, r, g, b),
      arc_selfmade(x, y, rad, start, end, r, g, b),
      line_selfmade(x, y, 0, 0, 0, 0, r, g, b) // Начальные значения для линии не важны, пересчитаем в draw
{
    draw();
}

msegment::~msegment() {}

void msegment::draw() {
    // 1. Рисуем дугу
    draw_arc(x, y, radius, start_angle, end_angle, r, g, b);

    // 2. Рассчитываем координаты начала и конца хорды
    float rad_start = (start_angle * 3.14159f) / 180.0f;
    float rad_end = (end_angle * 3.14159f) / 180.0f;

    float x1 = x + radius * cosf(rad_start);
    float y1 = y + radius * sinf(rad_start);
    float x2 = x + radius * cosf(rad_end);
    float y2 = y + radius * sinf(rad_end);

    // 3. Рисуем хорду
    draw_line(x1, y1, x2, y2, r, g, b);
}

void msegment::erase() {
    // Стираем дугу через родительский метод
    arc_selfmade::erase();

    // Стираем хорду (черным цветом)
    float rad_start = (start_angle * 3.14159f) / 180.0f;
    float rad_end = (end_angle * 3.14159f) / 180.0f;

    float x1 = x + radius * cosf(rad_start);
    float y1 = y + radius * sinf(rad_start);
    float x2 = x + radius * cosf(rad_end);
    float y2 = y + radius * sinf(rad_end);

    draw_line(x1, y1, x2, y2, 0, 0, 0);
}
