#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "Configuration/Configuration.h"

int main() {
    auto config = Configuration::readJSONFile("config.json");
    vector<pair<string, vector<string>>> solvers = config.first.second;
    vector<string> parsers = config.second.second;
//    vector<pair<string, vector<string>>> solvers = {pair<string, vector<string>>("MatrixSolver", {"A*"}),
//                                                    pair<string, vector<string>>("MathSolver",
//                                                                                 {"Reverse Polish Interpreter"})};
//    vector<string> parser = {"FileParser", "CommandPromptParser"};
//    Menu *m = new CommandPromptMenu(solvers, parser);
//    m->showMenu();
//
//    delete m;
    return 0;
}

