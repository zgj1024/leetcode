#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    if (nums.size() == 0)
      return result;
    permute_helper(result, nums, 0);
    return result;
  }

  void permute_helper(vector<vector<int>> &result, vector<int> nums, int pos) {
    if (pos == nums.size()) {
      result.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); i++) {
      swap(nums[i], nums[pos]);
      permute_helper(result, nums, pos + 1);
    }
  }
};

int main(int argc, char *argv[]) {
  int a1[] = {1, 2, 3};
  vector<int> v1(a1, a1 + 3);

  vector<vector<int>> expect_result(0);
  int ra1[] = {1, 2, 3};
  int ra2[] = {1, 3, 2};
  int ra3[] = {2, 1, 3};
  int ra4[] = {2, 3, 1};
  int ra5[] = {3, 1, 2};
  int ra6[] = {3, 2, 1};

  vector<int> rv1(ra1, ra1 + 3);
  vector<int> rv2(ra2, ra2 + 3);
  vector<int> rv3(ra3, ra3 + 3);
  vector<int> rv4(ra4, ra4 + 3);
  vector<int> rv5(ra5, ra5 + 3);
  vector<int> rv6(ra6, ra6 + 3);

  expect_result.push_back(rv1);
  expect_result.push_back(rv2);
  expect_result.push_back(rv3);
  expect_result.push_back(rv4);
  expect_result.push_back(rv5);
  expect_result.push_back(rv6);

  Solution s = Solution();
  vector<vector<int>> actual_result = s.permute(v1);

  cout << actual << endl;
  cout << expect_result << endl;

  return 0;
}
