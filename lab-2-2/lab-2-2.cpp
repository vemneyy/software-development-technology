#include <iostream>
#include <vector>
#include <algorithm> // Для max_element

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<double> arr1;
    vector<double> arr2;
    double number;

    // Заполнение массива arr1 вводом от пользователя
    cout << "Введите 10 чисел:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Введите число " << i + 1 << ": ";
        if (!(cin >> number)) {
            cout << "Введена не цифра. Программа прервана." << endl;
            return 1; // Выход из программы с кодом ошибки
        }
        arr1.push_back(number);
    }

    cout << "Введённый массив: ";
    for (double num: arr1) {
        cout << num << " ";
    }
    cout << endl;

    for (int i = 0; i < arr1.size() / 2 + arr1.size() % 2; ++i) {
        arr2.push_back(arr1[i] + arr1[arr1.size() - 1 - i]);
    }

    cout << "Полученный массив чисел, после сложения крайних: ";
    for (double num: arr2) {
        cout << num << " ";
    }
    cout << endl;

    // Нахождение наибольшего числа в массиве arr2
    double largestNumber = *max_element(arr2.begin(), arr2.end());

    cout << "Наибольшее число: " << largestNumber << endl;

    return 0;
}
