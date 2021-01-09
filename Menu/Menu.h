
#ifndef PROBLEMSOLVER_MENU_H
#define PROBLEMSOLVER_MENU_H

#include "../Factory/SolverFactory.h"
#include "../Factory/ParserFactory.h"

class Menu {
protected:
    ParserFactory parserFactory = ParserFactory();
    SolverFactory solverFactory = SolverFactory();

    vector<pair<string, vector<string>>> solvers;
    vector<string> parsers;

public:
    Menu(vector<pair<string, vector<string>>> &s, vector<string> &p) {
        solvers = s;
        parsers = p;
    }

    virtual bool solveProblem() = 0;

    virtual ~Menu() = default;
};

#endif //PROBLEMSOLVER_MENU_H
