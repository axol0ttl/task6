//
// Created by arseny on 04/05/2026.
//

#include "msector.h"

#include <cmath>
#include "../graphlib.h"

msector::msector(
    float x, float y, float rad, float start, float end,
    float r1_len, float r2_len, float r, float g, float b)
    // ОБЯЗАТЕЛЬНО добавить инициализацию самого базового виртуального класса:
    : figure_selfmade(x, y, r, g, b),
      arc_selfmade(x, y, rad, start, end, r, g, b),
      line_selfmade(x, y, 0, 0, 0, 0, r, g, b),
      r1(r1_len), r2(r2_len)
{
    draw();
}

msector::~msector() {}

void msector::draw() {
    // 1. Рисуем саму дугу (край пиццы)
    // Используем параметры start и end, которые хранятся в arc_selfmade
    draw_arc(x, y, radius, start_angle, end_angle, r, g, b);

    // Переводим градусы в радианы для функций cos/sin
    float rad_start = (start_angle * 3.14159f) / 180.0f;
    float rad_end = (end_angle * 3.14159f) / 180.0f;

    // 2. Рисуем первый радиус (от центра к началу дуги)
    draw_line(x +r1*cosf(rad_start), y + r1*sinf(rad_start),
            x + r2*cosf(rad_start), y + r2*sinf(rad_start), r, g, b);

    // 3. Рисуем второй радиус (от центра к концу дуги)
    draw_line(x+r1*cosf(rad_end), y+r1*sinf(rad_end),
        x +r2*cosf(rad_end), y + r2*sinf(rad_end), r, g, b);
}

void msector::erase() {
    // cтираем дугу (это сработает, так как параметры дуги хранятся в родителе)
    arc_selfmade::erase();

    // cтираем радиусы вручную черным цветом, просто скопировав по сути метод draw
    float rad_start = (start_angle * 3.14159f) / 180.0f;
    float rad_end = (end_angle * 3.14159f) / 180.0f;
    draw_line(x +r1*cosf(rad_start), y + r1*sinf(rad_start),
            x + r2*cosf(rad_start), y + r2*sinf(rad_start), 0, 0, 0);
    draw_line(x+r1*cosf(rad_end), y+r1*sinf(rad_end),
        x +r2*cosf(rad_end), y + r2*sinf(rad_end), 0, 0, 0);

}

void msector::move(float dx, float dy) {
    figure_selfmade::move(dx, dy);
}
