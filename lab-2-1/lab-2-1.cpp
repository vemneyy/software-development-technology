#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Введите стороны a, b, c, d (построение фигуры будет идти также по вводу)" << endl;
    cout << "Для прекращения ввода нажмите Enter во время ввода любой из переменных" << endl;

    double a, b, c, d;
    string nameFigure;

    while (true) {
        try {
            cout << "сторона a = ";
            if (!(cin >> a) || a <= 0) {
                cout << "Стороны должны быть в фигуре положительны!" << endl;
                break;
            }

            cout << "сторона b = ";
            if (!(cin >> b) || b <= 0) {
                cout << "Стороны должны быть в фигуре положительны!" << endl;
                break;
            }

            cout << "сторона c = ";
            if (!(cin >> c) || c <= 0) {
                cout << "Стороны должны быть в фигуре положительны!" << endl;
                break;
            }

            cout << "сторона d = ";
            if (!(cin >> d) || d <= 0) {
                cout << "Стороны должны быть в фигуре положительны!" << endl;
            }

            if (abs(a - b) < c + d && abs(a - c) < b + d && abs(a - d) < b + c &&
                abs(b - c) < a + d && abs(b - d) < a + c && abs(c - d) < a + b) {

                if (a == b && b == c && c == d) {
                    nameFigure = "квадрат или ромб";
                }
                else if ((a == b && c == d) || (a == d && b == c)) {
                    nameFigure = "правильный четырёхугольник";
                }
                else if ((a == c && b == d) || (a == d && b == c)) {
                    nameFigure = "прямоугольник или параллелограмм";
                }
                else {
                    nameFigure = "трапеция или обыкновенный четырёхугольник";
                }
            }

            else {
                cout << "Данного четырёхугольника с заданными сторонами не существует" << endl;
                break;
            }

            cout << "Введённая фигура - " << nameFigure << endl;
        }

        catch (...) {
            cout << "Введена буква. Ожидалось число" << endl;
        }
    }

    return 0;
}
