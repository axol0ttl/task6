#include "square_selfmade.h"
#include "../graphlib.h"
#include <unordered_map>

// Скрытый контейнер для хранения состояния объектов
namespace {
    struct SquareData {
        float width;
        float height;
    };

    // Ключ - указатель на объект, значение - его размеры
    std::unordered_map<const square_selfmade*, SquareData> squares_state;
}

square_selfmade::square_selfmade(float x, float y, float w, float h, float r, float g, float b)
    : figure_selfmade(x, y, r, g, b) {
    // Сохраняем данные в контейнер
    squares_state[this] = {w, h};
    draw();
}

square_selfmade::~square_selfmade() {
    erase();
    // Обязательно удаляем запись при разрушении объекта
    squares_state.erase(this);
}

void square_selfmade::draw() {
    // Достаем значения из контейнера
    float w = squares_state[this].width;
    float h = squares_state[this].height;

    draw_line(x, y, x + w, y, r, g, b);
    draw_line(x + w, y, x + w, y + h, r, g, b);
    draw_line(x + w, y + h, x, y + h, r, g, b);
    draw_line(x, y + h, x, y, r, g, b);
}

void square_selfmade::erase() {
    // Достаем значения из контейнера
    float w = squares_state[this].width;
    float h = squares_state[this].height;

    draw_line(x, y, x + w, y, 0, 0, 0);
    draw_line(x + w, y, x + w, y + h, 0, 0, 0);
    draw_line(x + w, y + h, x, y + h, 0, 0, 0);
    draw_line(x, y + h, x, y, 0, 0, 0);
}