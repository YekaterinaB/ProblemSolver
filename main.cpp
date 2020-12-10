#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include creating-configuration
#include "SolverFactory.h"
#include "Configuration/Configuration.h"

int main() {
  // Configuration::readXmlFile("config.xml");
    Menu *m = new CommandPromptMenu();
    m->showMenu();

    delete m;
    return 0;
}

