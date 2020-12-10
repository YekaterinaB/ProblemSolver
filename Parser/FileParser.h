
#ifndef PROBLEMSOLVER_FILEPARSER_H
#define PROBLEMSOLVER_FILEPARSER_H

#include "Parser.h"
#include <string>

using namespace std;

class FileParser : public Parser {
private:
    string fileName;

    void parseFile();

public:
    virtual void parse();
};
#endif //PROBLEMSOLVER_FILEPARSER_H
