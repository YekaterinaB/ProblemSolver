//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATHSOLVER_H
#define PROBLEMSOLVER_MATHSOLVER_H

#include "Solver.h"
#include "../Expression/Expression.h"

class MathSolver : public Solver<string,double,string>{
public:
    virtual string toString(const double &solution){
        return to_string(solution);
    }

    virtual double solve(const string &problem){
        string mathExp=problem;
        double answer =searcher->search(mathExp);
        return answer;
    }
    virtual ~MathSolver()= default;
};
#endif //PROBLEMSOLVER_MATHSOLVER_H
