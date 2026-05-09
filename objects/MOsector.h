#pragma once
#include <iostream>
#include "object.h"
#include "MOline.h"
#include "MOarc.h"
#include "../line/line_selfmade.h"
#include "../arc/arc_selfmade.h"
#include "../graphlib.h"
#include <cmath>

class MOsector : public object, public line_selfmade, public arc_selfmade {
private:
    std::string componentSuffix;
public:
    MOsector(float x, float y, float radius, float start_angle, float end_angle, float r1_len, float r2_len, float r, float g, float b, const std::string& suffix = "сектора")
        : figure_selfmade(x, y, r, g, b),
          arc_selfmade(x, y, radius, start_angle, end_angle, r, g, b),
          line_selfmade(x, y, 0, 0, 0, 0, r, g, b),
          object(),
          componentSuffix(suffix)
    {
        draw();
    }

    void draw() override {
        // Рисуем дугу
        arc_selfmade::draw();

        // Рисуем два радиуса, соединяющие центр с концами дуги
        float rad_start = (start_angle * 3.14159f) / 180.0f;
        float rad_end = (end_angle * 3.14159f) / 180.0f;

        draw_line(x, y, x + radius * cosf(rad_start), y + radius * sinf(rad_start), r, g, b);
        draw_line(x, y, x + radius * cosf(rad_end), y + radius * sinf(rad_end), r, g, b);
    }

    void erase() override {
        // Стираем дугу
        arc_selfmade::erase();

        // Стираем два радиуса
        float rad_start = (start_angle * 3.14159f) / 180.0f;
        float rad_end = (end_angle * 3.14159f) / 180.0f;

        draw_line(x, y, x + radius * cosf(rad_start), y + radius * sinf(rad_start), 0, 0, 0);
        draw_line(x, y, x + radius * cosf(rad_end), y + radius * sinf(rad_end), 0, 0, 0);
    }

    void print(const std::string& suffix = "") const override {
        std::cout << "я сектор" << suffix << std::endl;
        MOline::print_impl(componentSuffix);
        MOline::print_impl(componentSuffix);
        MOarc::print_impl(componentSuffix);
    }
};