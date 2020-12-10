
#ifndef PROBLEMSOLVER_COMMANDPROMPTMENU_H
#define PROBLEMSOLVER_COMMANDPROMPTMENU_H
#include "Menu.h"

class CommandPromptMenu : public Menu {
public:
    virtual void showMenu();

    virtual ~CommandPromptMenu() = default;
};
#endif //PROBLEMSOLVER_COMMANDPROMPTMENU_H
