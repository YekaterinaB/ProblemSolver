
#ifndef PROBLEMSOLVER_SEARCHERFACTORY_H
#define PROBLEMSOLVER_SEARCHERFACTORY_H

#include <string>
#include "../Searcher/Searcher.h"

using namespace std;
class SearcherFactory {
public:

    virtual Searcher* getSearcher(const string &searcher)=0;
    virtual ~SearcherFactory() = default;
};
#endif //PROBLEMSOLVER_SEARCHERFACTORY_H
