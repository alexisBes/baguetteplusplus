#include "mainLexer.h"
#include <stringTool.h>
#include "type.h"

std::vector<VARIABLE> allVariable;

bool findInVariable(std::string potentialVariable);

bool sortDocument(std::ifstream& input, DocContext *output) {
	std::ofstream logFile;//THIS is temporary
	logFile.open("logLexer.log");
	while (input)
	{
		std::string line;
		getline(input, line);
		std::vector<std::string> splitLine;
		splitString(splitLine, line, ' ');
		if (!splitLine.empty())
		{
			if (splitLine[0] == "POUR")
			{
				if (splitLine[1] == "CHAQUE")
					logFile << "boucle pour chaque detecte\n";
				else
					logFile << "boucle pour detecte\n";
			}
			if (splitLine[0] == "TANT" && splitLine[1] == "QUE")
				logFile << "boucle tant que detecte\n";
			if (splitLine[0] == "SI")
				logFile << "condition si detecte\n";
			if (splitLine[0] == "ANALYSER")
				logFile << "condition switch detecte\n";
			if (splitLine.size() > 1 && splitLine[1] == "EST")
			{
				VARIABLE v(splitLine[0], splitLine[3]);
				allVariable.push_back(v);
				logFile << "variable detecte " + v.name + " de type " + splitLine[3] + "\n";
			}
			if (splitLine[0] == "BLOC")
				logFile << "block detecte\n";
			if (splitLine[0] == "ECRIRE")
				logFile << "ecrire detecte\n";
		}
	}
	logFile.close();
	return true;
}

bool findInVariable(std::string potentialVariable)
{
	size_t sizeVariable = allVariable.size();
	for (size_t i = 0; i < sizeVariable; i++)
	{
		if (allVariable[i].name == potentialVariable)
		{
			return true;
		}
	}
	return false;
}
