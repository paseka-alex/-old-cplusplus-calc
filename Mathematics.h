#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Mathematics
{
public:
	float count(std::string& expression) 
	{
		return countExpression(expression);
	}
private:
	stack<float> stk;

	float countExpression(std::string postfix)
	{
		//сначала в стек попадают операнды (второй иф). потом, когда программа находит оператор, она присваивает двум переменным значение операнд из стека и выплевывает их.
		//и с помощью функции операция просчитывает их значение.
		int second_operand, first_operand;
		int operand_counter = 0;

		for (string::iterator it = postfix.begin(); it != postfix.end(); it++)
		{
			//read elements and perform postfix evaluation
			if (isOperator(*it))
			{
				second_operand = stk.top();
				stk.pop();
				first_operand = stk.top();
				stk.pop();
				stk.push(operation(second_operand, first_operand, *it));
			}
			if (isOperand(*it))
			{
				stk.push(scanNum(*it));
			}
		}
		return stk.top();
	}
	float scanNum(const char ch)
	{
		int value = ch;
		return float(value - '0');//return float from character
	}
	bool isOperator(char ch)
	{
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
			return true;
		return false;
	}
	bool isOperand(char ch)
	{
		if (ch >= '0' && ch <= '9')
			return true;
		return false;
	}
	float operation(int second_operand, int first_operand, char op)
	{
		//Perform operation
		if (op == '+')
			return first_operand + second_operand;
		else if (op == '-')
			return first_operand - second_operand;
		else if (op == '*')
			return first_operand * second_operand;
		else if (op == '/')
			return first_operand / second_operand;
		else if (op == '^')
			return pow(first_operand, second_operand); //find first_operand^second_operand
		//else
			//return INT_MIN; //return negative infinity
	}
};

