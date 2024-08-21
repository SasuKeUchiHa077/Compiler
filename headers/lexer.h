#ifndef LEXER_H
#define LEXER_H

#include <cstddef>
#include <string>
#include <vector>

enum class TokenType {
    IDENTIFIER, //variable names 
    NUMBER, //numeric values
    SYMBOL, //special characters
    END_OF_FILE, //EOF
    UNKNOWN //invalid characters
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
private:
    std::string source;
    size_t position;
    char currentChar;

    void Advance();
    char Peek() const;
    void SkipWhiteSpace();
    Token Identifier();
    Token Number();
    Token Symbol();

public:
    Lexer(const std::string &sourceCode);
    Token GetNextToken();
};

#endif // !LEXER_H
