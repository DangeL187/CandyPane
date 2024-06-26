#include "split.hpp"

std::vector<std::string> split(std::string line, char sym) {
    std::vector<std::string> vec;
    std::string line2;
    for (unsigned int i = 0; i <= line.length(); i++) {
        if (line[i] != sym && i < line.length()) {
            line2 += line[i];
        }
        if (line[i] == sym) {
            vec.push_back(line2);
            line2 = "";
        }
        if (i == line.length()) {
            vec.push_back(line2);
            line2 = "";
        }
    }
    return vec;
}
