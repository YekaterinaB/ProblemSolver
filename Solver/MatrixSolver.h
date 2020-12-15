//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATRIXSOLVER_H
#define PROBLEMSOLVER_MATRIXSOLVER_H


#include "Solver.h"
#include "../Maze/MatrixMaze.h"
#include "../Searcher/Searcher.h"
#include "../Maze/State.h"


class MatrixSolver : public Solver {
private:
    MatrixSearcher *searcher;
public:
    explicit MatrixSolver(MatrixSearcher *s) {
        searcher = s;
    }

    virtual string solve(const string &problem) {
        string solution;
        try {
            solution=searcher->search(problem);
        } catch (const std::exception &e) {
            solution = e.what();
        }

        return solution+"\n";
    }

    virtual ~MatrixSolver() {
        delete searcher;
    }

};

#endif //PROBLEMSOLVER_MATRIXSOLVER_H
