//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATRIXMAZE_H
#define PROBLEMSOLVER_MATRIXMAZE_H

#include "../StringUtils.h"
#include "State.h"

class MatrixMaze {
private:
    double **_matrix;
    int _sizeCol;
    int _sizeRow;
    State *_initial;
    State _goal;
    vector<State *> _allStates;

public:
    
    MatrixMaze(double **mat, int N, int M, State &ini, State g) {
        _sizeCol = M;
        _sizeRow = N;
        _matrix = mat;
        _initial = new State(ini);
        _allStates.push_back(_initial);
        _goal = g;
    }

    State * getInitialState()const { return _initial; }

    State getGoalState()const  { return _goal; }

    vector<State *> getAllPossibleStates(State *s) {
        vector<State *> succesors = {};
        vector<int> place = getPlacementOfNodeInMatrix(s);
        int i = place.at(0);
        int j = place.at(1);
        vector<int> previousStatePlacement;
        if (*s == *getInitialState()) {//first node doesnt have a dad
            previousStatePlacement = {0, 0};
        } else {
            previousStatePlacement = getPlacementOfNodeInMatrix(s->getPreviousState());
        }
        //check if he didnt go pass the border,
        // and through a wall, and if he is not coming from his dad.

        if (i < _sizeRow - 1 && _matrix[i + 1][j] != -1
            && i + 1 != previousStatePlacement.at(0)) {
            succesors.push_back(createSuccesorState(s, i + 1, j));
        }
        if (i > 0 && _matrix[i - 1][j] != -1
            && i - 1 != previousStatePlacement.at(0)) {
            succesors.push_back(createSuccesorState(s, i - 1, j));
        }
        if (j < _sizeCol - 1 && _matrix[i][j + 1] != -1
            && j + 1 != previousStatePlacement.at(1)) {
            succesors.push_back(createSuccesorState(s, i, j + 1));
        }
        if (j > 0 && _matrix[i][j - 1] != -1
            && j - 1 != previousStatePlacement.at(1)) {
            succesors.push_back(createSuccesorState(s, i, j - 1));
        }
        return succesors;
    }

    State* createSuccesorState(State *s, int i, int j) {
        string place = to_string(i) + ',' + to_string(j);
        State *newState = nullptr;
        newState = new State();
        newState->init(place);
        _allStates.push_back(newState);

        return newState;
    }

    double getHeuristic(State *state) {
        double cost = 1;
        if (state != nullptr) {
            vector<int> place = getPlacementOfNodeInMatrix(state);

            auto goalState = getGoalState();
            vector<int> goalPlace = getPlacementOfNodeInMatrix(&goalState);
            vector<int> initialPlace = getPlacementOfNodeInMatrix(this->_initial);
            if (!goalPlace.empty() && !initialPlace.empty()) {
                double dx1 = abs(place.at(0) - goalPlace.at(0));
                double dy1 = abs(place.at(1) - goalPlace.at(1));
                double dx2 = abs(initialPlace.at(0) - goalPlace.at(0));
                double dy2 = abs(initialPlace.at(1) - goalPlace.at(1));
                double cross = abs(dx1 * dy2 - dx2 * dy1);
                cost = cross * 0.001;
            }
        }
        return cost;
    }

    string getDirection(State *s) const{
        //after finished calculating route, calculate the direction that was chosen
        string direction;
        vector<int> place = getPlacementOfNodeInMatrix(s);
        vector<int> previousStatePlace = getPlacementOfNodeInMatrix(s->getPreviousState());
        if (place.at(0) == previousStatePlace.at(0)) {//same row
            if (place.at(1) - 1 == previousStatePlace.at(1)) {
                direction = "Right";
            } else {
                direction = "Left";
            }
        } else {//same col
            if (place.at(0) - 1 == previousStatePlace.at(0)) {
                direction = "Down";
            } else {
                direction = "Up";
            }
        }
        return direction;
    }


    double getCostToGetToNode(State *s) {
        vector<int> placement = getPlacementOfNodeInMatrix(s);
        int r = placement.at(0);
        int c = placement.at(1);
        return _matrix[r][c];
    }

    vector<int> getPlacementOfNodeInMatrix(State *s) const {
        // from string placement to int placement
        vector<string> place =
                StringUtils::splitByFirstChar((*s).getDescription(), ',');
        int r = atoi(place.at(0).c_str());
        int c = atoi(place.at(1).c_str());
        vector<int> placement;
        placement.push_back(r);
        placement.push_back(c);
        return placement;
    }


    static bool areInitialAndGoalValid(const State &initial, const State &goal, int N, int M) {
        bool valid = true;
        auto initialSplitted = StringUtils::split(initial.getDescription(), ',');
        auto goalSplitted = StringUtils::split(goal.getDescription(), ',');

        //get positions x,y
        auto xInitial = stod(initialSplitted.at(0));
        auto yInitial = stod(initialSplitted.at(1));
        auto xGoal = stod(goalSplitted.at(0));
        auto yGoal = stod(goalSplitted.at(1));

        if (xInitial < 0 || yInitial < 0 || xGoal < 0 || yGoal < 0
            || xInitial >= N || yInitial >= M || xGoal >= N || yGoal >= M) {
            valid = false;
        }

        return valid;
    }


    ~MatrixMaze() {
        for (int i = 0; i < _sizeRow; i++) {
            delete[] _matrix[i];
        }
        delete[] _matrix;

        while (!_allStates.empty()) {
            State *s = _allStates.back();
            _allStates.pop_back();
            delete s;
        }
    }
};

#endif //PROBLEMSOLVER_MATRIXMAZE_H
