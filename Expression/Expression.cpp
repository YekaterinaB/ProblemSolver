#include "Expression.h"

//value
double Value::calculate() {
    return this->num;
}

Value::Value(const double number) {
    this->num = number;
}
//binary
Expression* BinaryOperator::getLeft() {
    return this->left;
}

Expression* BinaryOperator::getRight() {
    return this->right;
}

BinaryOperator::~BinaryOperator() {
    delete this->left;
    delete this->right;
}

//plus
Plus::Plus(Expression *leftEX, Expression *rightEX) {
    this->left = leftEX;
    this->right = rightEX;
}

double Plus::calculate() {
    return (this->getLeft()->calculate() + this->getRight()->calculate());
}

//minus
Minus::Minus(Expression *leftEX, Expression *rightEX) {
    this->left = leftEX;
    this->right = rightEX;
}

double Minus::calculate() {
    return (this->getLeft()->calculate() - this->getRight()->calculate());
}

//mul
Mul::Mul(Expression *leftEX, Expression *rightEX) {
    this->left = leftEX;
    this->right = rightEX;
}

double Mul::calculate() {
    return (this->getLeft()->calculate() * this->getRight()->calculate());
}

//div

Div::Div(Expression *leftEX, Expression *rightEX) {
    this->left = leftEX;
    this->right = rightEX;
}

double Div::calculate() {
    if (this->getRight()->calculate() < 0.0001) {
        throw "Divide by 0";
    }
    return (this->getLeft()->calculate() / this->getRight()->calculate());
}

//unary
UnaryOperator::~UnaryOperator() {
    delete this->exp;
}

Expression *UnaryOperator::getExp() {
    return this->exp;
}
//uplus
UPlus::UPlus(Expression *e) {
    this->exp = e;
}

double UPlus::calculate() {
    double val = this->getExp()->calculate();
    return val;
}


//uminus
UMinus::UMinus(Expression *e) {
    this->exp = e;
}

double UMinus::calculate() {
    double val = this->getExp()->calculate();
    return val * (-1);
}
