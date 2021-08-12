#include "../inc/Base64.hpp"

#include <sstream>
#include <unordered_map>

using namespace std;

vector<char> encodings{
    'A', 'B', 'C', 'D', 'E',
    'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y',
    'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x',
    'y', 'z', '0', '1', '2',
    '3', '4', '5', '6', '7',
    '8', '9', '+', '/'
};

unordered_map<char, char> decodings{
    { 'A', 0 }, { 'B', 1 }, { 'C', 2 }, { 'D', 3 }, { 'E', 4 },
    { 'F', 5 }, { 'G', 6 }, { 'H', 7 }, { 'I', 8 }, { 'J', 9 },
    { 'K', 10 }, { 'L', 11 }, { 'M', 12 }, { 'N', 13 }, { 'O', 14 },
    { 'P', 15 }, { 'Q', 16 }, { 'R', 17 }, { 'S', 18 }, { 'T', 19 },
    { 'U', 20 }, { 'V', 21 }, { 'W', 22 }, { 'X', 23 }, { 'Y', 24 },
    { 'Z', 25 }, { 'a', 26 }, { 'b', 27 }, { 'c', 28 }, { 'd', 29 },
    { 'e', 30 }, { 'f', 31 }, { 'g', 32 }, { 'h', 33 }, { 'i', 34 },
    { 'j', 35 }, { 'k', 36 }, { 'l', 37 }, { 'm', 38 }, { 'n', 39 },
    { 'o', 40 }, { 'p', 41 }, { 'q', 42 }, { 'r', 43 }, { 's', 44 },
    { 't', 45 }, { 'u', 46 }, { 'v', 47 }, { 'w', 48 }, { 'x', 49 },
    { 'y', 50 }, { 'z', 51 }, { '0', 52 }, { '1', 53 }, { '2', 54 },
    { '3', 55 }, { '4', 56 }, { '5', 57 }, { '6', 58 }, { '7', 59 },
    { '8', 60 }, { '9', 61 }, { '+', 62 }, { '/', 63 }
};

string CodexMachina::encode(vector<char> bytes)
{
    stringstream ss;
    unsigned char state = 0;
    unsigned char e = 0;

    for (const auto b : bytes)
    {
        if (0 == state)
        {
            e = (b & 0b11111100) >> 2;
            ss << encodings[e];
            e = (b & 0b00000011) << 4;
            ++state;
        }
        else if (1 == state)
        {
            e |= (b & 0b11110000) >> 4;
            ss << encodings[e];
            e = (b & 0b00001111) << 2;
            ++state;
        }
        else if (2 == state)
        {
            e |= (b & 0b11000000) >> 6;
            ss << encodings[e];
            e = (b & 0b00111111);
            ss << encodings[e];
            state = 0;
        }
    }

    if (1 == state) ss << encodings[e] << "==";
    else if (2 == state) ss << encodings[e] << "=";
    return ss.str();
}

vector<char> CodexMachina::decode(string s)
{
    vector<char> result;
    unsigned char state = 0;
    char e = 0;

    for (const auto c : s)
    {
        if (0 == state)
        {
            e = decodings[c] << 2;
            ++state;
        }
        else if (1 == state)
        {
            const auto tmp = decodings[c];
            e |= (tmp & 0b00110000) >> 4;
            result.push_back(e);
            e = (tmp & 0b00001111) << 4;
            ++state;
        }
        else if (2 == state)
        {
            if ('=' == c) break;
            const auto tmp = decodings[c];
            e |= (tmp & 0b00111100) >> 2;
            result.push_back(e);
            e = (tmp & 0b00000011) << 6;
            ++state;
        }
        else if (3 == state)
        {
            if ('=' == c) break;
            e |= decodings[c];
            result.push_back(e);
            state = 0;
        }
    }

    return result;
}