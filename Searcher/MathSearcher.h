#ifndef PROBLEMSOLVER_MATHSEARCHER_H
#define PROBLEMSOLVER_MATHSEARCHER_H

#include <string>
#include "Searcher.h"

class MathSearcher : public Searcher<double, string> {
protected:
    bool isOperator(const string &s) {
        return s == "-" || s == "+" ||
               s == "*" || s == "/";
    }

public:

    virtual double search(const string &mathExp)=0;
    virtual ~MathSearcher()= default;

};

#endif //PROBLEMSOLVER_MATHSEARCHER_H
