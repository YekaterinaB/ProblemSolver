#ifndef PROBLEMSOLVER_SEARCHER_H
#define PROBLEMSOLVER_SEARCHER_H

#include <vector>

using namespace std;

class Searcher {
public:
    virtual string search(const string &searchable) = 0;

    virtual ~Searcher() = default;
};
#endif //PROBLEMSOLVER_SEARCHER_H
