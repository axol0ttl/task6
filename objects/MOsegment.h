//
// Created by arseny on 04/05/2026.
//

#pragma once
#include <iostream>
#include "object.h"
#include "../line/line_selfmade.h"
#include "../arc/arc_selfmade.h"
#include "../msegment/msegment.h"

class MOsegment : public object, public msegment {
    public:
    MOsegment(float x, float y, float radius, float start_angle, float end_angle, float r, float g, float b)
: figure_selfmade(x, y, r, g, b),      // 1. Корень всей графики
  arc_selfmade(x, y, radius, start_angle, end_angle, r, g, b), // 2. Виртуальный родитель
  line_selfmade(x, y, 0, 0, 0, 0, r, g, b), // 3. Виртуальный родитель (параметры dx/dy зависят от вашей реализации msector)
    msegment(x, y, radius, start_angle, end_angle, r, g, b), // 4. Прямой родитель
  object() {
        draw();
    }// 5. Другой прямой родитель

void print() const override {
        std::cout << "я сегмент" << std::endl;
    }
};