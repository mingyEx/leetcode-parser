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
#include<xutility>
#include<queue>
#include<cassert>
#include<functional>
#include<cctype>
#include<iomanip>
#include<bit>
#include<tuple>
#include <random>
#include <algorithm>
#include<stack>
#include<array>
#include<sstream>
using namespace std;
using std::string;
using std::vector;
using std::priority_queue;
using std::function;

//Compared to pprint.h
//advantage : you can put multiple objects in one `debug()`,ie,debug(a,b,c).
//disadvantage :Poor readability, not as good as trace.h

//From https://github.com/goodStudyTnT/library/blob/master/copypaste/debug.h

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string)s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

//from https://github.com/ftiasch/shoka/blob/master/debug.h#L32
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename... T>
string to_string(const tuple<T...>& t) {
  stringstream ss;
  ss << '(';
  std::apply(
    [&ss](const T &...args) {
      int index = 0;
      ((ss << to_string(args) << (++index != sizeof...(T) ? ", " : "")), ...);
    },
    t);
  ss << ")";
  return ss.str();
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug_out() {
  cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main()
{
  tuple<int, int, int>sc = { 1,2,3}; //error!
  tuple<int, int, int, int, int, int, int>sd = { 1,2,3,2,3,2,3 }; //error!
  debug (sc);
  debug(sd);
}
