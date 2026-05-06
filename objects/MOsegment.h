#pragma once
#include <iostream>
#include "object.h"
#include "MOline.h" // Нужно добавить эти инклюды
#include "MOarc.h"  // Чтобы компилятор знал о существовании этих классов
#include "../msegment/msegment.h"

class MOsegment : public object, public msegment {
public:
    MOsegment(float x, float y, float radius, float start_angle, float end_angle, float r, float g, float b)
: figure_selfmade(x, y, r, g, b),
  arc_selfmade(x, y, radius, start_angle, end_angle, r, g, b),
  line_selfmade(x, y, 0, 0, 0, 0, r, g, b),
  msegment(x, y, radius, start_angle, end_angle, r, g, b),
  object() {
        draw();
    }

    void print(const std::string& suffix = "") const override {
        std::cout << "я сегмент" << suffix << std::endl; // Исправил "сектор" на "сегмент"


        MOline::print_impl(" сегмента");
        MOarc::print_impl(" сегмента");
        // static_cast<const MOline*>(this)->print(" сегмента");
        // static_cast<const MOarc*>(this)->print(" сегмента");
    }
};