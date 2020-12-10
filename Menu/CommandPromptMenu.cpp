#include <iostream>
#include "CommandPromptMenu.h"

void CommandPromptMenu::showMenu() {
    chooseSolverAndSearcher();
    Parser * p= chooseParser();
    string problem= p->parse();
//    Solver * s = getSolverFromFactory();

    delete p;
//    delete s;

}

Parser * CommandPromptMenu::chooseParser() {
    cout << "Choose a way to upload the problem:" << endl;
    for (auto i = 0; i < parsers.size(); i++) {
        cout << "(" + to_string(i + 1) + ") " + parsers[i] << endl;
    }
    int indexParser = 0;
    cin >> indexParser;
    string parser = parsers[indexParser - 1];
    Parser * p =parserFactory.getParser(parser);
    return p;

}

void CommandPromptMenu::chooseSolverAndSearcher() {
    cout << "Choose a solver:" << endl;

    for (auto i = 0; i < solvers.size(); i++) {
        cout << "(" + to_string(i + 1) + ") " + solvers[i].first << endl;
    }
    int indexSolver = 0;
    cin >> indexSolver;
    solver = solvers[indexSolver - 1].first;
    cout << "Choose an algorithm to solve with:" << endl;

    for (auto i = 0; i < solvers[indexSolver - 1].second.size(); i++) {
        cout << "(" + to_string(i + 1) + ") " + solvers[indexSolver - 1].second[i] << endl;
    }
    int indexSearcher = 0;
    cin >> indexSearcher;
    searcher = solvers[indexSolver - 1].second[indexSearcher - 1];
}
