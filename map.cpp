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
  std::cout << "\nhere\n";
//  for (auto i = 0; i < argc; ++i) {
//    std::cout << i << " : " << argv[i] << '\n';
//  }
  for (auto i = 2; i < argc; ++i) { // argc - 1
    // перенаправить вывод
    char* key = argv[i];
    char* value = new char();
    std::strcpy(value, ToText(argv[i]).c_str());
    char* command = new char();
    std::strcpy(command, argv[1]);
    std::strcat(command, " ");
    std::strcat(command, key);
    std::strcat(command, " ");
    std::strcat(command, value);
//    std::strcpy(command, " > ");
//    std::strcpy(command, argv[argc - 1]); // source file

    std::system(command); // space
    delete command;
    delete value;
  }
  exit(0);
  return 0;
}

