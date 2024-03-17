//Vector.cpp
#include "Vector.h"
#include <sstream>

// ����������� �����������
Vector::Vector(int size, int* data) : N(size) {
    elements = new int[N];
    for (int i = 0; i < N; ++i) {
        elements[i] = data[i];
    }
}

Vector::Vector(int size) : N(size) {
    elements = new int[N];
    for (int i = 0; i < N; i++) {
        elements[i] = 0;
    }
}

// ����������� ��� ���������
Vector::Vector() : N(0), elements(nullptr) {
    elements = new int[N];
}

// ����������� ���������
Vector::Vector(const Vector& other) : N(other.N) {
    elements = new int[N];
    for (int i = 0; i < N; ++i) {
        elements[i] = other.elements[i];
    }
}

// ����������
Vector::~Vector() {
    delete[] elements;
}

// ������ ������� (getters/setters)
int Vector::getSize() const {
    return N;
}

int Vector::getElement(int index) const {
    if (index >= 0 && index < N) {
        return elements[index];
    }
    return -1; // ��������� -1 � ��� ������ �� ��� ������
}

void Vector::setElement(int index, int value) {
    if (index >= 0 && index < N) {
        elements[index] = value;
    }
}

Vector Vector::operator+(const Vector& other) {
    Vector result(this->N);
    if (N <= other.N) {
        Vector result(this->N); // ��������� ������ � ������� N
    }
    else Vector result(other.N);
    int tmp;
    for (int i = 0; i < N; ++i) {
        tmp = elements[i] + other.elements[i];
        result.elements[i] = tmp; // ������ ������� �������� ���� �������
    }

    return result; // ��������� ���������
}


// �������������� ��������� ���������
bool Vector::operator==(const Vector& other) const {
    if (N != other.N) {
        return false;
    }
    for (int i = 0; i < N; ++i) {
        if (elements[i] != other.elements[i]) {
            return false;
        }
    }
    return true;
}

bool Vector::operator!=(const Vector& other) const {
    return !(*this == other);
}

// ����� ��� ���������� ����� �������
int Vector::calculateNorm() const {
    int max = elements[0];
    int min = elements[0];
    for (int i = 1; i < N; ++i) {
        if (elements[i] > max) {
            max = elements[i];
        }
        if (elements[i] < min) {
            min = elements[i];
        }
    }
    return max - min;
}

// �������������� ��������� �������� �� ���������
std::ostream& operator << (std::ostream& out, const Vector& r)
{
    out << std::string(r);
    return out;
}

std::istream& operator>>(std::istream& is, Vector& vector) {
    int size;
    std::cout << "Enter size of vector: ";
    is >> size;
    if (size <= 0) {
        return is;
    }
    vector.N = size;
    vector.elements = new int[size];
    std::cout << "Enter elements of vector:\n";
    for (int i = 0; i < size; ++i) {
        is >> vector.elements[i];
    }
    return is;
}

// �������������� ��������� ���������� ���� �� �������� �����
Vector::operator std::string() const {
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < N; ++i) {
        ss << elements[i];
        if (i != N - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

// �������������� ��������� ������������
int& Vector::operator[](int index) {
    if (index < 0 || index >= N) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}