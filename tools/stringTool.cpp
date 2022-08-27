#include "stringTool.h"
#include <sstream>

void splitString(std::vector<std::string>& spliteString, std::string s, const char c)
{
	std::stringstream ss = std::stringstream(s);
	std::string temp;
	char curentChar;
	while (ss.get(curentChar))
	{
		if (curentChar != '\t')//ignore tabulation
		{
			if (c != curentChar)
				temp.push_back(curentChar);//not the easiest way
			else
			{
				spliteString.push_back(temp);
				temp.clear();
			}
		}
	}
}
