#include <iostream>

// Вставка элемента по индексу
void insertElement(int*& arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        std::cout << "Ошибка: индекс вне диапазона!" << std::endl;
        return;
    }

    int* newArr = new int[size + 1];

    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];

    newArr[index] = value;

    for (int i = index; i < size; i++)
        newArr[i + 1] = arr[i]

    delete[] arr;
    arr = newArr;
    size++;
}

// Удаление элемента по индексу
void removeElement(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Ошибка: индекс вне диапазона!" << std::endl;
        return;
    }

    int* newArr = new int[size - 1];

    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];

    for (int i = index + 1; i < size; i++)
        newArr[i - 1] = arr[i];

    delete[] arr;
    arr = newArr;
    size--;
}

// Вывод массива
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size = 4;
    int* arr = new int[size] {10, 20, 30, 40};

    std::cout << "Исходный массив: ";
    printArray(arr, size);

    insertElement(arr, size, 2, 25);
    std::cout << "После вставки 25: ";
    printArray(arr, size);

    removeElement(arr, size, 3);
    std::cout << "После удаления элемента на позиции 3: ";
    printArray(arr, size);

    delete[] arr; // освобождение памяти
    return 0;
}