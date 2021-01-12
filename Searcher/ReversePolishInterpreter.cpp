#include <stack>
#include <cstring>
#include "ReversePolishInterpreter.h"
#include "../Logger/Logger.h"

regex doubleNumberRegex("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
map<string, int> operatorPrecedence = {{"+", 1},
                                       {"-", 1},
                                       {"*", 2},
                                       {"/", 2}};


void ReversePolishInterpreter::readingStringToReversePolish(const string &mathExp, queue<string> &outputQueue,
                                                            stack<string> &operatorStack,
                                                            vector<char> &numberVector,
                                                            int &countOpenParenthesis) {
    char last[2] = {0}; // last read char
    for (int i = 0; i < mathExp.size(); i++) {
        char token[2] = {0}; //More room for \0
        token[0] = mathExp.at(i);
        if (isdigit(token[0]) || token[0] == '.') {
            // if the number is not from the variable reading.
            numberVector.push_back(token[0]);
        } else {
            if (!numberVector.empty()) {
                // finished reading number from string
                char number[10] = {0};
                strncpy(number, &numberVector[0], numberVector.size());
                if (!regex_match(number, doubleNumberRegex)) {
                    strcpy(this->excep, "Character is not number double: ");
                    strcat(this->excep, number);
                    throw string(this->excep);
                }
                outputQueue.push(number);
                numberVector.clear();
            }

            //checking the current token
            if (isOperator(token)) {
                operatorTokenCase(operatorStack, outputQueue, token, i, last);

            } else if (token[0] == '(') {
                countOpenParenthesis++;
                operatorStack.push(token);

            } else if (token[0] == ')') {
                closedParenthesisTokenCase(operatorStack, outputQueue, countOpenParenthesis);

            }
        }
        strcpy(last, token);
    } //stopped reading.

}

queue<string> ReversePolishInterpreter::getReversePolish(const string &mathExp) {
    queue<string> outputQueue;
    stack<string> operatorStack;
    vector<char> numberVector;
    int countOpenParenthesis = 0;

    readingStringToReversePolish(mathExp, outputQueue, operatorStack, numberVector, countOpenParenthesis);

    if (countOpenParenthesis > 0) {//more open than closed Parenthesis.
        throw string("There is more open parenthesis then closed ones.");
    }

    if (!numberVector.empty()) {
        // finished reading number from string
        char number[10] = {0};
        strncpy(number, &numberVector[0], numberVector.size());
        if (!regex_match(number, doubleNumberRegex)) {
            strcpy(this->excep, "Character is not number double: ");
            strcat(this->excep, number);
            throw string(this->excep);
        }
        outputQueue.push(number);
        numberVector.clear();
    }


    while (!operatorStack.empty()) {
        outputQueue.push(operatorStack.top());
        operatorStack.pop();
    }
    return outputQueue;
}

void ReversePolishInterpreter::operatorTokenCase(stack<string> &operatorStack, queue<string> &outputQueue, char *token,
                                                 int loopNum,
                                                 char *lastToken) {
    if (strcmp(token, "-") == 0 || strcmp(token, "+") == 0) { // unary operator check.
        if (loopNum == 0 || strcmp(lastToken, "(") == 0 ||
            isOperator(lastToken)) { // before operator no number, or just nothing(i=0)>unary
            outputQueue.push("0");
            operatorStack.push(token);
            strcpy(lastToken, token);
            return;
        }
    }
    if (!operatorStack.empty()) { // binary operator.
        if (operatorPrecedence[operatorStack.top()] >= operatorPrecedence[token]) {
            outputQueue.push(operatorStack.top());
            operatorStack.pop();
        }
    }
    operatorStack.push(token);

}

void ReversePolishInterpreter::closedParenthesisTokenCase(stack<string> &operatorStack, queue<string> &outputQueue,
                                                          int &countOpenParenthesis) {
    if (operatorStack.empty()) {
        throw string("There is more close parenthesis then open ones.");
    }
    while (operatorStack.top() != "(") {
        outputQueue.push(operatorStack.top());
        operatorStack.pop();
        if (operatorStack.empty()) {
            throw string("There is more close parenthesis then open ones.");
        }
    }
    operatorStack.pop(); // pop "(" OpenParenthesis
    countOpenParenthesis--;
}

Expression *ReversePolishInterpreter::interpret(const string &mathExp) {
    queue<string> polish = getReversePolish(mathExp);
    stack<Expression *> expressionStack;
    int len = polish.size();
    for (int i = 0; i < len; i++) {
        string front = polish.front();
        if (isOperator(front)) {
            polish.pop();

            if (expressionStack.empty()) {
                throw string("Missing expressions.");
            }
            Expression *exp1 = expressionStack.top();
            expressionStack.pop();
            if (expressionStack.empty()) {
                throw string("Missing expressions.");
            }
            Expression *exp2 = expressionStack.top();
            expressionStack.pop();

            if (front == "+") {
                expressionStack.push(new Plus(exp1, exp2));
            } else if (front == "-") {
                expressionStack.push(new Minus(exp2, exp1));
            } else if (front == "*") {
                expressionStack.push(new Mul(exp1, exp2));
            } else {
                expressionStack.push(new Div(exp2, exp1));
            }
        } else {
            if (regex_match(front, doubleNumberRegex)) {
                expressionStack.push(new Value(stod(front)));
                polish.pop();
            } else {
                strcpy(this->excep, "Not a number nor a operator inserted in string: ");
                strcat(this->excep, front.c_str());
                throw string(this->excep);
            }
        }
    }
    if (expressionStack.size() > 1 || expressionStack.empty()) {
        throw string("Missing expressions.");
    }
    return expressionStack.top();
}

string ReversePolishInterpreter::search(const string &mathExp) {
    Logger::getInstance()->log("Starting to solve using ReversePolishInterpreter...\n" + mathExp);
    Expression *e = interpret(mathExp);
    double result = e->calculate();
    delete e;
    return to_string(result);
}


