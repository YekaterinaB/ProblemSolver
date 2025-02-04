
#ifndef PROBLEMSOLVER_MENU_H
#define PROBLEMSOLVER_MENU_H

#include <unordered_map>
#include "../Factory/SolverFactory.h"
#include "../Factory/ParserFactory.h"

class Menu {
private:
    ParserFactory _parserFactory = ParserFactory();
    SolverFactory _solverFactory = SolverFactory();

    void initSolversMap(const vector<pair<string,vector<string>>> &s);
    void initParserMap(const vector<string> &p);

    void resetParserMap();
    void resetSolversMap();

protected:

    unordered_map<string,Solver *> _searcherMap;
    unordered_map<string,vector<string>> _solversMap;

    unordered_map<string,Parser *> _parsersMap;

    Solver * _currentSolver= nullptr;
    Parser * _currentParser=nullptr;

public:
    Menu(const vector<pair<string, vector<string>>> &s,const vector<string> &p);
    virtual void setSolver()=0;
    virtual void setParser()=0;
    virtual bool solveProblem() = 0;

    virtual ~Menu();
};

#endif //PROBLEMSOLVER_MENU_H
