//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_REVERSEPOLISHINTERPRETER_H
#define PROBLEMSOLVER_REVERSEPOLISHINTERPRETER_H

#include <string>
#include <queue>
#include <regex>
#include "Searcher.h"
#include "../Expression/Expression.h"

using namespace std;


class ReversePolishInterpreter : public Searcher<double, string> {
private:
    char excep[128];

    queue<string> getReversePolish(const string &mathExp);

    void readingStringToReversePolish(const string &mathExp, queue<string> &outputQueue, stack<string> &operatorStack,
                                      vector<char> &numberVector, int &countOpenParenthesis);

    Expression *interpret(const string &mathExp);

    void closedParenthesisTokenCase(stack<string> &operatorStack, queue<string> &outputQueue,
                                    int &countOpenParenthesis);

    void operatorTokenCase(stack<string> &operatorStack, queue<string> &outputQueue, char *token, int loopNum,
                           char *lastToken);

    bool isOperator(const string &s);

public:
    double search(const string &mathExp);


};

#endif //PROBLEMSOLVER_REVERSEPOLISHINTERPRETER_H
