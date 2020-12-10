#ifndef PROBLEMSOLVER_MATIRXSOLVERFACTORY_H
#define PROBLEMSOLVER_MATIRXSOLVERFACTORY_H

#include "SolverFactory.h"

class MatrixSolverFactory : public SolverFactory<MatrixSolver> {
private:
    enum class SearcherType {
        A_STAR
    };
    // map for searcher to int
    std::map<std::string, SearcherType> searcherToInt =
            {
                    {"A*", SearcherType::A_STAR}
            };
public:
    virtual MatrixSolver *getSolver(const string &searcher) {
        SearcherType searcherType = searcherToInt[searcher];
        switch (searcherType) {
            case SearcherType::A_STAR:
                return new MatrixSolver(new Astar());
        }

    }

    virtual ~MatrixSolverFactory() = default;
};

#endif //PROBLEMSOLVER_MATIRXSOLVERFACTORY_H
