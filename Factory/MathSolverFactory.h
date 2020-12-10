//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_MATHSOLVERFACTORY_H
#define PROBLEMSOLVER_MATHSOLVERFACTORY_H

#include "SolverFactory.h"


class MathSolverFactory : public SolverFactory<MathSolver> {
private:
    enum class SearcherType {
        ReversePolishInterpreter
    };
    // map for searcher to int
    std::map<std::string, SearcherType> searcherToInt =
            {
                    {"ReversePolishInterpreter", SearcherType::ReversePolishInterpreter}
            };
public:
    virtual MathSolver *getSolver(const string &searcher) {
        SearcherType searcherType = searcherToInt[searcher];
        switch (searcherType) {
            case SearcherType::ReversePolishInterpreter:
                MathSearcher *s = new ReversePolishInterpreter();
                return new MathSolver(s);
        }

    }

    virtual ~MathSolverFactory() = default;
};

#endif //PROBLEMSOLVER_MATHSOLVERFACTORY_H
