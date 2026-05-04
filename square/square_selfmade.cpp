//
// Created by arseny on 28/04/2026.
//

#include "square_selfmade.h"
#include "../graphlib.h"

// Конструктор.
// Мы передаем координаты и цвет в базовый класс figure_selfmade,
// а ширину и высоту сохраняем в текущем классе.
square_selfmade::square_selfmade(float x, float y, float w, float h, float r, float g, float b) :figure_selfmade(x, y, r, g, b), width(w), height(h) {
    draw();
}

// Деструктор (если удаление реализовано в ~figure_selfmade через вызов пустого цвета, то тут оставляем пустым)
square_selfmade::~square_selfmade() {
    erase();
}

// Метод рисования: собираем прямоугольник из четырех линий
void square_selfmade::draw() {
    // В базовом классе у нас хранятся поля x, y (точка привязки) и r, g, b (цвет)

    // 1. Верхняя грань (идем вправо на width)
    draw_line(x, y, x + width, y, r, g, b);

    // 2. Правая грань (идем вниз на height)
    draw_line(x + width, y, x + width, y + height, r, g, b);

    // 3. Нижняя грань (идем влево обратно к точке x)
    draw_line(x + width, y + height, x, y + height, r, g, b);

    // 4. Левая грань (поднимаемся обратно к точке y)
    draw_line(x, y + height, x, y, r, g, b);
}

void square_selfmade::erase() {
    draw_line(x, y, x + width, y, 0, 0, 0);

    // 2. Правая грань (идем вниз на height)
    draw_line(x + width, y, x + width, y + height, 0, 0, 0);

    // 3. Нижняя грань (идем влево обратно к точке x)
    draw_line(x + width, y + height, x, y + height, 0, 0, 0);

    // 4. Левая грань (поднимаемся обратно к точке y)
    draw_line(x, y + height, x, y, 0, 0, 0);
}