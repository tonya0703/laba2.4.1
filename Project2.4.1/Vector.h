//Vector.h
#pragma once
#include <iostream>

class Vector
{
private:
    int N; // ����� �������
    int* elements; // ����� ��� ���������� �������� �������

public:
    // ����������� �����������
    Vector(int size, int* data);

    // ����������� ��� ���������
    Vector();

    Vector(int N);

    // ����������� ���������
    Vector(const Vector& other);

    // ����������
    ~Vector();

    // ������ ������� (getters/setters)
    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);

    // ����� ��� ��������� �������
    Vector operator+(const Vector& other);

    // �������������� ��������� ���������
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    // ����� ��� ���������� ����� �������
    int calculateNorm() const;


    // �������������� ��������� �������� �� ���������
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
    friend std::istream& operator>>(std::istream& is, Vector& vector);

    operator std::string() const;
    int& operator[](int index);
};