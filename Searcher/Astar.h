//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_ASTAR_H
#define PROBLEMSOLVER_ASTAR_H

#include <map>
#include <set>
#include <limits>
#include "Searcher.h"
#include "CustomPriorityQueue.h"
#include "MatrixSearcher.h"

class Astar : public MatrixSearcher {
public:
    virtual vector<State *> search(MatrixMaze &searchable);



};


#endif //PROBLEMSOLVER_ASTAR_H
