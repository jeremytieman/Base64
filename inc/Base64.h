#pragma once

#include <string>
#include <vector>

namespace CodexMachina
{
    std::string encode(std::vector<char> bytes);
    std::vector<char> decode(std::string s);
}