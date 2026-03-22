#include <iostream>
#include <string>
#include <cctype>

// Функция делает каждое слово с заглавной буквы
std::string capitalizeWords(std::string str) {
    bool newWord = true;
    for (size_t i = 0; i < str.length(); i++) {
        if (isspace(str[i])) {
            newWord = true;
        }
        else {
            if (newWord) {
                str[i] = toupper(str[i]);
                newWord = false;
            }
            else {
                str[i] = tolower(str[i]);
            }
        }
    }
    return str;
}

// Функция поиска слова без учёта регистра
bool findWordIgnoreCase(std::string sentence, std::string word) 
    for (char& c : sentence) c = tolower(c);
    for (char& c : word) c = tolower(c);

    return sentence.find(word) != std::string::npos;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string sentence;
    std::cout << "Введите предложение: ";
    std::getline(std::cin, sentence);

    if (sentence.empty()) {
        std::cout << "Вы ничего не ввели!" << std::endl;
        return 0;
    }

    sentence = capitalizeWords(sentence);

    if (sentence.back() != '.') sentence += '.';

    std::cout << "Форматированное предложение: " << sentence << std::endl;

    std::string word;
    std::cout << "Введите слово для поиска: ";
    std::cin >> word;

    if (findWordIgnoreCase(sentence, word))
        std::cout << "Слово '" << word << "' найдено." << std::endl;
    else
        std::cout << "Слово '" << word << "' не найдено." << std::endl;

    return 0;
}