#include "ToLowerString.h"

string toLowerString(string in) {
    string out = string(in.length(), ' ');
    for (int c = 0; c < in.length(); c++) {
        out[c] = std::tolower(in[c]);
    }
    return out;
}