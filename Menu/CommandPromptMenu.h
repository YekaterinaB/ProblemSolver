
#ifndef PROBLEMSOLVER_COMMANDPROMPTMENU_H
#define PROBLEMSOLVER_COMMANDPROMPTMENU_H

#include "Menu.h"

class CommandPromptMenu : public Menu {
private:
    void chooseSolverAndSearcher();
    Parser * chooseParser();


public:
    CommandPromptMenu(vector<pair<string, vector<string>>> &s, vector<string> &p) : Menu(s,p) {}

    virtual void showMenu();

    virtual ~CommandPromptMenu() = default;
};

#endif //PROBLEMSOLVER_COMMANDPROMPTMENU_H
