#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

int main(int argc, char *argv[]) {
    for (auto i = 2; i < argc; ++i) {
        std::cout << argv[i] << '\t' << 1 << '\n';
    }
    return 0;
}