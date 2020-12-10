//
// Created by eladg on 10/12/2020.
//
#include "Configuration.h"

vector<std::pair<std::string, vector<std::string>>> Configuration::readXmlFile(const string &dir) {
    vector<std::pair<std::string, vector<std::string>>> linesVector;

    ifstream in(dir);
    if (!in || !in.is_open()) {
        cout << "Could not read xml file: " << dir << endl;
        return linesVector;
    }

    string line;
    while (getline(in, line)) {
        if (line.find(HEAD_TAG) != std::string::npos) {
            continue;
        }
        StringUtils::trim(line);
        auto pair = getPair(line);
        linesVector.push_back(pair);
    }

    in.close();
}

std::pair<std::string, std::vector<std::string>> Configuration::getPair(string &s) {
    unsigned opening = s.find('>');
    string key = s.substr(1, opening - 1);
    unsigned closing = s.find("</");
    vector<std::string> allNames = {};
    string value = s.substr(opening + 1, closing - opening - 1);
    return std::pair<std::string, vector<std::string>>(key, split(value, ","));
}

std::vector<std::string> Configuration::split(std::string str, const std::string &token) {
    std::vector<std::string> result;
    while (!str.empty()) {
        int index = str.find(token);
        if (index != string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.empty()) {
                StringUtils::trim(str);
                result.push_back(str);
            }
        } else {
            StringUtils::trim(str);
            result.push_back(str);
            str = "";
        }
    }
    return result;
}