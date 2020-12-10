#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "Configuration/Configuration.h"

int main() {
//    vector<pair<string, vector<string>>> solvers = Configuration::readXmlFile("config.xml");
    vector<pair<string, vector<string>>> solvers = {pair<string, vector<string>>("MatrixSolver", {"A*"}),
                                                    pair<string, vector<string>>("MathSolver",
                                                                                 {"Reverse Polish Interpreter"})};
    vector<string> parser = {"FileParser", "CommandPromptParser"};
    Menu *m = new CommandPromptMenu(solvers, parser);
    m->showMenu();

    delete m;
    return 0;
}

