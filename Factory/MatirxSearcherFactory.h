#ifndef PROBLEMSOLVER_MATIRXSEARCHERFACTORY_H
#define PROBLEMSOLVER_MATIRXSEARCHERFACTORY_H

#include <map>
#include "SearcherFactory.h"
#include "../Searcher/Astar.h"

class MatrixSearcherFactory : public SearcherFactory {
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
    virtual MatrixSearcher* getSearcher(const string &searcher) {
        SearcherType searcherType = searcherToInt[searcher];
        switch (searcherType) {
            case SearcherType::A_STAR:
                return new Astar();
        }

    }

    virtual ~MatrixSearcherFactory() = default;
};

#endif //PROBLEMSOLVER_MATIRXSEARCHERFACTORY_H
