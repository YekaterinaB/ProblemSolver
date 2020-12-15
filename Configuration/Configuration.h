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
#include "../json/single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Configuration {
public:
    static pair<pair<string, vector<pair<string, vector<string>>>>, pair<string, vector<string>>>
    readJSONFile(const string &dir);
};

#endif //PROBLEMSOLVER_CONFIGURATION_H
