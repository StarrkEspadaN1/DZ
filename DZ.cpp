#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    double p_app = 99, p_or = 111, p_apr = 96, p_pe = 211;
    double p_tom = 991, p_on = 211, p_cuc = 843;
    double p_gar = 123, p_par = 99;

    double limit = 2000;

    int app, orng, apr, pear;
    int tom, on, cuc;
    int gar, par;

    std::cout << "Введите количество (литры)\n";

    std::cout << "\nФруктовые\n";
    std::cout << "Яблочный: ";
    std::cin >> app;
    std::cout << "Апельсиновый: ";
    std::cin >> orng;
    std::cout << "Абрикосовый: ";
    std::cin >> apr;
    std::cout << "Грушевый: ";
    std::cin >> pear;

    std::cout << "\nОвощные\n";
    std::cout << "Томатный: ";
    std::cin >> tom;
    std::cout << "Луковый: ";
    std::cin >> on;
    std::cout << "Огуречный: ";
    std::cin >> cuc;

    std::cout << "\nЧаи\n";
    std::cout << "Чесночный: ";
    std::cin >> gar;
    std::cout << "Петрушевый: ";
    std::cin >> par;

    double sum = 0;
    double disc = 0;

    sum += app * p_app;
    sum += orng * p_or;
    sum += apr * p_apr;
    sum += pear * p_pe;

    sum += tom * p_tom;
    sum += cuc * p_cuc;
    sum += gar * p_gar;

    double par_sum = par * p_par;
    if (par >= 3) {
        double d = par_sum * 0.05;
        par_sum -= d;
        disc += d;
    }
    sum += par_sum;

    if (sum > limit) {
        double d = sum * 0.13;
        sum -= d;
        disc += d;
    }

    std::cout << "\n-----------------\n";
    std::cout << "Скидки: " << disc << " руб.\n";
    std::cout << "К оплате: " << sum << " руб.\n";
    std::cout << "-----------------\n";
}
