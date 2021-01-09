#ifndef PROBLEMSOLVER_COMMANDPROMPTMENU_H
#define PROBLEMSOLVER_COMMANDPROMPTMENU_H

#include "Menu.h"

class CommandPromptMenu : public Menu {
private:
    Solver *chooseSolverAndSearcher();

    Parser *chooseParser();

    bool doYouWantToSolveAgain();

public:
    CommandPromptMenu(vector<pair<string, vector<string>>> &s, vector<string> &p) : Menu(s, p) {}

    virtual bool solveProblem();

    virtual ~CommandPromptMenu() = default;
};

#endif //PROBLEMSOLVER_COMMANDPROMPTMENU_H
