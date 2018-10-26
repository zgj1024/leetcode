#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0) {
      return 0;
    }
    int n = obstacleGrid[0].size();
    if (n == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
      return 0;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {

        if (i == 0 && j == 0)
          a[0][0] = 1;
        else if (obstacleGrid[i][j] == 1)
          continue;
        else if (i == 0)
          a[0][j] += a[0][j - 1];
        else if (j == 0)
          a[i][0] += a[i - 1][0];
        else
          a[i][j] += a[i][j - 1] + a[i - 1][j];
      }
    }
    return a[m - 1][n - 1];
  }
};
int main(int argc, char *argv[]) {
  int a[][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  vector<int> v1(a[0], a[0] + 3);
  vector<int> v2(a[1], a[1] + 3);
  vector<int> v3(a[2], a[2] + 3);
  vector<vector<int>> v(0);
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);

  //  cout << v << endl;
  Solution s = Solution();
  ASSERT_EQUAL(2, s.uniquePathsWithObstacles(v), "");
  report();
  return 0;
}
