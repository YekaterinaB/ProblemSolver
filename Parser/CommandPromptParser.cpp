#include "CommandPromptParser.h"
#include "../StringUtils.h"

string CommandPromptParser::parse() {
    string userInput="";
    string problem="";
    cout << "Enter the problem: (write 'end' to finish)";
    do {
        std::getline(std::cin, userInput);

        problem +=userInput+"\n";
    } while (! StringUtils::endsWith(userInput,"end"));
    StringUtils::trim(problem);
    StringUtils::eraseAllSubStr(problem,"\nend");
    return problem;
}