
#ifndef PROBLEMSOLVER_MENU_H
#define PROBLEMSOLVER_MENU_H
#include "../SolverFactory.h"

class Menu {
protected:
    SolverFactory problemFactory;
public:
    explicit Menu(const SolverFactory &problemFactory) {
        this->problemFactory = problemFactory;
    }

    virtual void showMenu() = 0;

    virtual ~Menu() = default;
};
#endif //PROBLEMSOLVER_MENU_H
