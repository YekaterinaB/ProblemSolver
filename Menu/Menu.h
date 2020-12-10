
#ifndef PROBLEMSOLVER_MENU_H
#define PROBLEMSOLVER_MENU_H

#include "../Factory/SolverFactory.h"
#include "../Factory/ParserFactory.h"

class Menu {
protected:
    ParserFactory parserFactory=ParserFactory();
    vector<pair<string, vector<string>>> solvers;
    vector<string> parsers;
    string solver="";
    string searcher="";
    string parser="";
public:
    Menu(vector<pair<string, vector<string>>> &s, vector<string> &p) {
        solvers = s;
        parsers = p;
    }

    virtual void showMenu() = 0;

    virtual ~Menu() = default;
};

#endif //PROBLEMSOLVER_MENU_H
