//
// Created by arseny on 28/04/2026.
//
#pragma once
#include "../figure/figure_selfmade.h"

class square_selfmade : virtual public figure_selfmade {
private:
    float width;
    float height;

public:
    // Конструктор: точка привязки (x, y), размеры фигуры (w, h) и цвет (r, g, b)
    square_selfmade(float x, float y, float w, float h, float r, float g, float b);

    // Переопределенный деструктор
    ~square_selfmade() override;

    // Переопределенный метод отрисовки
    void draw() override;
    void erase() override;
};
