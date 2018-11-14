#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res(0);
    inorderTraversal(root, res);
    return res;
  }

private:
  void inorderTraversal(TreeNode *root, vector<int> &res) {
    if (root == NULL) {
      return;
    }
    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
  }
};
int main(int argc, char *argv[]) {
  Solution s = Solution();

  TreeNode *node = new TreeNode(1);
  TreeNode *right = new TreeNode(2);
  right->left = new TreeNode(3);

  node->right = right;

  vector<int> res = s.inorderTraversal(node);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}
