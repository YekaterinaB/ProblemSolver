
#include "Menu.h"

Menu::Menu(const vector<pair<string, vector<string>>> &s, const vector<string> &p) {
    initSolversMap(s);
    initParserMap(p);
}

Menu::~Menu() {
    resetParserMap();
    resetSolversMap();
    _currentSolver = nullptr;
    _currentParser = nullptr;
}

void Menu::resetParserMap() {
    for (auto &entry : _parsersMap) {
        delete entry.second;
    }
    _parsersMap.clear();
    _currentParser = nullptr;
}

void Menu::resetSolversMap() {

    for (auto &searcherEntry : _searcherMap) {
        delete searcherEntry.second;
    }
    _searcherMap.clear();
    _solversMap.clear();
    _currentSolver = nullptr;
}


void Menu::initParserMap(const vector<string> &p) {

    for (auto &parser : p) {
        _parsersMap[parser] = _parserFactory.getParser(parser);
    }

}

void Menu::initSolversMap(const vector<pair<string, vector<string>>> &s) {
    for (auto &pair : s) {
        string solver = pair.first;
        vector<string> searchers = pair.second;
        _solversMap[solver] = searchers;
        for (auto &searcher : searchers) {
            _searcherMap[solver + "_" + searcher] = _solverFactory.getSolver(solver, searcher);
        }
    }
}

