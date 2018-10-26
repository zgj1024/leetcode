#include "../leetcode.cpp"

class Solution {
private:
  vector<vector<int>> s_;

public:
  int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size();
    if (n == 0)
      return 0;

    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j == 0 && i == 0)
          continue;
        else if (j == 0)
          grid[i][0] = grid[i][0] + grid[i - 1][0];
        else if (i == 0)
          grid[0][j] = grid[0][j] + grid[0][j - 1];
        else
          grid[i][j] = grid[i][j] + min(grid[i][j - 1], grid[i - 1][j]);
      }
    }
    return grid[n - 1][m - 1];
  }

  int minPathSum1(vector<vector<int>> &grid) {
    int n = grid.size();
    if (n == 0)
      return 0;

    int m = grid[0].size();

    s_ = vector<vector<int>>(n, vector<int>(m, -1));
    return minPathSum(grid, n - 1, m - 1);
  }

  int minPathSum(vector<vector<int>> &grid, int n, int m) {
    if (n == 0 && m == 0) {
      return grid[n][m];
    } else if (s_[n][m] != -1) {
      return s_[n][m];
    } else if (n == 0) {
      s_[n][m] = (grid[n][m] + minPathSum(grid, n, m - 1));
    } else if (m == 0) {
      s_[n][m] = (grid[n][m] + minPathSum(grid, n - 1, m));
    } else {
      s_[n][m] = grid[n][m] +
                 min(minPathSum(grid, n - 1, m), minPathSum(grid, n, m - 1));
    }
    return s_[n][m];
  }
};

int main(int argc, char *argv[]) {

  int a1[] = {1, 3, 1};
  vector<int> row1(a1, a1 + 3);

  int a2[] = {1, 5, 1};
  vector<int> row2(a2, a1 + 3);

  int a3[] = {4, 2, 1};
  vector<int> row3(a3, a3 + 3);

  vector<vector<int>> args(0);
  args.push_back(row1);
  args.push_back(row2);
  args.push_back(row3);

  Solution s = Solution();
  cout << s.minPathSum(args) << endl;

  int a4[] = {1, 2};
  int a5[] = {1, 1};

  vector<int> row4(a4, a4 + 2);
  vector<int> row5(a5, a5 + 2);

  vector<vector<int>> args1(0);
  args1.push_back(row4);
  args1.push_back(row5);
  cout << s.minPathSum(args1) << endl;

  return 0;
}
