#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "Configuration/Configuration.h"

int main() {
    auto config = Configuration::readJSONFile("config.json");
    vector<pair<string, vector<string>>> solvers = config.first.second;
    vector<string> parsers = config.second.second;
    Menu *m = new CommandPromptMenu(solvers, parser);
    bool solveAgain = true;
    while (solveAgain) {
        solveAgain = m->solveProblem();
    }

    delete m;
    return 0;
}

