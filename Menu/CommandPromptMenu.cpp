#include <iostream>
#include "CommandPromptMenu.h"
#include "../Logger/Logger.h"

bool CommandPromptMenu::solveProblem() {
    Logger::getInstance()->log("Choosing problem at command prompt menu...");
    Solver *s = chooseSolverAndSearcher();
    Parser *p = chooseParser();
    string problem = p->parse();
    string solution = s->solve(problem);
    delete p;
    delete s;

    cout << "The solution is:\n " + solution << endl;
    return doYouWantToSolveAgain();
}

bool CommandPromptMenu::doYouWantToSolveAgain() {
    int indexParser = 0;
    cout << "Do you want to solve another problem?" << endl;
    cout << "(1) Yes" << endl;
    cout << "(2) No" << endl;
    cin >> indexParser;
    return indexParser == 1;
}

Parser *CommandPromptMenu::chooseParser() {
    cout << "Choose a way to upload the problem:" << endl;
    for (auto i = 0; i < parsers.size(); i++) {
        cout << "(" + to_string(i + 1) + ") " + parsers[i] << endl;
    }
    int indexParser = 0;
    cin >> indexParser;
    string parser = parsers[indexParser - 1];
    Parser *p = parserFactory.getParser(parser);
    return p;

}


Solver *CommandPromptMenu::chooseSolverAndSearcher() {
    cout << "Choose a solver:" << endl;

    for (auto i = 0; i < solvers.size(); i++) {
        cout << "(" + to_string(i + 1) + ") " + solvers[i].first << endl;
    }
    int indexSolver = 0;
    cin >> indexSolver;
    string solver = solvers[indexSolver - 1].first;
    cout << "Choose an algorithm to solve with:" << endl;

    for (auto i = 0; i < solvers[indexSolver - 1].second.size(); i++) {
        cout << "(" + to_string(i + 1) + ") " + solvers[indexSolver - 1].second[i] << endl;
    }
    int indexSearcher = 0;
    cin >> indexSearcher;
    string searcher = solvers[indexSolver - 1].second[indexSearcher - 1];
    Solver *s = solverFactory.getSolver(solver, searcher);
    return s;
}
