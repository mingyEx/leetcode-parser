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

//[[],[],[]] -> _,_ \n -,_\n ,
auto graph_data(vector<vector<int>> edges)
{
  string r;
  for (auto i : edges) {
    r = r + to_string(i[0]) + "," + to_string(i[1]);
    r.push_back('\n');
  }
  return r;
}

int main(int argc, char* argv[])
{
  std::ifstream file("in.txt");
  std::string in;
  std::getline(file, in);
  int caseN = 0;
  while (file.peek() != EOF)
  {
    cout << "case " << caseN << ":"<<endl;
    std::getline(file, in);
    auto t1 = Vec<int>(in);
    //cout << Solution().swapNodes(t1.get(), 2) << endl;
  }
  return 0;
}
