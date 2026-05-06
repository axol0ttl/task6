#include "line_selfmade.h"
#include "../graphlib.h"
#include <unordered_map>

namespace {
    struct LineData {
        float dx1, dy1, dx2, dy2;
    };
    // Хранилище для всех созданных линий
    std::unordered_map<const line_selfmade*, LineData> line_state;
}

line_selfmade::line_selfmade(float x, float y, float dx1, float dy1, float dx2, float dy2, float r, float g, float b)
    : figure_selfmade(x,y,r,g,b) 
{
    // Записываем данные в контейнер
    line_state[this] = {dx1, dy1, dx2, dy2};
    draw();
}

line_selfmade::~line_selfmade() {
    erase();
    // Чистим за собой
    line_state.erase(this);
}

void line_selfmade::draw() {
    // Извлекаем данные по указателю this
    const LineData& data = line_state[this];
    draw_line(x + data.dx1, y + data.dy1, x + data.dx2, y + data.dy2, r, g, b);
}

void line_selfmade::erase() {
    const LineData& data = line_state[this];
    draw_line(x + data.dx1, y + data.dy1, x + data.dx2, y + data.dy2, 0, 0, 0);
}