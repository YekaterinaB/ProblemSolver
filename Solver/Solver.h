//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_SOLVER_H
#define PROBLEMSOLVER_SOLVER_H

#include <string>
#include "../Searcher/Searcher.h"

using namespace std;
class Solver {
public:
    virtual string solve(const string &problem) = 0;
    virtual ~Solver()= default;
};

#endif //PROBLEMSOLVER_SOLVER_H
