//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_VARIABLE_H
#define PROBLEMSOLVER_VARIABLE_H

#include <string>
#include "Expression.h"

using namespace std;

class Variable : public Expression {
private:
    string name;
    double value{};

public:
    Variable() = default;

    Variable(const string &s, double val) {
        name = s;
        value = val;
    }

    double getValue() { return value; }

    Variable &operator+=(const double num) {
        this->value = this->value + num;
        return *this;
    }

    Variable &operator-=(const double num) {
        this->value = this->value - num;
        return *this;
    }

    Variable &operator++() {
        this->value++;
        return *this;
    }

    Variable &operator++(int) {
        this->value++;
        return *this;
    }

    Variable &operator--() {
        this->value--;
        return *this;
    }

    Variable &operator--(int) {
        this->value--;
        return *this;
    }

    double calculate() {
        return this->getValue();
    }

    virtual ~Variable() {}

};


#endif //PROBLEMSOLVER_VARIABLE_H
