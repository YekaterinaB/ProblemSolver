//
// Created by eladg on 10/12/2020.
//

#ifndef PROBLEMSOLVER_CONFIGURATION_H
#define PROBLEMSOLVER_CONFIGURATION_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <iterator>
#include "../StringUtils.h"

#define HEAD_TAG "head>"
using namespace std;

class Configuration {
private:
    static inline std::pair<std::string, std::vector<std::string>> getPair(string &s);

    static inline vector<string> split(string str, const string &token);

public:
    static vector<std::pair<std::string, vector<std::string>>> readXmlFile(const string &dir);
};

#endif //PROBLEMSOLVER_CONFIGURATION_H
