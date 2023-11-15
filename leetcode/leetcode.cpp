#include "leetcode.h"
using namespace std;
using namespace lc;

lc::List::List(const std::string& inputStr)
{
  auto vec = Vec<int>(inputStr);
  size_t count = vec.size();
  ListNode* curr;
  head = new ListNode(vec[0]);
  curr = head;
  for (size_t i = 1; i < count; i++) {
    ListNode* temp = new ListNode(vec[i]);
    curr->next = temp;
    curr = temp;
  }
}
lc::List::~List()
{
  ListNode* curr = head;
  ListNode* temp = nullptr;
  while (curr != nullptr) {
    temp = curr;
    curr = curr->next;
    delete temp;
  }
}
void lc::List::print()
{
  auto ptr = head;
  while (ptr) {
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

//Level Order Traversal => tree
lc::Tree::Tree(const std::string& input)
{
  vector<int> vec = Vec<int>(input);
  size_t count = vec.size();
  vector<TreeNode*>treeArr(count);
  for (size_t i = 0; i < count; i++)
  {
    if (TREE_NODE_BOUNDNARY == vec[i]) {
      treeArr[i] = nullptr;
    }
    else {
      treeArr[i] = new TreeNode(vec[i]);	//Assign
    }
  }
  size_t curr = 1;
  for (size_t i = 0; i < count; i++)
  {
    if (!treeArr[i]) {
      continue;
    }
    if (curr < count) {
      treeArr[i]->left = treeArr[curr++];
    }
    if (curr < count) {
      treeArr[i]->right = treeArr[curr++];
    }
  }
  root = treeArr[0];
}
lc::Tree::~Tree()
{
  if (!root)return;
  delete root;
}
void lc::Tree::print_Impl(TreeNode* n, bool left, std::string const& indent)
{
  if (n->right) print_Impl(n->right, false, indent + (left ? "|     " : "      "));
  std::cout << indent;
  std::cout << (left ? '\\' : '/');
  std::cout << "-----";
  std::cout << n->val << std::endl;
  if (n->left) print_Impl(n->left, true, indent + (left ? "      " : "|     "));
}
void lc::Tree::print()
{
  if (!root)return;
  if (root->right) print_Impl(root->right, false, " ");
  std::cout << root->val << '\n';
  if (root->left) print_Impl(root->left, true, " ");
}
void lc::print(TreeNode* p)
{
    lc::Tree(p).print();
}
void lc::print(ListNode* p)
{
  List(p).print();
}
