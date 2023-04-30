#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

int main(int argc, char *argv[]) {
    std::string command;
    if (std::strcmp(argv[1], "-map") == 0) {
        command = "./map ";
        for (auto i = 2; i < argc; ++i) {
            std::string filename(argv[i]);
            command.append(filename);
            command.append(" ");
        }
    } else {
        command = "./reduce ";
        std::string shuffle_command = "./shuffle ";
        shuffle_command.append(argv[3]);
        system(shuffle_command.c_str());
        std::string users_path(argv[2]);
        command.append(users_path).append(" ");
        command.append(argv[3]).append(" ").append(argv[4]);
    }
    std::system(command.c_str());
    return 0;
}
