#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int size = nums.size();
    int m = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > m)
        return false;
      m = max(i + nums[i], m);
    }
    return true;
  }
};

int main(int argc, char *argv[]) {

  Solution s = Solution();
  int a[5] = {2, 3, 1, 1, 4};
  vector<int> v(a, a + 5);
  cout << s.canJump(v) << endl;

  int a1[5] = {3, 2, 1, 0, 4};
  vector<int> v1(a1, a1 + 5);
  cout << s.canJump(v1) << endl;
  return 0;
}
