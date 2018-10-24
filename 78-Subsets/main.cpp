#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res(0);
    vector<int> tmp(0);
    subset(res, nums, tmp, 0);
    return res;
  }

  void subset(vector<vector<int>> &res, vector<int> nums, vector<int> tmp,
              int pos) {
    res.push_back(tmp);
    for (int i = pos; i < nums.size(); i++) {
      vector<int> newTmp = tmp;
      newTmp.push_back(nums[i]);
      subset(res, nums, newTmp, i + 1);
    }
  }
};
int main(int argc, char *argv[]) {

  int a[] = {1, 2, 3};
  vector<int> nums(a, a + 3);
  Solution s = Solution();
  vector<vector<int>> res = s.subsets(nums);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }

  //  report();
  return 0;
}
