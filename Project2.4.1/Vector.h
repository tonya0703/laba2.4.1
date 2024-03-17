//Vector.h
#pragma once
#include <iostream>

class Vector
{
private:
    int N; // Розмір вектора
    int* elements; // Масив для збереження елементів вектора

public:
    // Конструктор ініціалізації
    Vector(int size, int* data);

    // Конструктор без аргументів
    Vector();

    Vector(int N);

    // Конструктор копіювання
    Vector(const Vector& other);

    // Деструктор
    ~Vector();

    // Методи доступу (getters/setters)
    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);

    // Метод для додавання векторів
    Vector operator+(const Vector& other);

    // Перевантаження операторів порівняння
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    // Метод для обчислення норми вектора
    int calculateNorm() const;


    // Перевантаження операторів введення та виведення
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
    friend std::istream& operator>>(std::istream& is, Vector& vector);

    operator std::string() const;
    int& operator[](int index);
};