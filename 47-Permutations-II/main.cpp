#include "../leetcode.cpp"
#include <algorithm>

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ret(0);
    if (nums.size() == 0) {
      return ret;
    }
    sort(nums.begin(), nums.end());
    permuteUniqueHelper(ret, nums, 0);
    return ret;
  }

  void permuteUniqueHelper(vector<vector<int>> &ret, vector<int> nums,
                           int pos) {
    if (pos == nums.size()) {
      ret.push_back(nums);
      return;
    }
    for (int i = pos; i < nums.size(); i++) {
      int k = 1;
      if (i != pos && nums[i] == nums[pos]) {
        k++;
        continue;
      }
      swap(nums[i], nums[pos]);
      cout << nums << ":" << pos << endl;
      permuteUniqueHelper(ret, nums, pos + k);
    }
  }
};

int main(int argc, char *argv[]) {
  int a[] = {1, 2, 2};
  vector<int> v1(a, a + 3);

  Solution s = Solution();
  vector<vector<int>> r1 = s.permuteUnique(v1);
  cout << r1 << endl;
  return 0;
}
