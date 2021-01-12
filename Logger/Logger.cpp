//
// Created by eladg on 09/01/2021.
//

#include "Logger.h"

Logger *Logger::logger = nullptr;

Logger::Logger() {
    try {
        file = ofstream("logger.txt");
    } catch (...) {
        cerr << "Could not create logger file";
    }
}

Logger::~Logger() {
    if (file && file.is_open()) {
        file.close();
    }
}

Logger *Logger::getInstance() {
    if (!logger) {
        logger = new Logger();
    }

    return logger;
}

void Logger::log(const string &message) {
    if (file && file.is_open()) {
        file << message + '\n';
    }
}


void Logger::resetInstance() {
    delete logger;
    logger = nullptr;
}

