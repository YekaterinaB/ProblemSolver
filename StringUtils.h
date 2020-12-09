//
// Created by katya on 12/9/2020.
//

#ifndef PROBLEMSOLVER_STRINGUTILS_H
#define PROBLEMSOLVER_STRINGUTILS_H

#include "string"
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

class StringUtils {
public:
    static bool matchRegex(const string &subject, const string &pattern) {
        bool match = true;
        if (!subject.empty() || !pattern.empty()) {
            const regex re(pattern);
            match = regex_match(subject, re);
        }

        return match;
    }

    static bool endsWith(const std::string &str, const std::string &suffix) {
        return str.size() >= suffix.size() && 0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
    }

    static vector<string> split(const basic_string<char> &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static vector<string> split(const string &s, const string &delimiter) {
        vector<string> result{};
        if (!s.empty()) {
            string copy = s;
            size_t pos = 0;
            string token;
            while ((pos = copy.find(delimiter)) != string::npos) {
                token = copy.substr(0, pos);
                result.push_back(token);
                copy.erase(0, pos + delimiter.length());
            }
        }

        return result;
    }

    static string &ltrim(string &str, const string &chars = "\t\n\v\f\r ") {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }

    static string &rtrim(string &str, const string &chars = "\t\n\v\f\r ") {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }

    static string &trim(string &str, const string &chars = "\t\n\v\f\r ") {
        return ltrim(rtrim(str, chars), chars);
    }

    static void eraseAllSubStr(std::string &mainStr, const std::string &toErase) {
        size_t pos = std::string::npos;

        // Search for the substring in string in a loop untill nothing is found
        while ((pos = mainStr.find(toErase)) != std::string::npos) {
            // If found then erase it from string
            mainStr.erase(pos, toErase.length());
        }
    }

    static bool isCharInString(const string &str, char c) {
        return (strchr(str.c_str(), c));
    }

    static vector<string> splitByFirstChar(const string &str, char c) {
        // split string by first char
        vector<string> newVector;
        newVector.push_back(str.substr(0, str.find(c)));
        newVector.push_back(str.substr(str.find(c) + 1, str.length()));
        return newVector;
    }
};
#endif //PROBLEMSOLVER_STRINGUTILS_H
