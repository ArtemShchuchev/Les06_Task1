#include <cmath>    // математика
#include <iostream> // консоль - cout
#include <conio.h>  // _kbhit()

#include "MyFunc.h"

double add(double num1, double num2)
{
	return num1 + num2;
}

double subtract(double num1, double num2)
{
	return num1 - num2;
}

double multiply(double num1, double num2)
{
	return num1 * num2;
}

double divide(double num1, double num2)
{
	return num1 / num2;
}

double exponentiation(double num1, double num2)
{
	return std::pow(num1, num2);
}

/*
    будет запрашивать у пользователя ввод данных
    пока не будут введены верные данные.
    В случае успеха, вернет double.
    При ошибке ввода, сбросит и очистит cin
    и снова попросит ввести данные
*/
double userInput(const std::string& userText)
{
    double uData = 0;
    bool err = true;

    do
    {
        std::cout << userText; std::cin >> uData;

        if (err = std::cin.fail()) std::cin.clear(); // ошибка ввода
        int ch; // поиск и очистка лишних введенных символов
        while ((ch = std::cin.get()) != '\n' && ch != EOF);
    } while (err);

    return uData;
}

// ждет ввода комманды, возвращает введенную команду
Operand operInput()
{
    using namespace std;

    Operand op = Operand::NOT;
    cout << "Введите команду ('+', '-', '*', '/', '^' или 'ESC'): ";
    do
    {
        if (_kbhit())  // если клавиша была нажата
        {
            char sym = _getch();
            //std::cout << "-= " << sym << " - " << static_cast<int>(sym) << " =-\n";
            switch (sym)
            {
            case 42:    // '*'
                op = Operand::MUL;
                std::cout << "Умножение";
                break;

            case 43:    // '+'
                op = Operand::PLUS;
                std::cout << "Сложение";
                break;

            case 45:    // '-'
                op = Operand::MINUS;
                std::cout << "Вычитание";
                break;

            case 47:    // '/'
                op = Operand::DIV;
                std::cout << "Деление";
                break;

            case 94:    // "^"
                op = Operand::POW;
                std::cout << "Степень";
                break;

            //case 13:    // Enter
            //case 61:    // =
            //case 88:    // X
            //case 120:   // x
            //case 215:   // Ч
            //case 247:   // ч

            case 27:    // ESC
                op = Operand::EXIT;
                break;

            default:
                op = Operand::NOT;
                break;
            }
        }
    } while (op == Operand::NOT);

    std::cout << std::endl;
    return op;
}