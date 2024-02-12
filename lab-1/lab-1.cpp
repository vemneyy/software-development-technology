#include <iostream>
#include <array>
#include <string>
#include <cmath>
#include <limits>
#include <cctype>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Russian");

    double x = 0.0, y = 0.0, z = 0.0;
    std::array<char, 3> vars_char{ 'x', 'y', 'z' };
    std::array<double, 3> vars{ x, y, z };

    bool validInput = false;

    for (int i = 0; i < 3; i++) {
        bool validInput = false;
        while (!validInput) {
            std::cout << "Введите число для " << vars_char[i] << ": ";
            std::string input;
            std::cin >> input;

            // Проверка корректности ввода числа с десятичным разделителем
            bool hasDecimal = false;
            bool isValid = std::all_of(input.begin(), input.end(), [&](char c) {
                if (std::isdigit(c)) {
                    return true;
                }

                else if (c == ',' || c == '-' && !hasDecimal) {
                    hasDecimal = true;
                    return true;
                }

                return false;
            });

            if (isValid) {
                try {
                    vars[i] = std::stod(input);
                    validInput = true;

                    // Проверка деления на ноль после ввода переменной y
                    if (i == 1 && vars[1] == 0) {
                        std::cout << "Ошибка: деление на ноль! Пожалуйста, введите ненулевое значение для y!" << std::endl;
                        validInput = false; // устанавливаем флаг в false, чтобы пройти цикл ввода для y еще раз
                    }

                    else if (i == 0 && vars[0] < 0) {
                        std::cout << "Ошибка: отрицательное значение под квадратным корнем! Пожалуйста, введите неотрицательное значение для x!" << std::endl;
                        validInput = false; // устанавливаем флаг в false, чтобы пройти цикл ввода для y еще раз
                    }

                    else if (vars[0] > std::numeric_limits<double>::max()) {
                        std::cerr << "Ошибка: переполнение переменной. Попробуйте ввести меньшее значение!" << std::endl;
                        validInput = false;
                    }

                    
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Ошибка: некорректный ввод. Вводите только числа с разделителем в виде запятой!" << std::endl;
                }
            }
            else {
                std::cout << "Некорректный ввод. Введите число с разделителем в виде запятой!" << std::endl;
            }
        }
    }

    double denominator = 3 * vars[2] - (vars[0] * vars[1] / 5);

    // Проверка деления на ноль после ввода всех значений
    if (denominator == 0) {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 1;
    }

    double temp = pow(vars[0], 2) / denominator;

    // Проверка переполнения переменной
    if (temp > std::numeric_limits<double>::max()) {
        std::cout << "Ошибка: переполнение переменной!" << std::endl;
        return 1;
    }

    double t = sqrt(vars[0]) * (1 + temp);

    // Проверка на бесконечность и NaN
    if (!std::isfinite(t)) {
        if (std::isnan(t)) {
            std::cout << "Ошибка: неопределённое значение!" << std::endl;
        }
        else {
            std::cout << "Ошибка: бесконечность!" << std::endl;
        }
        return 1;
    }

    std::cout << "t = " << t << std::endl;

    return 0;
}
