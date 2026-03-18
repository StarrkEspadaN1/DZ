#include <iostream>

// Выделение мемори
int* allocateArray(int size) {
    return new int[size];
}

// Инициализация
void initArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

// Печать
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Удаление
void deleteArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}


int main() {
    int size = 5;

    int* arr = allocateArray(size);
    initArray(arr, size);

    std::cout << "Массив: ";
    printArray(arr, size);

    deleteArray(arr);

    return 0;
}
