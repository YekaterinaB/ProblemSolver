
#ifndef PROBLEMSOLVER_MENU_H
#define PROBLEMSOLVER_MENU_H
#include "../Factory/SolverFactory.h"

class Menu {

public:
    virtual void showMenu() = 0;

    virtual ~Menu() = default;
};
#endif //PROBLEMSOLVER_MENU_H
