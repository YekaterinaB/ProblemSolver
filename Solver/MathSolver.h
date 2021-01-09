//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATHSOLVER_H
#define PROBLEMSOLVER_MATHSOLVER_H

#include "Solver.h"
#include "../Expression/Expression.h"

class MathSolver : public Solver {
private:
    MathSearcher *searcher;
public:
    explicit MathSolver(MathSearcher *s) {
        searcher = s;
    }

    virtual string solve(const string &problem) {
        string mathExp = problem;
        string solution;
        try {
            solution = searcher->search(mathExp);
            Logger::getInstance()->log("Found a solution using MathSolver...\n" + solution);
        } catch (const string &e) {
            Logger::getInstance()->log("An error has occurred\n" + e);
            solution = e;
        } catch (...) {
            Logger::getInstance()->log("An error has occurred...");
            solution = "An error has accoured.";

        }
        return solution + "\n";
    }

    virtual ~MathSolver() {
        delete searcher;
    }
};

#endif //PROBLEMSOLVER_MATHSOLVER_H
