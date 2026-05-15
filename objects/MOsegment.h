#pragma once
#include <iostream>
#include "object.h"
#include "MOline.h"
#include "MOarc.h"
#include "../line/line_selfmade.h"
#include "../arc/arc_selfmade.h"
#include "../graphlib.h"
#include <cmath>

class MOsegment : public object, public line_selfmade, public arc_selfmade {
private:
    std::string componentSuffix;
public:
    MOsegment(float x, float y, float radius, float start_angle, float end_angle, float r, float g, float b, const std::string& suffix = "сегмента")
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

        // Рисуем хорду (линию, соединяющую концы дуги)
        float rad_start = (start_angle * 3.14159f) / 180.0f;
        float rad_end = (end_angle * 3.14159f) / 180.0f;

        float x1 = x + radius * cosf(rad_start);
        float y1 = y + radius * sinf(rad_start);
        float x2 = x + radius * cosf(rad_end);
        float y2 = y + radius * sinf(rad_end);

        draw_line(x1, y1, x2, y2, r, g, b);
    }

    void erase() override {
        // Стираем дугу
        arc_selfmade::erase();

        // Стираем хорду
        float rad_start = (start_angle * 3.14159f) / 180.0f;
        float rad_end = (end_angle * 3.14159f) / 180.0f;

        float x1 = x + radius * cosf(rad_start);
        float y1 = y + radius * sinf(rad_start);
        float x2 = x + radius * cosf(rad_end);
        float y2 = y + radius * sinf(rad_end);

        draw_line(x1, y1, x2, y2, 0, 0, 0);
    }

    void print(const std::string& suffix = "") const override {
        std::cout << "я сегмент" << suffix << std::endl;

        MOline::print_impl(componentSuffix);
        MOarc::print_impl(componentSuffix);
    }
};