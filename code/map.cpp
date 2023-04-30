#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

std::string ToText(const std::string& filename) {
    std::ifstream in(filename);
    std::string output;
    // if !in.is_open()
    std::string tmp;
    while (getline(in, tmp)) {
        output += tmp;
    }
    in.close();
    return output;
}

int main(int argc, char* argv[]) { // argv[0] - map.exe, argv[1] - path to map, others - filenames, last - file_to write
    std::ofstream out(argv[argc - 1]);
    out.clear();
    for (auto i = 2; i < argc - 1; ++i) { // argc - 1
        std::string key(argv[i]);
        std::string value = ToText(argv[i]);
        std::string command(argv[1]);
        command.append(" ");
        command.append(key);
        command.append(" ");
        command.append(value);
        std::string writefile(argv[argc - 1]);
        command.append(" >> ");
        command.append(writefile);
        std::system(command.c_str());
    }
    return 0;
}
