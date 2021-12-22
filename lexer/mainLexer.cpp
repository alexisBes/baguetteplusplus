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
		if (!splitLine.empty() && splitLine[0] == loopGrammar[0][0])
			logFile << "boucle pour detecte\n";
	}
	logFile.close();
	return true;
}