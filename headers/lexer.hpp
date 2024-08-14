#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>

class Lexer {
private:
    std::string source;
    int cursor = 0;
    int size = 0;
    char current;

public:
    Lexer(std::string sourceCode) {
        this->source = sourceCode;
        this->cursor = 0;
        this->size = sourceCode.size();
        this->current = sourceCode.at(cursor);
    }
};

#endif // !LEXER_HPP
