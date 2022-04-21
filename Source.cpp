#include<iostream>
#include<cmath>
#include<stack>
#include <vector>

using namespace std;
#include "calculator.h"

/*vector<string> trim(string postfixes)
{
	vector<string> res;
	string temp;
	int operand_counter = 0;
	for (auto i : postfixes)
	{
		if (isOperand(i))
		{
			operand_counter++;
			if (operand_counter > 2)
			{
				res.push_back(temp);
				temp.clear();
				operand_counter = 0;
			}
		}
		temp += i;
	}
	res.push_back(temp);
	return res;
}*/

int main() 
{
	calculator calc;
	calc.play();
}