#include <algorithm>
#include "Astar.h"

string Astar::search(const string &matrixMazeStr) {
    MatrixMaze matrixMaze =createProblemFromString(matrixMazeStr);
    // The set of discovered nodes that may need to be (re-)expanded.
    // Initially, only the start node is known.
    State *initialState = matrixMaze.getInitialState();
    initialState->setCost(matrixMaze.getCostToGetToNode(initialState));
    State goalState = matrixMaze.getGoalState();
    CustomPriorityQueue<State, vector<State>, greater<>> openSet;
    initialState->setCost(matrixMaze.getCostToGetToNode(initialState));
    vector<State *> currentStates = {initialState};
    openSet.push(*currentStates.at(0));

    // For node n, cameFrom[n] is the node immediately preceding
    // it on the cheapest path from start to n currently known.
    map<State *, State *> cameFrom;

    // For node n, gScore[n] is the cost of the cheapest path from start to n currently known.
    map<State *, double> gScore;

    //  set cost of state s to infinity
    gScore[initialState] = initialState->getCurrentCost();

    // For node n, fScore[n] := gScore[n] + h(n).
    map<State *, double> fScore;
    fScore[initialState] = gScore[initialState] + matrixMaze.getHeuristic(initialState);

    State current;
    double tentative_gScore = 0;
    State *currentStatePointer = nullptr;
    while (!openSet.empty()) {
        current = openSet.top();
        currentStatePointer = findState(currentStates, current);
        if (current == goalState) {
            vector<State*> trace= backTrace(currentStatePointer);
            return toString(trace);
        }

        openSet.pop();
        currentStates.erase(remove(currentStates.begin(), currentStates.end(),
                                   currentStatePointer), currentStates.end());

        for (auto neighbor : matrixMaze.getAllPossibleStates(currentStatePointer)) {
            // d(current,neighbor) is the weight of the edge from current to neighbor
            // tentative_gScore is the distance from start to the neighbor through current
            if (gScore.find(neighbor) == gScore.end()) {
                gScore[neighbor] = numeric_limits<double>::infinity();
            }

            tentative_gScore = gScore[currentStatePointer] + matrixMaze.getCostToGetToNode(neighbor);

            if (tentative_gScore < gScore[neighbor]) {
                // This path to neighbor is better than any previous one. Record it!
                neighbor->setCameFrom(currentStatePointer);
                gScore[neighbor] = tentative_gScore;
                fScore[neighbor] = gScore[neighbor] + matrixMaze.getHeuristic(neighbor);
                neighbor->setCost(gScore[neighbor]);
                if (!openSet.contains(*neighbor)) {
                    openSet.push(*neighbor);
                    currentStates.push_back(neighbor);
                }
            }
        }
    }

    // Open set is empty but goal was never reached
    return {};
}
