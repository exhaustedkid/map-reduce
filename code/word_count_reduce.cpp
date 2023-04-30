#include <algorithm>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) { // argv[1] - key, ... - values
    std::cout << argv[1] << '\t';
    int count = 0;
    for (auto i = 2; i < argc; ++i) {
        std::string cur(argv[i]);
        count += std::stoi(cur);
    }
    std::cout << count << '\n';
    return 0;
}