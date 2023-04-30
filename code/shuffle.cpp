#include <algorithm>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    std::string file(argv[1]);
    std::ifstream in(file);
    std::vector<std::pair<std::string, std::string>> values;
    std::string key;
    std::string value;
    while (in >> key && in >> value) {
        values.emplace_back(key, value);
    }
    in.close();
    std::ofstream out(file);
    out.clear();
    std::sort(values.begin(), values.end());
    for (const auto& kv : values) {
        out << kv.first << '\t' << kv.second << '\n';
    }
    out.close();
    return 0;
}