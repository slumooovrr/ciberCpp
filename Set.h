#ifndef SET_H
#define SET_H

#include <iostream>

template <typename T>
class Set {
private:
    T* elements;
    int capacity;
    int size;

public:
    Set();
    Set(const Set<T>& other);
    ~Set();
    Set<T>& operator=(const Set<T>& other);

    void add(const T& element);
    void remove(const T& element);
    void clear();

    bool contains(const T& element) const;
    int getSize() const;

    Set<T> connectSet(const Set<T>& other) const;
    Set<T> intersection(const Set<T>& other) const;
    Set<T> difference(const Set<T>& other) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Set<U>& set);
};

template <typename T>
Set<T>::Set() : elements(nullptr), capacity(0), size(0) {}

template <typename T>
Set<T>::Set(const Set<T>& other) : elements(nullptr), capacity(0), size(0) {
    *this = other;
}

template <typename T>
Set<T>::~Set() {
    delete[] elements;
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& other) {
    if (this != &other) {
        delete[] elements;
        capacity = other.capacity;
        size = other.size;
        elements = new T[capacity];
        std::copy(other.elements, other.elements + size, elements);
    }
    return *this;
}

template <typename T>
void Set<T>::add(const T& element) {
    if (!contains(element)) {
        if (size >= capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newElements = new T[newCapacity];
            std::copy(elements, elements + size, newElements);
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }
        elements[size++] = element;
    }
}

template <typename T>
void Set<T>::remove(const T& element) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        std::copy(elements + index + 1, elements + size, elements + index);
        size--;
    }
}

template <typename T>
void Set<T>::clear() {
    delete[] elements;
    elements = nullptr;
    capacity = size = 0;
}

template <typename T>
bool Set<T>::contains(const T& element) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
int Set<T>::getSize() const {
    return size;
}

template <typename T>
Set<T> Set<T>::connectSet(const Set<T>& other) const {
    Set<T> result = *this;
    for (int i = 0; i < other.size; ++i) {
        result.add(other.elements[i]);
    }
    return result;
}

template <typename T>
Set<T> Set<T>::intersection(const Set<T>& other) const {
    Set<T> result;
    for (int i = 0; i < size; ++i) {
        if (other.contains(elements[i])) {
            result.add(elements[i]);
        }
    }
    return result;
}

template <typename T>
Set<T> Set<T>::difference(const Set<T>& other) const {
    Set<T> result = *this;
    for (int i = 0; i < other.size; ++i) {
        result.remove(other.elements[i]);
    }
    return result;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Set<U>& set) {
    os << "{";
    for (int i = 0; i < set.size; ++i) {
        os << set.elements[i];
        if (i < set.size - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

#endif