#include <iostream>
#include "CommandPromptMenu.h"
#include "../Logger/Logger.h"

bool CommandPromptMenu::solveProblem() {
    Logger::getInstance()->log("Choosing problem at command prompt menu...");
    setSolver();
    setParser();
    string problem = this->currentParser->parse();
    string solution = this->currentSolver->solve(problem);

    cout << "The solution is:\n " + solution << endl;
    return doYouWantToSolveAgain();
}

bool CommandPromptMenu::doYouWantToSolveAgain() {
    int indexParser = 0;
    while (indexParser != 1 && indexParser != 2) {
        cout << "Do you want to solve another problem?" << endl;
        cout << "(1) Yes" << endl;
        cout << "(2) No" << endl;
        cin >> indexParser;
    }
    return indexParser == 1;
}


void CommandPromptMenu::setParser() {
    int parserIndex=0;
    while (!(parserIndex > 0 && parserIndex <= parsersMap.size())) {
        int i = 1;
        cout << "Choose a way to upload the problem:" << endl;
        for (auto &entry:parsersMap) {
            cout <<"("+ to_string(i) + ") " + entry.first << endl;
            i++;
        }
        cin >> parserIndex;
    }
    //find string to index
    int j=1;
    string parserStr;
    for(auto iter= parsersMap.begin();iter !=parsersMap.end(); iter++ ,j++){
        if(j == parserIndex)
        {
            parserStr = iter->first;
            break;
        }
    }
    currentParser = parsersMap[parserStr];
}

void CommandPromptMenu::setSolver() {
    int solverIndex=0;

    while (!(solverIndex > 0  && solverIndex <= solversMap.size())) {
        int i = 1;
        cout << "Choose a solver:" << endl;

        for (auto &entry:solversMap) {
            cout << to_string(i) + ". " + entry.first << endl;
            i++;
        }
        cin >> solverIndex;
    }
    //find solver string from index
    int j=1;
    vector<string> searchers;
    for(auto iter= solversMap.begin(); iter !=solversMap.end(); iter++ ,j++){
        if(j == solverIndex)
        {
            searchers = iter->second;
            break;
        }
    }
    string searcherStr=getSearcherFromUser(searchers);

    this->currentSolver = searcherMap[searcherStr];

}

string CommandPromptMenu::getSearcherFromUser(const vector<string> &searchers) {
    int searcherIndex=0;
    while (!(searcherIndex > 0 && searcherIndex <= searchers.size())) {
        cout << "Choose an algorithm to solve with:" << endl;
        for (int i = 0; i < searchers.size(); i++) {
            cout <<"(" +to_string(i + 1) + ") " + searchers[i] << endl;
        }
        cin >> searcherIndex;
    }
    string searcherStr=searchers[searcherIndex-1];
    return searcherStr;
}





