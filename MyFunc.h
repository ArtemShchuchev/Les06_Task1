#pragma once

enum class Operand { NOT, PLUS, MINUS, MUL, DIV, POW, EXIT };

double add(double, double);				// сложение
double subtract(double, double);		// вычитание
double multiply(double, double);		// умножение
double divide(double, double);			// деление
double exponentiation(double, double);	// возведение в степень

double userInput(const std::string&);	// ввод пользовательских данных
Operand operInput();					// ввод пользователем операции
