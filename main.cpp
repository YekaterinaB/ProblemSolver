#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "SolverFactory.h"
#include "Configuration/Configuration.h"

int main() {
    Configuration::readXmlFile("config.xml");
//    SolverFactory solverFactory = SolverFactory();
//    Menu *m = new CommandPromptMenu(solverFactory);
//    m->showMenu();

//    delete m;
    return 0;
}

