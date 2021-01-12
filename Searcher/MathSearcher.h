//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_MATHSEARCHER_H
#define PROBLEMSOLVER_MATHSEARCHER_H

#include <string>

using namespace std;

class MathSearcher : public Searcher {
protected:
    bool isOperator(const string &s) {
        return s == "-" || s == "+" ||
               s == "*" || s == "/";
    }
public:
    MathSearcher(){
        _type="MathSearcher";
    }
    virtual string search(const string &searchable) = 0;
    virtual ~MathSearcher()= default;
};

#endif //PROBLEMSOLVER_MATHSEARCHER_H
