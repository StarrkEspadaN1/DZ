#include <iostream>

double ageDiscount(double price, int age) {
    // Скидка для молоды и пенсионеров
    if (age < 18) {
        return price * 0.8;
    }
    else if (age >= 60) {
        return price * 0.85;
    }
    return price; 
}

double bulkDiscount(double price, double totalPurchase) {
    // Скидка при сумме покупки > 1000
    if (totalPurchase > 1000) {
        return price * 0.9;
    }
    return price;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double price;
    int age;
    double totalPurchase;

    std::cout << "Введите цену товара: ";
    std::cin >> price;
    std::cout << "Введите возраст покупателя: ";
    std::cin >> age;
    std::cout << "Введите общую сумму покупки: ";
    std::cin >> totalPurchase;

    double priceAfterAgeDiscount = ageDiscount(price, age);
    double finalPrice = bulkDiscount(priceAfterAgeDiscount, totalPurchase);

    std::cout << "Цена после всех скидок: " << finalPrice << std::endl;

    return 0;
}