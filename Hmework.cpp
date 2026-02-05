#include <iostream>


const int C = 18;   // вагоны
const int S = 36;   // места

void fillEmpty(int a[C][S]) {
    for (int i = 0; i < C; i++)
        for (int j = 0; j < S; j++)
            a[i][j] = 0;
}

void fillRandom(int a[C][S]) {
    for (int i = 0; i < C; i++)
        for (int j = 0; j < S; j++)
            a[i][j] = std::rand() % 2;
}

void print(int a[C][S]) {
    for (int i = 0; i < C; i++) {
        std::cout << "Вагон " << i + 1 << ": ";
        for (int j = 0; j < S; j++)
            std::cout << a[i][j] << " ";
    }
}

void change(int a[C][S], int c, int s, int v) {
    a[c][s] = v;
}

int freeCar(int a[C][S], int c) {
    int k = 0;
    for (int j = 0; j < S; j++)
        if (a[c][j] == 0)
            k++;
    return k;
}

int freeAll(int a[C][S]) {
    int sum = 0;
    for (int i = 0; i < C; i++)
        sum += freeCar(a, i);
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(0));

    int t[C][S];

    std::cout << "1 - случайно\n2 - всё пусто\n";
    int m;
    std::cin >> m;

    if (m == 1)
        fillRandom(t);
    else
        fillEmpty(t);

    print(t);

    int c, s;
    std::cout << "\n Введите вагон и место: ";
    std::cin >> c >> s;

    std::cout << "1 - занять, 0 - освободить: ";
    int v;
    std::cin >> v;

    change(t, c - 1, s - 1, v);

    std::cout << "\n После изменения: \n";
    print(t);

    std::cout << "\n Свободных в вагоне " << c << ": "
        << freeCar(t, c - 1);

    std::cout << "Свободных всего: "
        << freeAll(t);
}
