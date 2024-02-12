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
            std::cout << "������� ����� ��� " << vars_char[i] << ": ";
            std::string input;
            std::cin >> input;

            // �������� ������������ ����� ����� � ���������� ������������
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

                    // �������� ������� �� ���� ����� ����� ���������� y
                    if (i == 1 && vars[1] == 0) {
                        std::cout << "������: ������� �� ����! ����������, ������� ��������� �������� ��� y!" << std::endl;
                        validInput = false; // ������������� ���� � false, ����� ������ ���� ����� ��� y ��� ���
                    }

                    else if (i == 0 && vars[0] < 0) {
                        std::cout << "������: ������������� �������� ��� ���������� ������! ����������, ������� ��������������� �������� ��� x!" << std::endl;
                        validInput = false; // ������������� ���� � false, ����� ������ ���� ����� ��� y ��� ���
                    }

                    else if (vars[0] > std::numeric_limits<double>::max()) {
                        std::cerr << "������: ������������ ����������. ���������� ������ ������� ��������!" << std::endl;
                        validInput = false;
                    }

                    
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "������: ������������ ����. ������� ������ ����� � ������������ � ���� �������!" << std::endl;
                }
            }
            else {
                std::cout << "������������ ����. ������� ����� � ������������ � ���� �������!" << std::endl;
            }
        }
    }

    double denominator = 3 * vars[2] - (vars[0] * vars[1] / 5);

    // �������� ������� �� ���� ����� ����� ���� ��������
    if (denominator == 0) {
        std::cout << "������: ������� �� ����!" << std::endl;
        return 1;
    }

    double temp = pow(vars[0], 2) / denominator;

    // �������� ������������ ����������
    if (temp > std::numeric_limits<double>::max()) {
        std::cout << "������: ������������ ����������!" << std::endl;
        return 1;
    }

    double t = sqrt(vars[0]) * (1 + temp);

    // �������� �� ������������� � NaN
    if (!std::isfinite(t)) {
        if (std::isnan(t)) {
            std::cout << "������: ������������� ��������!" << std::endl;
        }
        else {
            std::cout << "������: �������������!" << std::endl;
        }
        return 1;
    }

    std::cout << "t = " << t << std::endl;

    return 0;
}
