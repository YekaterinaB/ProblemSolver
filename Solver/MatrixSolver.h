//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATRIXSOLVER_H
#define PROBLEMSOLVER_MATRIXSOLVER_H


#include "Solver.h"
#include "../Maze/MatrixMaze.h"
#include "../Searcher/Searcher.h"
#include "../Maze/State.h"


class MatrixSolver : public Solver<string, vector<State * >,MatrixMaze> {

private:
    MatrixMaze searchable{};
    void createProblemFromString(const string &str);
public:
    explicit MatrixSolver(Searcher<vector<State *>,MatrixMaze> *s) {
        searcher = s;
    }

   // initialize matrixMaze

    virtual string toString(const vector<State *> &backtrace);

    virtual vector<State *> solve(const string &problem){
        createProblemFromString(problem);
        vector<State *> backtrace = searcher->search(searchable);
        return backtrace;
    }

    virtual ~MatrixSolver() {
        delete searcher;
    }

};

#endif //PROBLEMSOLVER_MATRIXSOLVER_H
