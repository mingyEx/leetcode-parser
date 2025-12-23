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
#include "lc.h"
//#include"trace.h"
using namespace std;
using namespace lc;
using std::string;
using std::vector;
using std::priority_queue;
using std::function;

//cui begin
#define LOCAL
template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0; } out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto v : a) { out << (first ? "" : ", "); out << v; first = 0; } out << "]";
  return out;
}
//Append a newline character to the end of each row when outputting a two-dimensional array.
template <typename U>
std::ostream& operator <<(std::ostream& out, const std::vector<std::vector<U>>& a) {
  out << "{";
  bool first_outer = true;
  for (int i = 0; i < a.size(); ++i)
  {
    auto inner_vec = a[i];
    out << (first_outer ? "" : " ");
    out << inner_vec;    //call vector<T>
    if (i != a.size() - 1) out << "\n";
    first_outer = false;
  }
  out << "}";
  return out;
}

template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0; } out << "}";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const multiset<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0; } out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0; } out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const unordered_map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0; } out << "}";
  return out;
}
template <typename... T>
ostream& operator<<(ostream& out, const tuple<T...>& t) {
  out << '(';
  std::apply(
    [&out](const T &...args) {
      int index = 0;
      ((out << args << (++index != sizeof...(T) ? ", " : "")), ...);
    },
    t);
  return out << ')';
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

#ifdef LOCAL
#define D(...) __f(#__VA_ARGS__, __VA_ARGS__);
#else
#define D(...) 42
#endif
//cui end

#ifdef math
const double pi = acos(-1.0);//NOTES:pi 
const double eps = 1e-11;//NOTES:eps
//数学函数
//形式为:因子和其次数的pair
template<class T> inline vector<pair<T, int>> factorize(T n)
{
  vector<pair<T, int> > R;
  for (T i = 2; n > 1;) {
    if (n % i == 0)
    {
      int C = 0;
      for (; n % i == 0; C++, n /= i)
        R.push_back(make_pair(i, C));
    }
    i++;
    if (i > n / i)
      i = n;
  }
  if (n > 1)R.push_back(make_pair(n, 1));
  return R;
}
//依次除以[2,sqrt(n)]，因为2先被除以，所以此区间里valid的都是质因数.
//上文的原理跟这个一样.

template<class T> inline bool isPrimeNumber(T n)
{
  if (n <= 1)return false;
  for (T i = 2; i * i <= n; i++)if (n % i == 0) return false; return true;
}
//几何
template<class T> inline T sqr(T x) { return x * x; }//NOTES:sqr
double dist(double x1, double y1, double x2, double y2) { return sqrt(sqr(x1 - x2) + sqr(y1 - y2)); }//两点距离
template<class T> T cross(T x0, T y0, T x1, T y1, T x2, T y2)//x1y2-x2y1 叉积
{
  return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
//在左则1,否则-1.
int crossOper(double x0, double y0, double x1, double y1, double x2, double y2)
{
  double t = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
  if (fabs(t) <= eps) return 0;
  return (t < 0) ? -1 : 1;
}
//line segments intersect
bool isIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
  return crossOper(x1, y1, x2, y2, x3, y3) * crossOper(x1, y1, x2, y2, x4, y4) < 0 && crossOper(x3, y3, x4, y4, x1, y1) * crossOper(x3, y3, x4, y4, x2, y2) < 0;
}
#endif
//不常用
#define spice
#ifdef spice
template<class T> inline T lowbit(T n) { return (n ^ (n - 1)) & n; }  // 6(110)->2(10
template <class T, class S, class C>
S& Container(priority_queue<T, S, C>& q) {
  struct HackedQueue : private priority_queue<T, S, C> {
    static S& Container(priority_queue<T, S, C>& q) {
      return q.* & HackedQueue::c;;
    }
  };
  return HackedQueue::Container(q);
}
template<typename T>
vector<T> print(priority_queue<T> pq) {
  auto res = Container(pq);
  return res;
}
template<typename T> void UN(T& n) { sort(all(n)); n.erase(std::unique(n.begin(), n.end()), n.end()); }
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>; //Small root heap. Default is big root heap.
const vector<vector<int>> d4{ {0, 1}, { -1, 0 }, { 0, -1 }, { 1, 0 }, }; //{y,x}:right, down, left, up
const int d8[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };

//#define D(x) cout << #x << " : " << x << "\n";
#endif

///常用

//#define D(x); 
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
using vss = vector<vs>;
using ii = pair<int, int>;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()   
#define sz(a) int((a).size())   
#define psum(x,y)  partial_sum(all(x), y.begin());
#define ext(container, element)(container.find(element) != container.end())
#define cext(container, element)(find(all(container), element) != container.end())
#define loop(i,a,b) for (int i = a; i < b; i++)
#define loop2(x, n,step) for(int x = 0; x < n; x+=step)
#define rt  return res;
#define ed cout<<'\n';
#define D2(x) cout <<  x << endl;
constexpr int MOD = 1e9 + 9;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;

inline void add_mod(int& x, int y) { x += y; if (x >= MOD) x -= MOD; }
inline void sub_mod(int& x, int y) { x += MOD - y; if (x >= MOD) x -= MOD; }
inline int mod(int x) { return x >= MOD ? x - MOD : x; }
template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
//usage:
// if(a[i] < currMin){ currMin = a[i]; ans++; }
// equal to :if (ckmin(currMin, a[i])) ans++;
//1:0 is return value for the if,
//ps:这帮人真是一行代码也舍不得多写啊.
template <class T> auto vect(const T& v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
  return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}

