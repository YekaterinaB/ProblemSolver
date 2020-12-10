//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_MATRIXMAZE_H
#define PROBLEMSOLVER_MATRIXMAZE_H

#include "../StringUtils.h"

class MatrixMaze {
private:
    double **matrix;
    int sizeCol;
    int sizeRow;
    State *initial;
    State goal;
    vector<State *> allStates;

public:
    MatrixMaze();
    MatrixMaze(double **mat, int N, int M, State &ini, State g) {
        sizeCol = M;
        sizeRow = N;
        matrix = mat;
        initial = new State(ini);
        allStates.push_back(initial);
        goal = g;
    }

    State *getInitialState() { return initial; }

    State getGoalState() { return goal; }

    vector<State *> getAllPossibleStates(State *s) {
        vector<State *> succesors = {};
        vector<int> place = getPlacementOfNodeInMatrix(s);
        int i = place.at(0);
        int j = place.at(1);
        vector<int> dadsPlace;
        if (*s == *getInitialState()) {//first node doesnt have a dad
            dadsPlace = {0, 0};
        } else {
            dadsPlace = getPlacementOfNodeInMatrix(s->getFather());
        }
        //check if he didnt go pass the border,
        // and through a wall, and if he is not coming from his dad.

        if (i < sizeRow - 1 && matrix[i + 1][j] != -1
            && i + 1 != dadsPlace.at(0)) {
            succesors.push_back(createSuccesorState(s, i + 1, j));
        }
        if (i > 0 && matrix[i - 1][j] != -1
            && i - 1 != dadsPlace.at(0)) {
            succesors.push_back(createSuccesorState(s, i - 1, j));
        }
        if (j < sizeCol - 1 && matrix[i][j + 1] != -1
            && j + 1 != dadsPlace.at(1)) {
            succesors.push_back(createSuccesorState(s, i, j + 1));
        }
        if (j > 0 && matrix[i][j - 1] != -1
            && j - 1 != dadsPlace.at(1)) {
            succesors.push_back(createSuccesorState(s, i, j - 1));
        }
        return succesors;
    }

    State *createSuccesorState(State *s, int i, int j) {
        string place = to_string(i) + ',' + to_string(j);
        State *newState = nullptr;
        for (State *state:allStates) {
            if (state->getDescription() == place) {
                newState = state;
                break;
            }
        }
        if (newState == nullptr) {
            newState = new State();
            newState->init(place);
            allStates.push_back(newState);
        }

        return newState;
    }

    double getHeuristic(State *state) {
        double cost = 1;
        if (state != nullptr) {
            vector<int> place = getPlacementOfNodeInMatrix(state);

            auto goalState = getGoalState();
            vector<int> goalPlace = getPlacementOfNodeInMatrix(&goalState);
            vector<int> initialPlace = getPlacementOfNodeInMatrix(this->initial);
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

    string getDirection(State *s) {
        string direction;
        vector<int> place = getPlacementOfNodeInMatrix(s);
        vector<int> dadsPlace = getPlacementOfNodeInMatrix(s->getFather());
        if (place.at(0) == dadsPlace.at(0)) {//same row
            if (place.at(1) - 1 == dadsPlace.at(1)) {
                direction = "Right";
            } else {
                direction = "Left";
            }
        } else {//same col
            if (place.at(0) - 1 == dadsPlace.at(0)) {
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
        return matrix[r][c];
    }

    vector<int> getPlacementOfNodeInMatrix(State *s) {
        vector<string> place =
                StringUtils::splitByFirstChar((*s).getDescription(), ',');
        int r = atoi(place.at(0).c_str());
        int c = atoi(place.at(1).c_str());
        vector<int> placement;
        placement.push_back(r);
        placement.push_back(c);
        return placement;
    }


    ~MatrixMaze() {
        for (int i = 0; i < sizeRow; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        while (!allStates.empty()) {
            State *s = allStates.back();
            allStates.pop_back();
            delete s;
        }
    }
};

#endif //PROBLEMSOLVER_MATRIXMAZE_H
