
#include <iomanip>
#include "MatrixSearcher.h"

State *MatrixSearcher::findState(const vector<State *> &allStates, const State &stateToFind) {
    for (auto s : allStates) {
        if (s->getDescription() == stateToFind.getDescription()) {
            return s;
        }
    }
    return nullptr;
}


vector<State *> MatrixSearcher::backTrace(State *goal) {
    vector<State *> backtrace;
    while (goal->getFather() != nullptr) {
        backtrace.insert(backtrace.begin(), goal);
        goal = (*goal).getFather();
    }
    backtrace.insert(backtrace.begin(), goal);// first node
    return backtrace;
}



string MatrixSearcher::toString(const vector<State *> &backtrace,const MatrixMaze &matrixMaze) {
    string solution="";
    if (!backtrace.empty()) {
        for (State *s:backtrace) {
            if (*s == * matrixMaze.getInitialState()) {
                continue;
            }
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) << s->getCurrentCost();
            solution += matrixMaze.getDirection(s) + " (" +
                        stream.str() + "), ";
        }
        solution = solution.substr(0, solution.length() - 2);
    } else {
        solution = "No path found";
    }
    return solution;

}


MatrixMaze MatrixSearcher::createProblemFromString(const string &str) {
    vector<string> matrix = StringUtils::split(str, '\n');
    State goal;
    goal.init(matrix.back());
    matrix.pop_back();
    State initial;
    initial.init(matrix.back());
    matrix.pop_back();
    if (!StringUtils::matchRegex(initial.getDescription(), POINTS_REGEX)
        || !StringUtils::matchRegex(goal.getDescription(), POINTS_REGEX)) {
        throw string("Could not parse initial or goal position: " + initial.getDescription()
              + " ," + goal.getDescription());
    }

    int M = (StringUtils::split(matrix.front(), ',')).size();
    int N = matrix.size();

    if (!MatrixMaze::areInitialAndGoalValid(initial, goal, N, M)) {
        throw string("Starting/end position invalid");
    }

    auto **mat = new double *[N];
    for (int i = 0; i < N; i++) {
        mat[i] = new double[M];
        vector<string> nodes = StringUtils::split(matrix.front(), ',');
        matrix.erase(matrix.begin());
        for (int j = 0; j < M; j++) {
            string doub = StringUtils::trim(nodes.front());
            try{
                mat[i][j] = stod(doub);
            }catch(const exception &e){
                throw string("Invalid Matrix.");
            }
            auto it = nodes.begin();
            nodes.erase(it);
        }
    }

    return MatrixMaze(mat, N, M, initial, goal);
}


