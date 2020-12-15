#include "CommandPromptParser.h"

string CommandPromptParser::parse() {
    string userInput;
    cout << "Enter the problem:";
    cin >> userInput;
    return userInput;
}