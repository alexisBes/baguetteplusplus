#pragma once
#include <string>
#include <vector>

static std::string loopGrammar[3][6] = {
	{"POUR","DE","A","PAS","FAIRE","FPOUR"},
	{"TANT QUE","FAIRE","FTANTQUE","","",""},
	{"POUR CHAQUE","DANS","ALORS","FTANTQUE","",""}
};

static std::string conditionGrammar[2][4] = {
	{"SI","ALORS","SINON","FSI"},
	{""}//TODO add switch keyword here
};

bool sortDocument(std::ifstream& f);