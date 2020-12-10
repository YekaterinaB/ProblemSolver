
#include "MatrixSearcher.h"

State *MatrixSearcher::findState(const vector<State *> &allStates, const State &stateToFind) {
    for (auto s : allStates) {
        if (s->getDescription() == stateToFind.getDescription()) {
            return s;
        }
    }

    return nullptr;
}

int MatrixSearcher::getNumberOfNodesEvaluated() {
    return this->numberOfNodesEvaluated;
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

vector<State *> MatrixSearcher::backTraceAndUpdateCost(State *s, MatrixMaze &searchable) {
    vector<State *> route = backTrace(s);

    double cost = 0;
    for (auto it = route.begin(); it != route.end(); it++) {
        cost += searchable.getCostToGetToNode(*it);
        (*it)->setCost(cost);
    }
    return route;

}
