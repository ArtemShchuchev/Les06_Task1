#pragma once

enum class Operand { NOT, PLUS, MINUS, MUL, DIV, POW, EXIT };

double add(double, double);				// ��������
double subtract(double, double);		// ���������
double multiply(double, double);		// ���������
double divide(double, double);			// �������
double exponentiation(double, double);	// ���������� � �������

double userInput(const std::string&);	// ���� ���������������� ������
Operand operInput();					// ���� ������������� ��������
