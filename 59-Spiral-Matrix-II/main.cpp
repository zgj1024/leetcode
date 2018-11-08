#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;

    vector<vector<int>> res(n, vector<int>(n, 0));
    int v = 1;
    while (rowStart <= rowEnd && colStart <= colEnd) {
      for (int i = colStart; i <= colEnd; i++) {
        res[rowStart][i] = v;
        v++;
      }
      rowStart++;

      //      cout << res << endl;
      for (int i = rowStart; i <= rowEnd; i++) {
        res[i][colEnd] = v;
        v++;
      }

      colEnd--;
      //      cout << res << endl;

      if (rowStart <= rowEnd) {
        for (int i = colEnd; i >= colStart; i--) {
          res[rowEnd][i] = v;
          v++;
        }
        rowEnd--;
      }

      if (colStart <= colEnd) {
        for (int i = rowEnd; i >= rowStart; i--) {
          res[i][colStart] = v;
          v++;
        }
        colStart++;
      }
    }
    return res;
  }
};
int main(int argc, char *argv[]) {
  Solution s = Solution();
  cout << s.generateMatrix(3) << endl;
  return 0;
}
