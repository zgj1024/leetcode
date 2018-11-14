#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
class Solution {
public:
  int numTrees(int n) {
    if (n == 0 || n == 1)
      return 1;

    int *nums = new int[n + 1];
    for (int i = 0; i <= n; i++) {
      nums[i] = 0;
    }

    nums[0] = 1;
    nums[1] = 1;

    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        nums[i] += (nums[i - j - 1] * nums[j]);
      }
    }
    int res = nums[n];
    delete[] nums;
    return res;
  }
};
// int numTrees(int n) {
//     long C = 1;
//     for(int i = 0; i < n; ++i) {
//         C = C * 2 * (2 * i + 1) / (i + 2);
//     }
//     return (int) C;
// }
int main(int argc, char *argv[]) {
  Solution s = Solution();
  ASSERT_EQUAL(5, s.numTrees(3), "");
  report();
  return 0;
}
