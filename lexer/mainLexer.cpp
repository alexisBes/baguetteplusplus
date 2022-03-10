#include "mainLexer.h"
#include <fstream>
#include "../tools/stringTool.h"

bool sortDocument(std::ifstream& f) {
	std::ofstream logFile;//THIS is temporary
	logFile.open("logLexer.txt");
	while (f)
	{
		std::string line;
		getline(f, line);
		std::vector<std::string> splitLine;
		splitString(splitLine, line, ' ');
		if (!splitLine.empty())
		{
			if (splitLine[0] == "POUR")
			{
				if(splitLine[1] == "CHAQUE")
					logFile << "boucle pour chaque detecte\n";
				else
					logFile << "boucle pour detecte\n";
			}
			if (splitLine[0] == "TANT")
				logFile << "boucle tant que detecte\n";
			if(splitLine[0] == "SI")
				logFile << "condition si detecte\n";
			if(splitLine[0] == "ANALYSER")
				logFile << "condition switch detecte\n";
		}

	}
	logFile.close();
	return true;
}