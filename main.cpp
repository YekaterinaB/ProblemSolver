#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "SolverFactory.h"

int main() {
    SolverFactory solverFactory = SolverFactory();
    Menu *m = new CommandPromptMenu(solverFactory);
    m->showMenu();

    delete m;
    return 0;
}