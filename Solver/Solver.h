//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_SOLVER_H
#define PROBLEMSOLVER_SOLVER_H

#include <string>
#include "../Searcher/Searcher.h"

using namespace std;
//P problem, S solution, T parsed problem
template<typename P, typename S,typename T>
class Solver {
protected:
    string solution = "";
    Searcher<S,T> *searcher;

public:
    virtual string toString(const S &solution) = 0;

    virtual S solve(const P &problem) = 0;
};

#endif //PROBLEMSOLVER_SOLVER_H
