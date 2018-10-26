#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

/* sicp 换零钱 */
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> a(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0)
          a[0][0] = 1;
        else if (i == 0)
          a[0][j] += a[0][j - 1];
        else if (j == 0)
          a[i][0] = a[i - 1][0];
        else
          a[i][j] = a[i - 1][j] + a[i][j - 1];
      }
    }
    return a[m - 1][n - 1];
  }
};

int main(int argc, char *argv[]) {
  Solution s = Solution();
  ASSERT_EQUAL(3, s.uniquePaths(3, 2), "3x2");
  ASSERT_EQUAL(28, s.uniquePaths(7, 3), "7x3");
  report();
  return 0;
}
