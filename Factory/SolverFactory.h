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
#include "SearcherFactory.h"
#include "MathSearcherFactory.h"
#include "MatirxSearcherFactory.h"

using namespace std;
class SolverFactory {
private:
private:
    enum class SolverType {
        MATH_SOLVER,MATRIX_SOLVER
    };
    // map for searcher to int
    std::map<std::string, SolverType> searcherToInt =
            {
                    {"MatrixSolver", SolverType::MATRIX_SOLVER},
                    {"MathSolver", SolverType::MATH_SOLVER}

            };
public:

    Solver *getSolver(const string &solver,const string &searcher){
        SolverType solverType = searcherToInt[solver];
        Solver * s= nullptr;
        switch (solverType) {
            case SolverType::MATH_SOLVER:
                s = new MathSolver(MathSearcherFactory().getSearcher(searcher));
                break;
            case SolverType ::MATRIX_SOLVER:
                 s = new MatrixSolver(MatrixSearcherFactory().getSearcher(searcher));
                break;

        }
        return s;
    }

    virtual ~SolverFactory()= default;
};
#endif //PROBLEMSOLVER_SOLVERFACTORY_H
