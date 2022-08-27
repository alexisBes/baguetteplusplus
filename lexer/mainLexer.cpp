#include "mainLexer.h"
#include <fstream>
#include "../tools/stringTool.h"

bool sortDocument(std::ifstream& f) {
	std::ofstream logFile;//THIS is temporary
	logFile.open("logLexer.txt");
	while (f)
	{
		std::string line;
		getline(f,line);
		std::vector<std::string> splitLine;
		splitString(splitLine,line,' ');
		int type = 0;
		bool isLoop = false, isFound = false;
		std::string keyword = splitLine[0];
		if (!splitLine.empty())
		{
			while (type < 3)
			{
				if (loopGrammar[type][0] == keyword)
				{
					isLoop = isFound = true;
					break;
				}
				type++;
			}
			if (!isLoop)
			{
				type = 0;
				while (type < 2)
				{
					if (conditionGrammar[type][0] == keyword)
					{
						isFound = true;
						break;
					}
					type++;
				}
			}
		}
		if (isFound)logFile << "keyword "<< keyword <<" found\n";
	}
	logFile.close();
	return true;
}