#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

// class Solution {
// public:
//   bool isValidBST(TreeNode *root) { return isValidBST(root, nullptr,
//   nullptr); }

// private:
//   bool isValidBST(TreeNode *root, int *min, int *max) {
//     if (!root)
//       return true;
//     if (min && root->val <= *min)
//       return false;

//     if (max && root->val >= *max)
//       return false;

//     return isValidBST(root->left, min, &root->val) &&
//            isValidBST(root->right, &root->val, max);
//   }
// };

class Solution {
private:
  TreeNode *pre;

public:
  bool isValidBST(TreeNode *root) {
    if (!root)
      return true;
    bool isLeftOK = isValidBST(root->left);
    if (pre && root->val <= pre->val)
      return false;

    pre = root;

    bool isRightOK = isValidBST(root->right);
    return isLeftOK && isRightOK;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *n1 = new TreeNode(2);
  n1->left = new TreeNode(1);
  n1->right = new TreeNode(3);

  Solution s = Solution();
  ASSERT_EQUAL(true, s.isValidBST(n1), "(2 1 3)");

  //(5 1 (4 3 6))
  TreeNode *n2 = new TreeNode(5);
  n2->left = new TreeNode(1);

  TreeNode *n2_r = new TreeNode(4);
  n2_r->left = new TreeNode(3);
  n2_r->right = new TreeNode(6);

  n2->right = n2_r;

  ASSERT_EQUAL(false, s.isValidBST(n2), "(5 1 (4 3 6))");

  //(10 5 (15 6 20))
  TreeNode *n3 = new TreeNode(10);
  n3->left = new TreeNode(5);

  TreeNode *n3_r = new TreeNode(15);
  n3_r->left = new TreeNode(6);
  n3_r->right = new TreeNode(20);

  n3->right = n3_r;
  ASSERT_EQUAL(false, s.isValidBST(n3), "(10 5  (15 6 20))");

  report();
  return 0;
}
