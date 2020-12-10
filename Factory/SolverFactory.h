//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_SOLVERFACTORY_H
#define PROBLEMSOLVER_SOLVERFACTORY_H
#include <vector>
#include <string>
#include "../Solver/Solver.h"
#include <map>
#include "../Searcher/Astar.h"
#include "../Solver/MatrixSolver.h"
#include "../Searcher/ReversePolishInterpreter.h"
#include "../Solver/MathSolver.h"

using namespace std;
template<typename S>
class SolverFactory {
public:

    virtual S *getSolver(const string &searcher)=0;

    virtual ~SolverFactory() = default;
};
#endif //PROBLEMSOLVER_SOLVERFACTORY_H
