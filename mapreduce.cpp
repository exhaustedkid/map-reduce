#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[]) {
//  char* name = new char();
//  if (std::strcmp(argv[1], "map") == 0) {
////    std::strcpy(name, R"(C:\Users\saven\CLionProjects\mapreduce\map\map.exe )");
//    std::strcpy(name, "map.exe ");
//  } else {
//    std::strcpy(name, "reduce.exe ");
//  }
//  for (auto i = 2; i < argc; ++i) {
//    std::strcat(name, argv[i]);
//    std::strcat(name, " ");
//  }
//  std::cout << name << '\n';
//  std::system(name);
  std::system("map.exe word_count_map.exe in1.txt");
//  delete name;
//  exit(0);
  return 0;
}

