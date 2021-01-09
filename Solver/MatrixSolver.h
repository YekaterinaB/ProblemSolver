//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATRIXSOLVER_H
#define PROBLEMSOLVER_MATRIXSOLVER_H


#include "Solver.h"
#include "../Maze/MatrixMaze.h"
#include "../Searcher/Searcher.h"
#include "../Maze/State.h"
#include "../Logger/Logger.h"


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
            solution = searcher->search(problem);
            Logger::getInstance()->log("Found a solution using MatrixSolver...\n" + solution);
        } catch (const string &e) {
            Logger::getInstance()->log("An error has occurred\n" + e);
            solution = e;
        } catch (...) {
            Logger::getInstance()->log("An error has occurred...");
            solution = "An error has occurred.";
        }

        return solution + "\n";
    }

    virtual ~MatrixSolver() {
        delete searcher;
    }

};

#endif //PROBLEMSOLVER_MATRIXSOLVER_H
