#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    if (n < 2)
      return 0;

    int count = 0;
    int current_max = 0;
    int next_max = 0;
    int i = 0;

    while (i < n) {
      count++;
      for (; i <= current_max; i++) {
        next_max = max(next_max, nums[i] + i);
        if (next_max >= n - 1) {
          return count;
        }
      }
      current_max = next_max;
    }

    return count;
  }
};

int main(int argc, char *argv[]) {

  Solution s = Solution();

  vector<int> v1(0);
  ASSERT_EQUAL(0, s.jump(v1), "[]");

  int a2[5] = {2, 3, 1, 1, 4};
  vector<int> v2(a2, a2 + 5);
  ASSERT_EQUAL(2, s.jump(v2), "[2,3,1,1,4]");

  int a3[5] = {2};
  vector<int> v3(a3, a3 + 1);
  ASSERT_EQUAL(0, s.jump(v3), "[2]");
  report();
  return 0;
}
