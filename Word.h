#ifndef WORD
#define WORD

#include <string>
using namespace std;

class Word {
    public:
        Word();
        Word(const string);
        string token;
        int frequency;
        int code;
    private:

};

#endif
