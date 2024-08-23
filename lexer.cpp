#include "headers/lexer.h"
#include <cctype>
#include <string>

Lexer::Lexer(const std::string &sourceCode) : source(sourceCode), position(0) {
    this->currentChar = this->source[this->position];
}

void Lexer::Advance() {
    this->position++;

    if (this->position < this->source.length()) {
        this->currentChar = this->source[this->position];
    } else {
        this->currentChar = '\0';
    }
}

char Lexer::Peek() const {
    if (this->position + 1 < this->source.length()) {
        return this->source[this->position + 1];
    } else {
        return '\0';
    }
}

void Lexer::SkipWhiteSpace() {
    while (this->currentChar != '\0' && isspace(this->currentChar)) {
        this->Advance();
    }
}

Token Lexer::Identifier() {
    std::string result;

    while (this->currentChar != '\0' && (isalpha(this->currentChar) || this->currentChar == '_')) {
        result += currentChar;
        this->Advance();
    }
    return {TokenType::IDENTIFIER, result};
}

Token Lexer::Number() {
    std::string result;

    while (this->currentChar != '\0' && isdigit(this->currentChar)) {
        result += this->currentChar;
        this->Advance();
    }
    return {TokenType::NUMBER, result};
}

Token Lexer::Symbol() {
    char symbol = this->currentChar;
    this->Advance();
    return {TokenType::SYMBOL, std::string(1, symbol)};
}

Token Lexer::GetNextToken() {
    while (this->currentChar != '\0') {
        if (isspace(this->currentChar)) {
            this->SkipWhiteSpace();
            continue;
        }

        if (isalpha(this->currentChar) || this->currentChar == '_') {
            return this->Identifier();
        }

        if (isdigit(this->currentChar)) {
            return this->Number();
        }

        if (ispunct(this->currentChar)) {
            return this->Symbol();
        }

        this->Advance();
    }

    return {TokenType::END_OF_FILE, ""};
}

std::string Lexer::TokenToString(const TokenType &token) {
    switch (token) {
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::SYMBOL: return "SYMBOL";
        case TokenType::END_OF_FILE: return "END_OF_FILE";

        default: return "UNKNOWN";
    }
}
