//main.cpp : Defines the entry point for the application.
#include<vector>
#include<string>
#include<map>
#include<algorithm>	
#include <unordered_map>
#include<bitset>
#include<fstream>
#include<numeric>
#include<set>
#include<queue>
#include<functional>
#include<iomanip>
#include<variant>
#include<cassert>
#include<memory>
#include<iostream>
#include<cctype>
#include "pprint.h"
#include "Solution.h"
#include"leetcode.h"
using namespace std;
using namespace lc;
auto string_to_char(vector<string>& t1)
{
  vector<vector<char>> t;
  for (auto i : t1)
  {
    t.push_back(vector<char>());
    for (auto j : i)
      t.back().push_back(j);
  }
  return t;
}

int main()
{
  std::string filename = "in.txt";
  std::ifstream file(filename); //默认的不是这个位置吗？
    if (!file.is_open()) {
    std::cout << "failed to open ,Please create `in.txt` in the current directory as the input file" << filename << '\n';
    return 0;
  }
  std::string in;
  std::getline(file, in);
  auto res = Tree(in);
  res.print();
  //your solution here...
  
  return 0;
}
