//
// Created by eladg on 10/12/2020.
//
#include "Configuration.h"
#include "../Logger/Logger.h"

pair<pair<string, vector<pair<string, vector<string>>>>, pair<string, vector<string>>>
Configuration::readJSONFile(const string &dir) {
    Logger::getInstance()->log("Reading JSON configuration file...");
    ifstream i(dir);
    if (!i.is_open()) {
        cerr << "Could not read json file!" << endl;
        return {};
    }
    json j;
    i >> j;
    i.close();
    vector<pair<string, vector<string>>> solvers = {};
    vector<string> parsers = {};

    auto solversJson = json::object();
    j.at("Solvers").get_to(solversJson);
    vector<string> matrixSolvers = solversJson["MatrixSolver"];
    vector<string> mathSolvers = solversJson["MathSolver"];
    solvers = {pair<string, vector<string>>("MatrixSolver", matrixSolvers),
               pair<string, vector<string>>("MathSolver", mathSolvers)};
    j.at("Parsers").get_to(parsers);
    auto solversPair = pair<string, vector<pair<string, vector<string>>>>("Solvers", solvers);
    auto parsersPair = pair<string, vector<string>>("Parsers", parsers);
    return pair<pair<string, vector<pair<string, vector<string>>>>, pair<string, vector<string>>>(solversPair,
                                                                                                  parsersPair);
}