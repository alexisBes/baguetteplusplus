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
				if (temp != " " && !temp.empty())
					spliteString.push_back(temp);
				temp.clear();
			}
		}
	}
	spliteString.push_back(temp);
}

std::string cleanString(std::string str)
{
	std::stringstream ss = std::stringstream(str);
	char c;
	std::string newString;
	while (ss.get(c))
	{
		if (c != '\t' && c != '\r' && c != ' ')
			newString.append(c, 1);
	}
	return std::string();
}
