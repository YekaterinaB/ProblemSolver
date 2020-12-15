//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATHSOLVER_H
#define PROBLEMSOLVER_MATHSOLVER_H

#include "Solver.h"
#include "../Expression/Expression.h"

class MathSolver : public Solver {
private:
    MathSearcher * searcher;
public:
    explicit MathSolver(MathSearcher *s) {
        searcher = s;
    }

    virtual string solve(const string &problem) {
        string mathExp = problem;
        string solution;
        try {
            solution = searcher->search(mathExp);
        }catch (const std::exception &e){
            solution=e.what();
        }
        return solution+"\n";
    }

    virtual ~MathSolver(){
        delete searcher;
    }
};

#endif //PROBLEMSOLVER_MATHSOLVER_H
