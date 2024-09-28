#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <sstream>

class Tokenizer {
public:
    Tokenizer(const std::string& str) : stream(str) {}

    std::string next() {
        std::string token;
        stream >> token;
        return token;
    }

private:
    std::istringstream stream;
};

#endif // TOKENIZER_s
