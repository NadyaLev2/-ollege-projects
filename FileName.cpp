#include <iostream>
#include <stdexcept>
#include <string>

class Proportion {
public:
    static double solveProportion(const std::string& x, double a, double b, double c, double d) {
        if (x == "a") {
            if (b != 0 && c != 0 && d != 0) {
                return (b * c) / d;
            }
            else {
                throw std::invalid_argument("Невозможно вычислить a: убедитесь, что b, c, d не равны 0");
            }
        }
        else if (x == "b") {
            if (a != 0 && c != 0 && d != 0) {
                return (a * d) / c;
            }
            else {
                throw std::invalid_argument("Невозможно вычислить b: убедитесь, что a, c, d не равны 0");
            }
        }
        else if (x == "c") {
            if (a != 0 && b != 0 && d != 0) {
                return (a * d) / b;
            }
            else {
                throw std::invalid_argument("Невозможно вычислить c: убедитесь, что a, b, d не равны 0");
            }
        }
        else if (x == "d") {
            if (a != 0 && b != 0 && c != 0) {
                return (b * c) / a;
            }
            else {
                throw std::invalid_argument("Невозможно вычислить d: убедитесь, что a, b, c не равны 0");
            }
        }
        else {
            //Проверка пропорции
            if (a * d == b * c) {
                std::cout << "Пропорция выполнена, все числа заданы\n";
                return 0;
            }
            else {
                throw std::invalid_argument("Пропорция не выполнена");
            }
        }
        return 0;
    }

    // Нахождение числа по проценту
    static double percentageProportion(double e, double f) {
        return (e * f) / 100;
    }

    // Расчет коэффициента масштабирования между исходным и новым размером
    static double scaleFactor(double g, double h) {
        if (g == 0) {
            throw std::invalid_argument("Исходный размер не может быть равен нулю");
        }
        return h / g;
    }

    // Применение масштаба к значению
    static double applyScale(double i, double scale) {
        return i * scale;
    }
};

int main() {
    setlocale(0, "");

    // Решение пропорции
    std::string x; // переменная, какую ищем
    double a, b, c, d;

    std::cout << "Программа решает пропорции\n";
    std::cout << "Введите переменную, которую нужно найти (a, b, c, d): ";
    std::cin >> x;

    std::cout << "Введите значение a = ";
    std::cin >> a;
    std::cout << "Введите значение b = ";
    std::cin >> b;
    std::cout << "Введите значение c = ";
    std::cin >> c;
    std::cout << "Введите значение d = ";
    std::cin >> d;

    double result = Proportion::solveProportion(x, a, b, c, d);
    std::cout << "Решение пропорции " << x << " = " << result << std::endl << std::endl;

    // Нахождение % от числа
    double e, f;
    std::cout << "Программа находит процент от числа\n";
    std::cout << "Введите число = ";
    std::cin >> e;
    std::cout << "Введите процент = ";
    std::cin >> f;
    double percent = Proportion::percentageProportion(e, f);
    std::cout << f << "% от " << e << " = " << percent << std::endl << std::endl;

    // Расчет коэффициента масштабирования
    double g, h;
    std::cout << "Программа рассчитывает коэффициент масштабирования\n";
    std::cout << "Введите значение a = ";
    std::cin >> g;
    std::cout << "Введите значение b = ";
    std::cin >> h;
    double scale = Proportion::scaleFactor(g, h);
    std::cout << "Коэффициент масштабирования: " << scale << std::endl << std::endl;

    // Применение масштаба
    double i;
    std::cout << "Программа изменяет масштаб\n";
    std::cout << "Введите значение для масштабирования = ";
    std::cin >> i;
    double scaled_value = Proportion::applyScale(i, scale);
    std::cout << "Значение после масштабирования: " << scaled_value << std::endl << std::endl;

    return 0;
}