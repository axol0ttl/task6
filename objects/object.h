//
// Created by arseny on 04/05/2026.
//
#pragma once
#include <iostream>
#include <string>
#include <memory>

class object {
public:
    virtual ~object() {}
    virtual void print(const std::string& suffix = "") const {
        std::cout << "я объект " << suffix << std::endl;
    }
};

class MNumber : public object {
private:
    int value;
public:
    MNumber(int v) : value(v) {}
    void print(const std::string& suffix = "") const override {
        std::cout << "я число: " << value << suffix << std::endl;
    }
};

// Вспомогательные структуры для внутреннего управления списком
struct Node {
    object* data;
    Node* pNext;
    Node* pPrev;

    Node(object* obj) : data(obj), pNext(nullptr), pPrev(nullptr) {}
};

// Контейнер для управления двусвязным списком объектов
class ObjectList {
private:
    Node* pFirst;
    Node* pLast;

public:
    ObjectList() : pFirst(nullptr), pLast(nullptr) {}

    ~ObjectList() {
        clear();
    }

    // Добавить объект в конец списка
    void add(object* obj) {
        if (!obj) return;

        Node* pNew = new Node(obj);
        pNew->pPrev = pLast;

        if (pLast) {
            pLast->pNext = pNew;
        } else {
            pFirst = pNew;
        }
        pLast = pNew;
    }

    // Получить указатель на первый элемент (для обхода)
    Node* getFirst() const {
        return pFirst;
    }

    // Очистить список (удалить все узлы)
    void clear() {
        Node* pCurrent = pFirst;
        while (pCurrent != nullptr) {
            Node* pTemp = pCurrent;
            pCurrent = pCurrent->pNext;
            delete pTemp;
        }
        pFirst = pLast = nullptr;
    }

    // Удалить объекты (без удаления узлов)
    void deleteObjects() {
        Node* pCurrent = pFirst;
        while (pCurrent != nullptr) {
            delete pCurrent->data;
            pCurrent = pCurrent->pNext;
        }
    }
};