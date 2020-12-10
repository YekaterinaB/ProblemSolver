//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_SOLVERFACTORY_H
#define PROBLEMSOLVER_SOLVERFACTORY_H
#include <vector>
#include <string>
#include "Solver/Solver.h"
#include <map>
#include "Searcher/Astar.h"
#include "Solver/MatrixSolver.h"
#include "Searcher/ReversePolishInterpreter.h"
#include "Solver/MathSolver.h"

using namespace std;

class SolverFactory {
public:
    template<typename S>
    S *getSolver(const string &solver, const string &searcher);

    ~SolverFactory() = default;
};
#endif //PROBLEMSOLVER_SOLVERFACTORY_H
