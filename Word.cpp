#include "Word.h"

Word::Word() {
    token = nullptr;
    frequency = 0;
    code = 0;
}

Word::Word(const string token) {
    this->token = token;
    frequency = 1;
    code = 0;
}
