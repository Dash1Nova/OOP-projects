#include "inputValid.h"
#include <iostream>

char inputLetter(const std::string& message) {
    std::string input;

    while (true) {
        try {
            std::cout << message;
            std::cin >> input;

            if (input.length() != 1)
                throw std::invalid_argument("Turi buti ivesta viena raide.");

            if (!std::isalpha(input[0]))
                throw std::invalid_argument("Leidziamos tik raides.");

            return input[0];
        }
        catch (const std::exception& e) {
            std::cout << "Klaida: " << e.what() << std::endl;
        }
    }
}

std::string inputWord(const std::string& message) {
    std::string text;

    while (true) {
        try {
            std::cout << message;
            std::cin >> text;

            if (text.empty())
                throw std::invalid_argument("Zodis negali buti tuscias.");

            for (char c: text) {
                if (!std::isalpha(c))
                    throw std::invalid_argument("Zodyje gali buti tik raides.");
            }

            return text;
        }
        catch (const std::exception& e) {
            std::cout << "Klaida: " << e.what() << std::endl;
        }
    }
}

int inputInt(const std::string& message, int min, int max) {
    std::string input;
    int number;

    while (true) {
        try {
            std::cout << message;
            std::cin >> input;

            size_t pos;
            number = std::stoi(input, &pos);

            if (pos != input.length())
                throw std::invalid_argument("Ivestis nera sveikasis skaicius.");

            if (number < min || number > max)
                throw std::out_of_range("Skaicius nepatenka i leidziamas ribas.");

            return number;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Klaida: ivestas skaicius uz leistinu ribu.\n";
        }
    }
}

double inputR(const std::string& message, double min, double max) {
    std::string input;
    double number;

    while (true) {
        try {
            std::cout << message;
            std::cin >> input;

            size_t pos;
            number = std::stod(input, &pos);

            if (pos != input.length())
                throw std::invalid_argument("Ivestis nera realusis skaicius.");

            if (number < min || number > max)
                throw std::out_of_range("Skaicius nepatenka i leidziamas ribas.");

            return number;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Klaida: reikia ivesti realuji skaiciu.\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Klaida: ivestas skaicius uz leistinu ribu.\n";
        }
    }
}