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
#include "pprint.h"
#include "leetcode.h"
//#include <boost/describe.hpp>
//#include <boost/mp11.hpp>
//#include <boost/json.hpp>
//#include <boost/type_traits.hpp>
//#include <boost/utility/string_view.hpp>
using namespace std;
using namespace lc;

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

#define ice
#ifdef ice
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<vs> vss;
typedef pair<int, int> PII;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(a) int((a).size())
#define tr(c, i) for (typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define loop(i,a,b) for (int i = a; i <= b; i++)
#define loop2(x, n,step) for(int x = 0; x < n; x+=step)
constexpr int mod = 1e9 + 7;
template<class T> inline T lowbit(T n) { return (n ^ (n - 1)) & n; }  // 6(110)->2(10)
template<class T> inline int countbit(T n) { return (n == 0) ? 0 : (1 + countbit(n & (n - 1))); }//1 in binary represent

//use to print value,from https://stackoverflow.com/a/61925948/13792395
template<class T, class C = vector<T>, class P = less<typename C::value_type> >
struct heapq :std::priority_queue<T, C, P> {
  using priority_queue<T, C, P>::priority_queue;
  typename C::iterator begin() { return std::priority_queue<T, C, P>::c.begin(); }
  typename C::iterator end() { return std::priority_queue<T, C, P>::c.end(); }
};

template<typename T> void UN(T& n) { sort(all(n)); n.erase(std::unique(n.begin(), n.end()), n.end()); }
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>; //Small root heap. Default is big root heap.
const vector<vector<int>> dirs{ {0, 1},{-1, 0} , {0, -1}, {1, 0}, }; //{y,x}:right, down, left, up

//customize
#define psum(x,y)  partial_sum(all(x), y.begin());
#define D(x) cout << #x << " : " << x << endl;
#define ed cout << endl;
#define  sw cout<< l <<" "<<r<<endl; //sliding window 
#define rt  return res;
#endif
//#define D(x); 

typedef long long ll;
typedef vector<int> vi;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(a) int((a).size())
#define psum(x,y)  partial_sum(all(x), y.begin());
typedef vector<int> vi;
typedef vector<vi> vii;
//#define ed ;

class Solution {
  // your solution here...
};
