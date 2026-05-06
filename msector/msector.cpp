#include "msector.h"
#include <cmath>
#include <unordered_map>
#include "../graphlib.h"

namespace {
    struct SectorData {
        float r1;
        float r2;
    };
    std::unordered_map<const msector*, SectorData> sector_state;
}

msector::msector(
    float x, float y, float rad, float start, float end,
    float r1_len, float r2_len, float r, float g, float b)
    : figure_selfmade(x, y, r, g, b),
      arc_selfmade(x, y, rad, start, end, r, g, b),
      line_selfmade(x, y, 0, 0, 0, 0, r, g, b) 
{
    // Сохраняем r1 и r2 в карту
    sector_state[this] = {r1_len, r2_len};
    draw();
}

msector::~msector() {
    erase();
    // Чистим карту
    sector_state.erase(this);
}

void msector::draw() {
    // Получаем данные из карты
    float r1_val = sector_state[this].r1;
    float r2_val = sector_state[this].r2;

    // Рисуем дугу (параметры x, y, radius и т.д. берем из родительских классов)
    draw_arc(x, y, radius, start_angle, end_angle, r, g, b);

    float rad_start = (start_angle * 3.14159f) / 180.0f;
    float rad_end = (end_angle * 3.14159f) / 180.0f;

    // Рисуем два радиуса
    draw_line(x + r1_val * cosf(rad_start), y + r1_val * sinf(rad_start),
              x + r2_val * cosf(rad_start), y + r2_val * sinf(rad_start), r, g, b);

    draw_line(x + r1_val * cosf(rad_end), y + r1_val * sinf(rad_end),
              x + r2_val * cosf(rad_end), y + r2_val * sinf(rad_end), r, g, b);
}

void msector::erase() {
    float r1_val = sector_state[this].r1;
    float r2_val = sector_state[this].r2;

    arc_selfmade::erase();

    float rad_start = (start_angle * 3.14159f) / 180.0f;
    float rad_end = (end_angle * 3.14159f) / 180.0f;

    draw_line(x + r1_val * cosf(rad_start), y + r1_val * sinf(rad_start),
              x + r2_val * cosf(rad_start), y + r2_val * sinf(rad_start), 0, 0, 0);
    draw_line(x + r1_val * cosf(rad_end), y + r1_val * sinf(rad_end),
              x + r2_val * cosf(rad_end), y + r2_val * sinf(rad_end), 0, 0, 0);
}

