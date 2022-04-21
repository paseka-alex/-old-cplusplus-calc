#pragma once
#include <iostream>

#include "UI.h"
#include "Mathematics.h"
#include "StringValidifier.h"
#include "PolishNotationConverter.h"
#include <cstring>

class calculator
{
public: 
	void play()
	{
		while (true)
		{
			std::string math_str = ui.getInput();
			/*if (checkValidity.check(math_str) == false) 
			{ 
				break; //add an exeption 
			}*/
			polish_cv.convert(math_str);
			float res = math.count(math_str);
			ui.printOutput(res);
		}
	}
private:
	UI ui;
	Mathematics math;
	StringValidifier checkValidity;
	PolishNotationConverter polish_cv;
};

