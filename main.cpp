#include <iostream>
#include "graphlib.h"
#include "objects/object.h"
#include "objects/MOsquare.h"
#include "objects/MOsector.h"
#include "objects/MOsegment.h"
#include "objects/MOline.h"
#include "objects/MOarc.h"

// Структура узла двусвязного списка
struct Node {
    object* data;    // Указатель на объект (линия, сектор и т.д.)
    Node* pNext;     // Ссылка на следующий элемент
    Node* pPrev;     // Ссылка на предыдущий элемент
};

// Глобальные указатели списка
Node* pFirst = nullptr;
Node* pLast = nullptr;

// Функция добавления объекта в список
void AddToList(object* obj) {
    if (!obj) return;

    Node* pNew = new Node;
    pNew->data = obj;
    pNew->pNext = nullptr;
    pNew->pPrev = pLast;

    if (pLast) {
        pLast->pNext = pNew;
    }
    else {
        pFirst = pNew;
    }
    pLast = pNew;
}

void Main(void) {
    float n = 4.5;

    // 1. Создание объектов и добавление их в двусвязный список
    AddToList(new MOline(400*n, 100*n, 0*n, 0*n, 0*n, 100*n, 255, 0, 0));
    AddToList(new MOline(400*n, 100*n, 0*n, 0*n, 100*n, 0*n, 255, 0, 0));
    AddToList(new MOline(400*n, 200*n, 0*n, 0*n, 100*n, 0*n, 255, 0, 0));
    AddToList(new MOline(500*n, 100*n, 0*n, 0*n, 0*n, 100*n, 255, 0, 0));
    AddToList(new MOline(400*n, 200*n, 0*n, 0*n, 50*n, 50*n, 255, 0, 0));
    AddToList(new MOline(500*n, 200*n, 0*n, 0*n, -50*n, 50*n, 255, 0, 0));
    AddToList(new MOarc(450*n, 150*n, 25*n, 0, 360, 255, 123, 123));
    AddToList(new MOsquare(450*n, 150*n, 50*n, 100*n, 255, 0, 255));
    AddToList(new MOsector(100*n, 150*n, 100*n, 30, 67, 0*n, 100*n, 255, 255, 0));
    AddToList(new MOsegment(300*n, 150*n, 50*n, 45, 135, 255, 0, 255));
    AddToList(new MNumber(555));

    wait4keyORmouse();

    // 2. Проход по списку: Печать и Движение
    std::cout << "обработка списка объектов" << std::endl;
    Node* pCurrent = pFirst;
    int index = 0;
    while (pCurrent != nullptr) {
        std::cout << "Узел " << index++ << ": ";

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

    // 3. Пример проверки конкретного типа (dynamic_cast для первого элемента)
    if (pFirst && pFirst->data) {
        std::cout << "Проверка первого элемента на тип MNumber..." << std::endl;
        MNumber* isNum = dynamic_cast<MNumber*>(pFirst->data);
        if (isNum) {
            isNum->print();
        }
        else {
            std::cout << "Первый элемент не является числом." << std::endl;
        }
    }

    // 4. Очистка памяти: удаление объектов, стирание с экрана и удаление узлов
    std::cout << "очистка памяти и удаление объектов" << std::endl;
    pCurrent = pFirst;
    while (pCurrent != nullptr) {
        // Стираем фигуру перед удалением
        figure_selfmade* fig = dynamic_cast<figure_selfmade*>(pCurrent->data);
        if (fig) fig->erase();

        // Удаляем сам объект
        delete pCurrent->data;

        // Удаляем текущий узел и переходим к следующему
        Node* pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        delete pTemp;
    }

    // Сбрасываем указатели
    pFirst = pLast = nullptr;

    std::cout << "Готово. Все объекты и узлы удалены." << std::endl;
    wait4keyORmouse();
}