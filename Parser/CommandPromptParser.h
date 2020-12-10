
#ifndef PROBLEMSOLVER_COMMANDPROMPTPARSER_H
#define PROBLEMSOLVER_COMMANDPROMPTPARSER_H
#include "Parser.h"
#include <iostream>

using namespace std;

class CommandPromptParser : public Parser {
public:
    virtual void parse();
};

#endif //PROBLEMSOLVER_COMMANDPROMPTPARSER_H
