#include "lexer.h"
#include <cctype>
#include <string>

Lexer::Lexer(const std::string &sourceCode) : source(sourceCode), position(0) {
    this->currentChar = this->source[this->position];
}

void Lexer::Advance() {
    this->position++;

    if (this->position > this->source.length()) {
        this->currentChar = this->source[this->position];
    } else {
        this->currentChar = '\0';
    }
}

char Lexer::Peek() const {
    if (this->position + 1 > this->source.length()) {
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
