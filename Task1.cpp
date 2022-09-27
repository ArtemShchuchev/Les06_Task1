#include <iostream> // консоль - cout
#include "MyFunc.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");   // задаём русский текст
    system("chcp 1251");            // настраиваем кодировку консоли
    std::system("cls");

    std::cout << "Задача 1. Математические функции\n";
    std::cout << "--------------------------------\n";

    bool noExit = true;
    do
    {
        std::cout << std::endl;

        double answ = 0.0;
        std::string str;
        Operand op = operInput();
        if (op != Operand::EXIT)
        {
            double num1 = userInput("Введите первое число: ");
            double num2 = userInput("Введите второе число: ");

            switch (op)
            {
            case Operand::MUL:  // '*'
                answ = multiply(num1, num2);
                str = " умножить на ";
                break;

            case Operand::PLUS: // '+'
                answ = add(num1, num2);
                str = " плюс ";
                break;

            case Operand::MINUS:// '-'
                answ = subtract(num1, num2);
                str = " минус ";
                break;

            case Operand::DIV:  // '/'
                answ = divide(num1, num2);
                str = " разделить на ";
                break;

            case Operand::POW:  // "^"
                answ = exponentiation(num1, num2);
                str = " в степени ";
                break;

            default:
                break;
            }
            std::cout << num1 << str << num2 << " = " << answ << std::endl;
        }
        else noExit = false;
    } while(noExit);
    
    std::cout << "Пока..." << std::endl;
    return 0;
}
