#include "Menu/Menu.h"
#include "Menu/CommandPromptMenu.h"
#include "Configuration/Configuration.h"

int main() {
//    vector<pair<string, vector<string>>> solvers = Configuration::readXmlFile("config.xml");
    vector<pair<string, vector<string>>> solvers = {pair<string, vector<string>>("MatrixSolver", {"A*"}),
                                                    pair<string, vector<string>>("MathSolver",
                                                                                 {"Reverse Polish Interpreter"})};
    vector<string> parser = {"CommandPromptParser"};
    Menu *m = new CommandPromptMenu(solvers, parser);
    bool solveAgain = true;
    while (solveAgain) {
        solveAgain = m->solveProblem();
    }

    delete m;
    return 0;
}

