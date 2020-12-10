#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "Factory/SolverFactory.h"

int main() {
    Menu *m = new CommandPromptMenu();
    m->showMenu();

    delete m;
    return 0;
}

