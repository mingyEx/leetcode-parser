#ifndef LC
#define LC
#include "pprint.h"
#include<iostream>
#include<regex>
#include<sstream>
#include<string>
#include<type_traits>
#include <climits>
using std::cout;
using std::endl;
using std::vector;
using std::string;
namespace lc
{
  struct ListNode
  {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next_) : val(x), next{ next_ } {}
  };
  class List
  {
    ListNode* head;
    ListNode* copy(ListNode* p)
    {
      if (!p)return nullptr;
      ListNode* r = new ListNode(p->val);
      r->next = copy(p->next);
      return r;
    }
  public:
    List(const std::string& inputStr);
    List(ListNode* p) { head = copy(p); };
    ~List();
    void print();
    auto get() { return head; }
  };

  const int32_t TREE_NODE_BOUNDNARY = INT_MIN + 1; // replace null
  struct TreeNode
  {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    ~TreeNode() {
      delete left;
      delete right;
    }
  };

  //template for int and long long

//for int and long long
  template<typename T>
  std::vector<T> Vec(const std::string inputStr)
  {
    std::vector<T> ret;
    const std::string pattern = R"(([+|-]?\w*\.?[\w+|#|(|)|\.]),?)";
    std::smatch match;
    std::string log = inputStr;
    while (regex_search(log, match, (std::regex)pattern)) {
      std::stringstream ss;
      std::string treeNull = match.str(1) == "null" ? std::to_string(TREE_NODE_BOUNDNARY) : match.str(1);
      ss << treeNull;
      T temp;
      ss >> temp;
      ret.push_back(temp);
      log = match.suffix();
    }
    if (ret.empty())
      std::cout << "Construct Vector failed" << std::endl;
    return ret;
  }
  template<typename T>
  std::vector<std::vector<T>> Vec2(const std::string inputStr)
  {
    std::vector<std::vector<T>> ret;
    const std::string pattern = R"((\[[^\[\]]*\]))";
    std::smatch match;
    std::string log = inputStr;
    while (regex_search(log, match, (std::regex)pattern)) {
      const std::string vec = match.str(1);
      ret.push_back(Vec<int>(vec));
      log = match.suffix();
    }
    if (ret.empty()) { 
      ret = {};
      std::cout << "Construct vector<vector<int>>failed" <<std::endl; }
    return ret;
  }

  //string from:https://leetcode.cn/playground/new/empty/
  inline vector<string> VecStr(const string input) {
    if (input.size() < 2) {
      std::cout << "Construct vector<string> failed" << std::endl;
      return{};
    }
    vector<string> res;
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
      char currentChar = input[i];
      if (input[i] == '\\') {
        char nextChar = input[i + 1];
        switch (nextChar) {
        case '\"': result.push_back('\"'); break;
        case '/': result.push_back('/'); break;
        case '\\': result.push_back('\\'); break;
        case 'b': result.push_back('\b'); break;
        case 'f': result.push_back('\f'); break;
        case 'r': result.push_back('\r'); break;
        case 'n': result.push_back('\n'); break;
        case 't': result.push_back('\t'); break;
        default: break;
        }
        i++;
      }
      else {
        result.push_back(currentChar);
      }
      if (input[i] == ',')
      {
        result.pop_back();
        result.pop_back();
        res.push_back(result.substr(1));
        result = "";
      }
    }
    if (!result.empty()) {
      result.pop_back();
      res.push_back(result.substr(1));
    }
    return res;
  }
  inline std::vector<std::vector<string>> Vec2Str(const std::string inputStr)
  {
    std::vector<std::vector<string>> ret;
    const std::string pattern = R"((\[[^\[\]]*\]))";
    std::smatch match;
    std::string log = inputStr;
    while (regex_search(log, match, (std::regex)pattern)) {
      const std::string vec = match.str(1);
      ret.push_back(VecStr(vec));
      log = match.suffix();
    }
    if (ret.empty()) std::cout << "Construct vector<vector<string>> failed" << std::endl;
    return ret;
  }

  template<>
  inline std::vector<string> Vec(const std::string inputStr) {
    return VecStr(inputStr);
  }
  template<>
  inline std::vector<std::vector<string>> Vec2(const std::string inputStr)
  {
    return Vec2Str(inputStr);
  }

  class Tree
  {
  private:
    TreeNode* root;
    void print_Impl(TreeNode* n, bool left, std::string const& indent);
    TreeNode* copyTree(TreeNode* p)
    {
      if (!p)return nullptr;
      auto r = new TreeNode(p->val);
      r->left = copyTree(p->left);
      r->right = copyTree(p->right);
      return r;
    }
  public:
    Tree(const std::string& input);
    Tree(TreeNode* p) { root = copyTree(p); }
    ~Tree();
    TreeNode* get() { return root; }
    void print();
  };
  void print(TreeNode* p);
  void print(ListNode* p);
}
#endif
