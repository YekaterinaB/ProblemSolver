//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_MATRIXSEARCHER_H
#define PROBLEMSOLVER_MATRIXSEARCHER_H

#include "../Maze/MatrixMaze.h"
#include "../Maze/State.h"
#include "Searcher.h"
#define POINTS_REGEX "^\\d+,\\d+$"
class MatrixSearcher : public Searcher {
protected:

    MatrixMaze createProblemFromString(const string &str);

    State *findState(const vector<State *> &allStates, const State &stateToFind);

    vector<State *> backTrace(State *goal);

    string toString(const vector<State *> &backtrace,const MatrixMaze &matrixMaze);


public:
    MatrixSearcher(){
        _type="MatrixSearcher";
    }
    virtual string search(const string &matrixMazeStr) = 0;

    virtual ~MatrixSearcher() = default;

};

#endif //PROBLEMSOLVER_MATRIXSEARCHER_H
