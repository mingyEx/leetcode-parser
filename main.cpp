// leetcode-parser.cpp : Defines the entry point for the application.
//

#include<vector>
#include<string>
#include<map>
#include<algorithm>	
#include <unordered_map>
#include<iostream>
#include<bitset>
#include<algorithm>
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
auto stc(vector<string>& t1)
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
  std::ifstream file("in.txt");
  std::string in;
  std::getline(file, in);
  auto res = lc::VecStr(in);  //还是不行.
  for (auto i : res)cout << i << " ";
  return 0;
}
//你可能会发现它很有用

