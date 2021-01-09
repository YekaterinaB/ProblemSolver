//
// Created by eladg on 09/01/2021.
//

#include "Logger.h"

Logger *Logger::logger = nullptr;

Logger::Logger() {
    file = ofstream("logger.txt");
}

Logger::~Logger() {
    if (file.is_open()) {
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
    file << message + '\n';
}


void Logger::resetInstance() {
    delete logger;
    logger = nullptr;
}

