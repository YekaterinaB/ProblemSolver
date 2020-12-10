//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_MATHSEARCHER_H
#define PROBLEMSOLVER_MATHSEARCHER_H

#include <string>

using namespace std;

class MathSearcher : public Searcher<double, string> {
protected:
    bool isOperator(const string &s) {
        return s == "-" || s == "+" ||
               s == "*" || s == "/";
    }
public:
    virtual double search(string &searchable) = 0;

};

#endif //PROBLEMSOLVER_MATHSEARCHER_H
