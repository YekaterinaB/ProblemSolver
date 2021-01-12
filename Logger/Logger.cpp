//
// Created by eladg on 09/01/2021.
//

#include "Logger.h"

Logger *Logger::_logger = nullptr;

Logger::Logger() {
    try {
        _file = ofstream("logger.txt");
    } catch (...) {
        cerr << "Could not create logger file";
    }
}

Logger::~Logger() {
    if (_file && _file.is_open()) {
        _file.close();
    }
}

Logger *Logger::getInstance() {
    if (!_logger) {
        _logger = new Logger();
    }

    return _logger;
}

void Logger::log(const string &message) {
    if (_file && _file.is_open()) {
        _file << message + '\n';
    }
}


void Logger::resetInstance() {
    delete _logger;
    _logger = nullptr;
}

