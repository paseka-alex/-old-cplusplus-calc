#pragma once
#include <iostream>
#include <string>

class UI
{
public:
	std::string getInput()
	{
		std::string inputed;
		std::getline(std::cin, inputed);
		return inputed;
	}
	void printOutput(float result) const
	{
		std::cout << result << std::endl;
	}
private:
};

