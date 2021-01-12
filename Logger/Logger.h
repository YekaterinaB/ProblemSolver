//
// Created by eladg on 09/01/2021.
//

#ifndef PROBLEMSOLVER_LOGGER_H
#define PROBLEMSOLVER_LOGGER_H

#include <iostream>
#include <fstream>

using namespace std;

class Logger {
private:
    static Logger *_logger;
    ofstream _file;

    Logger();

    ~Logger();
public:
    static Logger *getInstance();

    void log(const string &message);

    static void resetInstance();
};
#endif //PROBLEMSOLVER_LOGGER_H
