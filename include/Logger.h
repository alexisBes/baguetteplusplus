#ifndef LOGGER_H
#define LOGGER_H

void erreur_MauvaisMotsCLE(const int ligne,const char *motcle);

void erreur_VariableExiste(const int ligne, const char* variable);

void erreur_MauvaisOperateur(const int ligne, const char* operateur);
#endif