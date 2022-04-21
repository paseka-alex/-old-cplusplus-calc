#pragma once
#include <map>
#include <stack>
#include <algorithm>
#include <iostream>

class PolishNotationConverter
{
public:
	void convert(std::string& expression)
	{
		cleanFromSpaces(expression);
		//check(expression);
		//std::cout << expression << std::endl;
		formateExpressionToConvent(expression);
		convertExpression(expression);
		addRestToResult();
		expression = convented;
	}

	PolishNotationConverter()
	{
		//��������� ����� ����������� ��������
		prioritets.insert(std::make_pair('*', 3));
		prioritets.insert(std::make_pair('/', 3));
		prioritets.insert(std::make_pair('+', 2));
		prioritets.insert(std::make_pair('-', 2));
		prioritets.insert(std::make_pair('(', 1));
	}
private:
	std::string convented;
	std::stack<char> stack;
	std::string::size_type ind;              
	std::map<char, size_t> prioritets; // ����� ����� ��������

	void cleanFromSpaces(std::string& expr)
	{
		while ((ind = expr.find(' ')) != std::string::npos) // �������� �������� �� ������� ������
		{
			expr.erase(ind, 1);
		}
	}
	void formateExpressionToConvent(std::string& expr)
	{
		for (int i = 0; i < expr.size(); ++i) // ���� ������������� �����
		{
			if ((expr[i] == '+' || expr[i] == '-') && (0 == i || (!isalnum(expr[i - 1]) && expr[i - 1] != '.' && expr[i - 1] != ')')))
			{
				auto it = std::find_if(expr.begin() + i + 1, expr.end(), [](char const c) {return !isalnum(c); });
				expr.insert(it, ')');  // ������ ������ ��� ������������ ����������� � ���������
				expr.insert(i, "(0");  //������ -� ������ 0 - � ��� ��������� ����� 
			}
		}
	}
	void convertExpression(std::string& expr)
	{
		for (auto c : expr) // ���������� �������������� ������ � ���
		{
			if (isdigit(c))
			{
				convented += c;
			}
			else if (!isalnum(c) && ('.' != c))
			{
				if (')' == c)
				{
					while (stack.top() != '(')
					{
						convented += stack.top();
						stack.pop();
					}
					stack.pop();
				}
				else if ('(' == c)
				{
					stack.push(c);
				}
				else if (stack.empty() || (prioritets[stack.top()] < prioritets[c]))
				{
					stack.push(c);
				}
				else
				{
					do
					{
						convented += stack.top();
						stack.pop();
					} while (!(stack.empty() || (prioritets[stack.top()] < prioritets[c])));
					stack.push(c);
				}
			}
		}
	}
	/*void check(std::string& expr)
	{
		string temp;
		for (auto i : expr)
		{		
			if (i == '+' || i == '-' || i == '*' || i == '/' || i == ')')
			{
				temp += ".";
			}
			temp += i;
		}
		temp += ".";
		expr = temp;
	}*/
	void addRestToResult()
	{
		while (!stack.empty())// ������� �� ����� ����������� � �������. ������
		{
			convented += stack.top();
			stack.pop();
		}
	}
};

