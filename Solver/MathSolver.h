
#ifndef PROBLEMSOLVER_MATHSOLVER_H
#define PROBLEMSOLVER_MATHSOLVER_H

#include "Solver.h"
#include "../Expression/Expression.h"

class MathSolver : public Solver {
private:
    MathSearcher *_searcher;
public:
    MathSolver(Searcher *s):_searcher(nullptr) {
        if(s != nullptr && s->getType() == "MathSearcher"){
            _searcher =(MathSearcher*) s;
        }
    }

    virtual string solve(const string &problem) {
        string mathExp = problem;
        string solution;
        try {
            solution = _searcher->search(mathExp);
            Logger::getInstance()->log("Found a solution using MathSolver...\n" + solution);
        } catch (const string &e) {
            Logger::getInstance()->log("An error has occurred\n" + e);
            solution = e;
        } catch (...) {
            Logger::getInstance()->log("An error has occurred...");
            solution = "An error has occurred.";

        }
        return solution + "\n";
    }

    virtual ~MathSolver() {
        delete _searcher;
    }
};

#endif //PROBLEMSOLVER_MATHSOLVER_H
