
#include "Menu.h"
Menu::Menu(const vector<pair<string, vector<string>>> &s, const vector<string> &p) {
    initSolversMap(s);
    initParserMap(p);
}

Menu::~Menu() {
    resetParserMap();
    resetSolversMap();
    currentSolver= nullptr;
    currentParser= nullptr;
}

void Menu::resetParserMap() {
    for(auto & entry : parsersMap ) {
        delete entry.second;
    }
    parsersMap.clear();
    currentParser= nullptr;
}

void Menu::resetSolversMap() {

    for(auto &searcherEntry : searcherMap ){
        delete searcherEntry.second;
    }
    searcherMap.clear();
    solversMap.clear();
    currentSolver=nullptr;
}



void Menu::initParserMap(const vector<string> &p) {

    for(auto &parser : p ) {
        parsersMap[parser]= parserFactory.getParser(parser);
    }

}

void Menu::initSolversMap(const vector<pair<string, vector<string>>> &s) {
    for(auto &pair : s ){
        string solver=pair.first;
        vector<string> searchers=pair.second;
        solversMap[solver]=searchers;
        for(auto &searcher : searchers){
            searcherMap[searcher] = solverFactory.getSolver(solver,searcher);
        }
    }
}








