#include <iostream>

//  Пример
void normalMode() {
    int a, b;
    std::cout << "Введите 2 числа: ";
    std::cin >> a >> b;
    std::cout << "Сумма: " << a + b << std::endl;
}

// argc argv
void argsMode(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Нужно 2 аргумента!" << std::endl;
        return;
    }

    int a = std::atoi(argv[1]);
    int b = std::atoi(argv[2]);

    std::cout << "Сумма из аргументов: " << a + b << std::endl;
}

int main(int argc, char* argv[]) {
    //void main - возврашает функцию и она будет повторяться / int main - инцеелезирует функию только один раз но это всё зависит от стандарта
	//  main argc argv - принемает аргументы из терминала
    setlocale(LC_ALL, "Russian");
    if (argc > 1) {
        argsMode(argc, argv);
    }
    else {
        normalMode();
    }

    return 0;
}
