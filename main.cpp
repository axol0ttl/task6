#include <iostream>
#include "graphlib.h"
#include "line/line_selfmade.h"
#include "arc/arc_selfmade.h"
#include "square/square_selfmade.h"
#include "msector/msector.h"
#include "msegment/msegment.h"

void Main(void) {
    // Создаем массив указателей на базовый класс Figure
    const int num_figures = 10;
    figure_selfmade* picture[num_figures];
    float n = 4.5; // масштаб
    //множитель к размеру
    //заполняем массив конкретными объектами
    //используем 'new', так как работаем с указателями


    picture[0] = new line_selfmade(400*n, 100*n, 0*n, 0*n, 0*n, 100*n, 255, 0, 0);
    picture[1] = new line_selfmade(400*n, 100*n, 0*n, 0*n, 100*n, 0*n, 255, 0, 0);
    picture[2] = new line_selfmade(400*n, 200*n, 0*n, 0*n, 100*n, 0*n, 255, 0, 0);
    picture[3] = new line_selfmade(500*n, 100*n, 0*n, 0*n, 0*n, 100*n, 255, 0, 0);
    picture[4] = new line_selfmade(400*n, 200*n, 0*n, 0*n, 50*n, 50*n, 255, 0, 0);
    picture[5] = new line_selfmade(500*n, 200*n, 0*n, 0*n, -50*n, 50*n, 255, 0, 0);

    picture[6] = new  arc_selfmade(450*n, 150*n, 25*n, 0, 360, 255, 123, 123);
    picture[7] = new square_selfmade(450*n, 150*n, 50*n, 100*n, 255, 0, 255); // квадрат настоящий
    // новое
    picture[8] = new msector(100*n, 150*n, 100*n, 30, 67, 0*n, 100*n, 255, 255, 0);
    picture[9] = new msegment(300*n, 150*n, 50*n, 45, 135, 255, 0, 255); // сегмент (дуга + хорда)

    for (int i = 0; i < num_figures; i++) {
        picture[i]->change_color(0, 255, 0); // меняем цвет третей фигуры на зеленый
        // Ожидание
        wait4keyORmouse();
    }

    std::cout << "Перемещаем все фигуры разом" << std::endl;
    for (int i = 0; i < num_figures; i++) {
        picture[i]->move(100, 350); // Сдвигаем каждую фигуру на 100 вправо и 50 вниз
    }

    // ждем
    wait4keyORmouse();

    // чистка памяти
    // благодаря 'virtual ~Figure()', вызов delete для Figure* // правильно вызовет деструктор line_selfmade или arc_selfmade, и фигура сотрется (erase)
    std::cout << "удаляем фигуры (они должны исчезнуть с экрана)" << std::endl;
    for (int i = 0; i < num_figures; i++) {
        picture[i]->erase(); // Стираем фигуру с экрана
    }
       wait4keyORmouse();
 }
