#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res(0);
    vector<int> tmp(0);
    subsetsWithDup(res, nums, tmp, 0);
    return res;
  }

  void subsetsWithDup(vector<vector<int>> &res, vector<int> nums,
                      vector<int> tmp, int pos) {
    res.push_back(tmp);
    for (int i = pos; i < nums.size(); i++) {
      if (i > pos && nums[i] == nums[i - 1]) {
        continue;
      }
      vector<int> copyTmp = tmp;
      copyTmp.push_back(nums[i]);
      //      cout << i << "\t" << copyTmp << endl;
      subsetsWithDup(res, nums, copyTmp, i + 1);
    }
  }
};

int main(int argc, char *argv[]) {
  int a[] = {2, 1, 2};
  vector<int> nums(a, a + 3);

  // cout << nums << endl;

  Solution s = Solution();
  vector<vector<int>> res = s.subsetsWithDup(nums);

  cout << res << endl;
  //  report();
  return 0;
}
