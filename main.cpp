#include <iostream>
#include "graphlib.h"
#include "objects/object.h"
#include "objects/MOsquare.h"
#include "objects/MOsector.h"
#include "objects/MOsegment.h"
#include "objects/MOline.h"
#include "objects/MOarc.h"


void Main(void) {
    const int num = 5;
    object* list[num];
    float n = 4.5;

    // 1. Создаем разные объекты
    list[0] = new MNumber(555);
    list[1] = new MOline(100*n, 100*n, 0, 0, 100*n, 100*n, 255, 0, 0);
    list[2] = new MOsquare(200*n, 200*n, 50*n, 50*n, 0, 255, 0);
    list[3] = new MOsector(300*n, 150*n, 50*n, 0, 90, 50*n, 50*n, 0, 0, 255);
    list[4] = new MNumber(7);

    // 2. Демонстрируем полиморфизм и dynamic_cast
    for (int i = 0; i < num; i++) {
        std::cout << "Объект " << i << ": ";
        list[i]->print(); // Виртуальный метод печати
        std::cout << std::endl;
        // Пытаемся привести к фигуре, чтобы подвинуть/нарисовать
        figure_selfmade* fig = dynamic_cast<figure_selfmade*>(list[i]);

        if (fig) { // если фигура, сдвигаем
            fig->move(20, 20); // Метод фигуры
            wait4keyORmouse();
        } else {
            // Это не фигура, пропускаем сдвиг
        }
    }

    // 3. Пример со ссылкой (на оценку 5+)
    try {
        std::cout << "\nПроверка первого элемента на число..." << std::endl;
        MNumber& numRef = dynamic_cast<MNumber&>(*list[0]);
        numRef.print();
    } catch (const std::bad_cast& e) {
        std::cout << "Ошибка приведения!" << std::endl;
    }

    // Чистка
    for (int i = 0; i < num; i++) {
        // Если это фигура, сотрем с экрана перед удалением
        figure_selfmade* fig = dynamic_cast<figure_selfmade*>(list[i]);
        if (fig) fig->erase();

        delete list[i];
    }

    std::cout << "Готово!" << std::endl;
    wait4keyORmouse();
}
