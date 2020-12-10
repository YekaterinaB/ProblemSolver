//
// Created by katya on 12/10/2020.
//

#ifndef PROBLEMSOLVER_PARSERFACTORY_H
#define PROBLEMSOLVER_PARSERFACTORY_H

#include <string>
#include <map>
#include "../Parser/Parser.h"
#include "../Parser/FileParser.h"
#include "../Parser/CommandPromptParser.h"

using namespace std;
class ParserFactory{
private:
    enum class ParserType {
        FILE_PARSER,
        COMMADPROMPT_PARSER
    };
    // map for searcher to int
    std::map<std::string, ParserType> searcherToInt =
            {
                    {"FileParser", ParserType::FILE_PARSER},
                    {"CommandPromptParser",ParserType::COMMADPROMPT_PARSER}
            };

public:
    virtual Parser *getParser(const string &parser){
        ParserType parseType = searcherToInt[parser];

        switch (parseType) {
            case ParserType::FILE_PARSER:
                return new FileParser();
            case ParserType::COMMADPROMPT_PARSER:
                return new CommandPromptParser();
        }
    }

    virtual ~ParserFactory() = default;
};
#endif //PROBLEMSOLVER_PARSERFACTORY_H
