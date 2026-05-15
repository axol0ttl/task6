#include <iostream>
#include "graphlib.h"
#include "objects/object.h"
#include "objects/MOsquare.h"
#include "objects/MOsector.h"
#include "objects/MOsegment.h"
#include "objects/MOline.h"
#include "objects/MOarc.h"

void Main(void) {
    float n = 4.5;

    // Создаем контейнер для управления объектами
    ObjectList objects;

    // Добавляем объекты в список
    objects.add(new MOline(400*n, 100*n, 0*n, 0*n, 0*n, 100*n, 255, 0, 0));
    objects.add(new MOline(400*n, 100*n, 0*n, 0*n, 100*n, 0*n, 255, 0, 0));
    objects.add(new MOline(400*n, 200*n, 0*n, 0*n, 100*n, 0*n, 255, 0, 0));
    objects.add(new MOline(500*n, 100*n, 0*n, 0*n, 0*n, 100*n, 255, 0, 0));
    objects.add(new MOline(400*n, 200*n, 0*n, 0*n, 50*n, 50*n, 255, 0, 0));
    objects.add(new MOline(500*n, 200*n, 0*n, 0*n, -50*n, 50*n, 255, 0, 0));
    objects.add(new MOarc(450*n, 150*n, 25*n, 0, 360, 255, 123, 123));
    objects.add(new MOsquare(450*n, 150*n, 50*n, 100*n, 255, 0, 255));
    objects.add(new MOsector(100*n, 150*n, 100*n, 30, 67, 0*n, 100*n, 255, 255, 0));
    objects.add(new MOsegment(300*n, 150*n, 50*n, 45, 135, 255, 0, 255));
    objects.add(new MNumber(555));

    wait4keyORmouse();

    // Проход по списку: Печать и Движение
    std::cout << "обработка списка объектов" << std::endl;
    Node* pCurrent = objects.getFirst();
    int index = 0;
    while (pCurrent != nullptr) {
        std::cout << index++ << ": ";

        // Полиморфный вызов печати
        pCurrent->data->print();

        // Попытка привести к фигуре для вызова move
        figure_selfmade* fig = dynamic_cast<figure_selfmade*>(pCurrent->data);
        if (fig) {
            fig->move(50*n, 20*n);
        }

        std::cout << std::endl;
        pCurrent = pCurrent->pNext;
    }

    wait4keyORmouse();

    // Проверка конкретного типа (dynamic_cast для первого элемента)
    Node* pFirst = objects.getFirst();
    if (pFirst && pFirst->data) {
        std::cout << "проверка первого элемента на тип MNumber..." << std::endl;
        MNumber* isNum = dynamic_cast<MNumber*>(pFirst->data);
        if (isNum) {
            isNum->print();
        }
        else {
            std::cout << "первый элемент не является числом" << std::endl;
        }
    }

    // Очистка памяти: удаление объектов, стирание с экрана
    std::cout << "очистка памяти и удаление объектов" << std::endl;
    pCurrent = objects.getFirst();
    while (pCurrent != nullptr) {
        // Стираем фигуру перед удалением
        figure_selfmade* fig = dynamic_cast<figure_selfmade*>(pCurrent->data);
        if (fig) fig->erase();

        pCurrent = pCurrent->pNext;
    }

    // ObjectList автоматически удалит все узлы в деструкторе
    objects.deleteObjects();

    wait4keyORmouse();
}