//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATHSOLVER_H
#define PROBLEMSOLVER_MATHSOLVER_H

#include "Solver.h"

class MathSolver : public Solver<string,string,Expression>{
public:
    virtual string toString(const string &solution);

    virtual string solve(const string &problem);
};
#endif //PROBLEMSOLVER_MATHSOLVER_H
