//Main.cpp
#include "Vector.h"
#include <iostream>
#include <string>

int main() {
    // Створення векторів
    Vector v1(3, new int[3] {1, 2, 3});
    Vector v2;
    Vector v3;

    // Виведення розміру класу Vector
    std::cout << "Size of Vector class: " << sizeof(Vector) << " bytes\n";
    std::cout << "Size of Vector class with pragma pack(1): " << sizeof(Vector) << " bytes\n\n";

    // Перевірка конструктора копіювання
    Vector v4 = v1;

    // Виведення векторів
    std::cout << "Vector 1: " << v1 << std::endl;
    std::cout << "Vector 2: " << v2 << std::endl;
    std::cout << "Vector 3: " << v3 << std::endl;
    std::cout << "Vector 4 (copy of Vector 1): " << v4 << std::endl << std::endl;

    // Введення вектора з клавіатури
    std::cout << "Enter elements for Vector 2:\n";
    std::cin >> v2;
    std::cout << "Vector 2 after input: " << v2 << std::endl << std::endl;

    // Перевірка методу додавання векторів
    std::cout << "Addition of Vector 1 and Vector 2: " << v1 + v2 << std::endl << std::endl;

    // Перевірка методів порівняння
    if (v1 == v4) {
        std::cout << "Vector 1 is equal to Vector 4\n";
    }
    else {
        std::cout << "Vector 1 is not equal to Vector 4\n";
    }
    if (v2 != v3) {
        std::cout << "Vector 2 is not equal to Vector 3\n";
    }
    else {
        std::cout << "Vector 2 is equal to Vector 3\n";
    }

    // Перевірка методу обчислення норми вектора
    std::cout << "Norm of Vector 3: " << v2.calculateNorm() << std::endl;

    Vector v(3, new int[3] {1, 2, 3});

    // Індексування
    std::cout << "Element at index 1: " << v[1] << std::endl;
    v[1] = 5; // Зміна значення елемента за індексом
    std::cout << "Modified vector: " << v << std::endl;

    return 0;
}