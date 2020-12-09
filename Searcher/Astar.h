//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_ASTAR_H
#define PROBLEMSOLVER_ASTAR_H

#include <map>
#include <set>
#include <limits>
#include "Searcher.h"
#include "CustomPriorityQueue.h"
#include "Searcher.h"
#include "../Maze/State.h"
#include "../Maze/MatrixMaze.h"

class Astar : public Searcher<vector<State *>, MatrixMaze> {
private:
    int numberOfNodesEvaluated = 0;

    static State *findState(const vector<State *> &allStates, const State &stateToFind);

public:
    virtual vector<State *> search(MatrixMaze &searchable);

    int getNumberOfNodesEvaluated();

    vector<State *> backTrace(State *goal);

    vector<State *> backTraceAndUpdateCost(State *s, MatrixMaze &searchable);

};


#endif //PROBLEMSOLVER_ASTAR_H
