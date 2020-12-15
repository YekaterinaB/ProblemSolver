
#include <iomanip>
#include "MatrixSearcher.h"

State *MatrixSearcher::findState(const vector<State *> &allStates, const State &stateToFind) {
    for (auto s : allStates) {
        if (s->getDescription() == stateToFind.getDescription()) {
            return s;
        }
    }
    return nullptr;
}


vector<State *> MatrixSearcher::backTrace(State *goal) {
    vector<State *> backtrace;
    while (goal->getFather() != nullptr) {
        backtrace.insert(backtrace.begin(), goal);
        goal = (*goal).getFather();
    }
    backtrace.insert(backtrace.begin(), goal);// first node
    return backtrace;
}

