#ifndef PROBLEMSOLVER_PARSER_H
#define PROBLEMSOLVER_PARSER_H

#include <string>

class Parser {
public:
    Parser() = default;

    virtual std::string parse() = 0;

    virtual ~Parser() = default;
};

#endif //PROBLEMSOLVER_PARSER_H
