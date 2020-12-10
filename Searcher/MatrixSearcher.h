//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_MATRIXSEARCHER_H
#define PROBLEMSOLVER_MATRIXSEARCHER_H

#include "../Maze/MatrixMaze.h"
#include "../Maze/State.h"
#include "Searcher.h"

class MatrixSearcher : public Searcher<vector<State *>, MatrixMaze> {
protected:
    int numberOfNodesEvaluated = 0;

    State *findState(const vector<State *> &allStates, const State &stateToFind);

public:
    virtual vector<State *> search(MatrixMaze &searchable) = 0;

    int getNumberOfNodesEvaluated();

    vector<State *> backTrace(State *goal);

    vector<State *> backTraceAndUpdateCost(State *s, MatrixMaze &searchable);
};

#endif //PROBLEMSOLVER_MATRIXSEARCHER_H
