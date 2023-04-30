#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

std::vector<std::pair<std::string, int>> MapWordCount(const std::string& filename, const std::string& value) {
  std::vector<std::pair<std::string, int>> output;
  for (auto i = 0; i < value.size();) {
    while (i < value.size() && std::isspace(value[i])) {
      ++i;
    }
    int word_beg = i;
    while (i < value.size() && !std::isspace(value[i])) {
      ++i;
    }
    int word_end = i;
    output.emplace_back(value.substr(word_beg, word_end - word_beg), 1);
  }
  return output;
}

//std::vector<std::pair<std::string, std::vector<int>>> Shuffle(const std::vector<std::pair<std::string, int>>& values) {
//  std::vector<std::pair<std::string, std::vector<int>>> shuffled;
//  for (const auto& value: values) {
//    auto pos = std::find(shuffled.begin(), shuffled.end(), value.first);
//    if (pos == shuffled.end()) {
//      shuffled.emplace_back(value.first, value.second);
//    } else {
//      pos->second.push_back(value.second);
//    }
//  }
//  return shuffled;
//}

void Shuffle(std::vector<std::pair<std::string, int>>& values) {
  std::sort(values.begin(), values.end());
}

std::pair<std::string, int> ReduceWordCount(const std::vector<std::pair<std::string, int>>& values) {
  int count = 0;
  std::string word = values[0].first;
  for (const auto& value: values) {
    count += value.second;
  }
  return std::make_pair(word, count);
}

class WordCountMapReducer {
 public:
  static void MapReduce(const std::vector<std::string>& filenames) {
    std::vector<std::pair<std::string, int>> values;
    for (const auto& filename: filenames) {
      std::vector<std::pair<std::string, int>> tmp_values = MapWordCount(filename, ToText(filename));
      values.insert(values.end(), tmp_values.begin(), tmp_values.end());
    }
    Shuffle(values);
    for (auto i = 0; i < values.size(); ++i) {
      int l_beg = i;
      while(i < values.size() && values[i].first == values[i + 1].first) {
        ++i;
      }
      std::vector<std::pair<std::string, int>> key(values.begin() + l_beg, values.begin() + i + 1); // why + 1??
      auto processed = ReduceWordCount(key);
      std::cout << processed.first << ' ' << processed.second << '\n';
    }

  }

 private:
  static std::string ToText(const std::string& filename) {
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

};




int main() {
  std::vector<std::pair<std::string, int>> avto;
  MapWordCount("aa", "bus car bus car train car bus car train bus");
//
  std::vector<std::string> v = {"in1.txt", "in2.txt", "in3.txt"};
  WordCountMapReducer::MapReduce(v);


  return 0;
}
