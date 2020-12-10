
#ifndef PROBLEMSOLVER_COMMANDPROMPTPARSER_H
#define PROBLEMSOLVER_COMMANDPROMPTPARSER_H
#include "Parser.h"
#include <iostream>

using namespace std;

class CommandPromptParser : public Parser {
public:
    virtual string parse();
    virtual ~CommandPromptParser()= default;
};

#endif //PROBLEMSOLVER_COMMANDPROMPTPARSER_H
