#ifndef PROBLEMSOLVER_COMMANDPROMPTMENU_H
#define PROBLEMSOLVER_COMMANDPROMPTMENU_H

#include "Menu.h"

class CommandPromptMenu : public Menu {
private:
    bool doYouWantToSolveAgain();
    string getSearcherFromUser(const vector<string> &searchers);
public:
    CommandPromptMenu(vector<pair<string, vector<string>>> &s, vector<string> &p): Menu(s, p){}

    virtual void setSolver();

    virtual void setParser();

    virtual bool solveProblem();

    virtual ~CommandPromptMenu() = default;
};

#endif //PROBLEMSOLVER_COMMANDPROMPTMENU_H
