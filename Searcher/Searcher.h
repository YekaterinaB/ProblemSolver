#ifndef PROBLEMSOLVER_SEARCHER_H
#define PROBLEMSOLVER_SEARCHER_H

#include <vector>

using namespace std;

template<typename S,typename T>
class Searcher {
public:
    virtual S search(T *searchable) = 0;

    virtual ~Searcher() = default;
};
#endif //PROBLEMSOLVER_SEARCHER_H
