#include <iostream>
#include "graphlib.h"
#include "objects/object.h"
#include "objects/MOsquare.h"
#include "objects/MOsector.h"
#include "objects/MOsegment.h"
#include "objects/MOline.h"
#include "objects/MOarc.h"


void Main(void) {
    const int num = 11;
    object* list[num];
    float n = 4.5;

    //Создаем разные объекты

    list[0] = new    MOline(400*n, 100*n, 0*n, 0*n, 0*n, 100*n, 255, 0, 0);
    list[1] = new    MOline(400*n, 100*n, 0*n, 0*n, 100*n, 0*n, 255, 0, 0);
    list[2] = new    MOline(400*n, 200*n, 0*n, 0*n, 100*n, 0*n, 255, 0, 0);
    list[3] = new    MOline(500*n, 100*n, 0*n, 0*n, 0*n, 100*n, 255, 0, 0);
    list[4] = new    MOline(400*n, 200*n, 0*n, 0*n, 50*n, 50*n, 255, 0, 0);
    list[5] = new    MOline(500*n, 200*n, 0*n, 0*n, -50*n, 50*n, 255, 0, 0);
    list[6] = new    MOarc(450*n, 150*n, 25*n, 0, 360, 255, 123, 123);
    list[7] = new    MOsquare(450*n, 150*n, 50*n, 100*n, 255, 0, 255); // квадрат настоящий
    list[8] = new    MOsector(100*n, 150*n, 100*n, 30, 67, 0*n, 100*n, 255, 255, 0);
    list[9] = new    MOsegment(300*n, 150*n, 50*n, 45, 135, 255, 0, 255); // сегмент (дуга + арка)
    list[10]= new    MNumber(555);

    wait4keyORmouse();

    // Демонстрируем полиморфизм и dynamic_cast
    for (int i = 0; i < num; i++) {
        std::cout << "Объект " << i << ": ";
        list[i]->print(); // Виртуальный метод печати
        std::cout << std::endl;
        // Пытаемся привести к фигуре, чтобы подвинуть/нарисовать
        try {
            figure_selfmade* fig = dynamic_cast<figure_selfmade*>(list[i]);



            if (fig) { // если фигура, сдвигаем
                fig->move(50*n, 20*n); // Метод фигуры
            }
            else {
                // Это не фигура, пропускаем сдвиг
            }
        }
        catch (const std::bad_cast& e) {
            std::cerr << "ошибка приведения" << std::endl;
        }
    }
    wait4keyORmouse();

    try {
        std::cout << "\nПроверка первого элемента на число..." << std::endl;
        MNumber& numRef = dynamic_cast<MNumber&>(*list[0]);
        numRef.print();
    } catch (const std::bad_cast& e) {
        std::cerr << "Ошибка приведения!" << std::endl;
    }

    // Чистка
    for (int i = 0; i < num; i++) {
        // Если это фигура, сотрем с экрана перед удалением
        try {
            figure_selfmade* fig = dynamic_cast<figure_selfmade*>(list[i]);
            if (fig) fig->erase();

            delete list[i];
        }
        catch (const std::bad_cast& e) {
            std::cerr << "ошибка приведения" << std::endl;
        }
    }
    wait4keyORmouse();

}