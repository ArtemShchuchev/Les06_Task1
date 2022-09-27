#include <cmath>    // ����������
#include <iostream> // ������� - cout
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
    ����� ����������� � ������������ ���� ������
    ���� �� ����� ������� ������ ������.
    � ������ ������, ������ double.
    ��� ������ �����, ������� � ������� cin
    � ����� �������� ������ ������
*/
double userInput(const std::string& userText)
{
    double uData = 0;
    bool err = true;

    do
    {
        std::cout << userText; std::cin >> uData;

        if (err = std::cin.fail()) std::cin.clear(); // ������ �����
        int ch; // ����� � ������� ������ ��������� ��������
        while ((ch = std::cin.get()) != '\n' && ch != EOF);
    } while (err);

    return uData;
}

// ���� ����� ��������, ���������� ��������� �������
Operand operInput()
{
    using namespace std;

    Operand op = Operand::NOT;
    cout << "������� ������� ('+', '-', '*', '/', '^' ��� 'ESC'): ";
    do
    {
        if (_kbhit())  // ���� ������� ���� ������
        {
            char sym = _getch();
            //std::cout << "-= " << sym << " - " << static_cast<int>(sym) << " =-\n";
            switch (sym)
            {
            case 42:    // '*'
                op = Operand::MUL;
                std::cout << "���������";
                break;

            case 43:    // '+'
                op = Operand::PLUS;
                std::cout << "��������";
                break;

            case 45:    // '-'
                op = Operand::MINUS;
                std::cout << "���������";
                break;

            case 47:    // '/'
                op = Operand::DIV;
                std::cout << "�������";
                break;

            case 94:    // "^"
                op = Operand::POW;
                std::cout << "�������";
                break;

            //case 13:    // Enter
            //case 61:    // =
            //case 88:    // X
            //case 120:   // x
            //case 215:   // �
            //case 247:   // �

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