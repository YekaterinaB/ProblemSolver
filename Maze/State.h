//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_STATE_H
#define PROBLEMSOLVER_STATE_H
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

class State {
private:
    string _stateDescription;
    double _cost = INFINITY;
    State *_cameFrom;

public:
    State() { _cameFrom = nullptr; }

    void init(const string &state) {
        _stateDescription = state;
    }

    State(const State &s) {//copy const for initial State
        _stateDescription = s.getDescription();

        _cost = s.getCurrentCost();
        _cameFrom = s._cameFrom;
    }

//
//    State(const string &state, State *cameFrom) {
//        _stateDescription = state;
//        this->_cameFrom = cameFrom;
//    }

    void setCameFrom(State *s) { _cameFrom = s; }

    State *getPreviousState() {
        return _cameFrom;
    }


    string getDescription() const {
        return _stateDescription;
    }


    double getCurrentCost() const { return _cost; }

    void setCost(double c) { this->_cost = c; }

    friend bool operator>(const State &s1, const State &s2) {
        return s1._cost > s2._cost;
    }

    friend bool operator>=(const State &s1, const State &s2) {
        return s1._cost >= s2._cost;
    }

    friend bool operator<(const State &s1, const State &s2) {
        return s1._cost < s2._cost;
    }

    friend bool operator<=(const State &s1, const State &s2) {
        return s1._cost <= s2._cost;
    }

    friend bool operator==(const State &s1, const State &s2) {
        return s1.getDescription() == s2.getDescription();
    }

    friend bool operator!=(const State &s1, const State &s2) {
        return s1.getDescription() != s2.getDescription();
    }

};

#endif //PROBLEMSOLVER_STATE_H
