#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "Configuration/Configuration.h"

int main() {
    vector<pair<string, vector<string>>> solvers = Configuration::readXmlFile("config.xml");
    vector<string> parser={};
    Menu *m = new CommandPromptMenu(solvers,parser);
    m->showMenu();

    delete m;
    return 0;
}

