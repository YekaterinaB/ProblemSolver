//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_MATHSEARCHERFACTORY_H
#define PROBLEMSOLVER_MATHSEARCHERFACTORY_H

#include <map>
#include "SearcherFactory.h"
#include "../Searcher/ReversePolishInterpreter.h"

using namespace std;
class MathSearcherFactory : public SearcherFactory {
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
    virtual MathSearcher *getSearcher(const string &searcher) {
        SearcherType searcherType = searcherToInt[searcher];
        switch (searcherType) {
            case SearcherType::ReversePolishInterpreter:
                return new ReversePolishInterpreter();

        }

    }

    virtual ~MathSearcherFactory() = default;
};

#endif //PROBLEMSOLVER_MATHSEARCHERFACTORY_H
