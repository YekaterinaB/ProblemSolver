#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "Configuration/Configuration.h"
#include "Logger/Logger.h"


int main() {
    Logger::getInstance()->log("Starting program...");
    auto config = Configuration::readJSONFile("config.json");
    vector<pair<string, vector<string>>> solvers = config.first.second;
    vector<string> parsers = config.second.second;
    Menu *m = new CommandPromptMenu(solvers, parsers);
    bool solveAgain = true;
    while (solveAgain) {
        solveAgain = m->solveProblem();
    }

    delete m;
    Logger::resetInstance();
    return 0;
}

