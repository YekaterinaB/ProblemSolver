
#ifndef PROBLEMSOLVER_SEARCHERFACTORY_H
#define PROBLEMSOLVER_SEARCHERFACTORY_H

#include <string>
#include "../Searcher/Searcher.h"

using namespace std;

class SearcherFactory {
private:
    enum class SearcherType {
        A_STAR,
        ReversePolishInterpreter
    };
    // map for searcher to int
    std::map<std::string, SearcherType> searcherToInt =
            {
                    {"A*", SearcherType::A_STAR},
                    {"ReversePolishInterpreter", SearcherType::ReversePolishInterpreter}
            };

public:
    Searcher *getSearcher(const string &searcher) {
        SearcherType searcherType = searcherToInt[searcher];
        switch (searcherType) {
            case SearcherType::A_STAR:
                return new Astar();
            case SearcherType::ReversePolishInterpreter:
                return new ReversePolishInterpreter();
        }
    }

    virtual ~SearcherFactory() = default;
};

#endif //PROBLEMSOLVER_SEARCHERFACTORY_H
