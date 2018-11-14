#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    if (n <= 0) {
      vector<TreeNode *> res;
      return res;
    }
    return generateTrees(1, n);
  }

private:
  vector<TreeNode *> generateTrees(int begin, int n) {
    vector<TreeNode *> trees;
    if (begin > n) {
      trees.push_back(NULL);
      return trees;
    }
    if (begin == n) {
      trees.push_back(new TreeNode(n));
      return trees;
    }
    for (int i = begin; i <= n; i++) {
      vector<TreeNode *> leftTrees = generateTrees(begin, i - 1);
      vector<TreeNode *> rightTrees = generateTrees(i + 1, n);
      for (auto &leftTree : leftTrees) {
        for (auto &rightTree : rightTrees) {
          TreeNode *root = new TreeNode(i);
          root->left = leftTree;
          root->right = rightTree;
          trees.push_back(root);
        }
      }
    }
    return trees;
  }
};

void displayTreeNode(TreeNode *node) {

  if (node == NULL) {
    cout << "null";
    return;
  }
  cout << "(";
  displayTreeNode(node->left);
  cout << "," << node->val << ",";
  displayTreeNode(node->right);
  cout << ")";
}

int main(int argc, char *argv[]) {
  Solution s = Solution();
  vector<TreeNode *> res = s.generateTrees(3);
  cout << "size:\t" << res.size() << endl;
  for (TreeNode *node : res) {
    displayTreeNode(node);
    cout << endl;
  }
  return 0;
}
