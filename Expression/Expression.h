//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_EXPRESSION_H
#define PROBLEMSOLVER_EXPRESSION_H

class Expression {
public:
    virtual double calculate() = 0;

    virtual ~Expression() {}
};


class Value : public Expression {
    double num;
public:
    explicit Value(double number);

    double calculate() override;
};


class BinaryOperator : public Expression {
protected:
    Expression *right;
    Expression *left;
public:
    virtual Expression *getLeft();

    virtual Expression *getRight();

    virtual ~BinaryOperator();
};

class Plus : public BinaryOperator {
public:
    Plus(Expression *leftEx, Expression *rightEx);

    double calculate() override;

    ~Plus() override = default;

};

class Minus : public BinaryOperator {
public:
    Minus(Expression *leftEx, Expression *rightEx);

    double calculate() override;

    ~Minus() override = default;
};

class Mul : public BinaryOperator {
public:
    Mul(Expression *leftEx, Expression *rightEx);

    double calculate() override;

    ~Mul() override = default;
};

class Div : public BinaryOperator {
public:
    Div(Expression *leftEx, Expression *rightEx);

    double calculate() override;

    ~Div() override = default;
};

class UnaryOperator : public Expression {
protected:
    Expression *exp;
public:
    virtual Expression *getExp();

    virtual ~UnaryOperator();
};

class UPlus : public UnaryOperator {
public:
    explicit UPlus(Expression *e);

    double calculate() override;

    ~UPlus() override = default;
};

class UMinus : public UnaryOperator {
public:
    explicit UMinus(Expression *e);

    double calculate() override;

    ~UMinus() override = default;
};


#endif //PROBLEMSOLVER_EXPRESSION_H
