#include <iostream>
#include <fstream>
#include <vector>


int main(int argc, char *argv[]) { // argv[0] - reduce, argv[1] - word_count_reduce, argv[2] - file from, argv[3] - file to
    std::string file(argv[2]);
    std::ifstream in(file);
    std::string prev_key;
    in >> prev_key;
    std::string prev_value;
    in >> prev_value;
    std::vector<std::string> values;
    values.push_back(prev_value);
    std::string key;
    std::string value;
    std::string file_to_write(argv[3]);
    std::ofstream out(file_to_write);
    out.clear();
    bool pair_added = false;
    while (in >> key && in >> value) {
        if (key != prev_key) {
            std::string command(argv[1]);
            command.append(" ");
            command.append(prev_key);
            for (const auto &this_value: values) {
                command.append(" ");
                command.append(this_value);
            }
            command.append(" >> ");
            command.append(file_to_write);
            system(command.c_str());
            values.clear();
            prev_key = key;
            prev_value = value;
            values.push_back(value);
            pair_added = true;
        } else {
            values.push_back(value);
            pair_added = false;
        }
    }
    if (pair_added) {
        std::string command(argv[1]);
        command.append(" ");
        command.append(key);
        for (const auto &this_value: values) {
            command.append(" ");
            command.append(this_value);
        }
        command.append(" >> ");
        command.append(file_to_write);
        system(command.c_str());
    }
    in.close();
}