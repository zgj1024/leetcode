#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {

public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return vector<int>(0);
    int m = matrix.size();
    int n = matrix[0].size();
    int size = n * m;

    vector<int> ret(size);
    int index = 0;

    int rowStart = 0, rowEnd = m - 1, colStart = 0, colEnd = n - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
      // right
      for (int i = colStart; i <= colEnd; i++, index++) {
        ret[index] = matrix[rowStart][i];
      }
      rowStart++;
      // down
      for (int i = rowStart; i <= rowEnd; i++, index++) {
        ret[index] = matrix[i][colEnd];
      }
      colEnd--;

      // left
      if (rowStart <= rowEnd) {
        for (int i = colEnd; i >= colStart; i--, index++) {
          ret[index] = matrix[rowEnd][i];
        }
        rowEnd--;
      }
      // up
      if (colStart <= colEnd) {
        for (int i = rowEnd; i >= rowStart; i--, index++) {
          ret[index] = matrix[i][colStart];
        }
        colStart++;
      }
    }
    return ret;
  }
};
int main(int argc, char *argv[]) {

  int a_1[3] = {1, 2, 3};
  int a_2[3] = {4, 5, 6};
  int a_3[4] = {7, 8, 9};
  vector<int> v1(a_1, a_1 + 3);
  vector<int> v2(a_2, a_2 + 3);
  vector<int> v3(a_3, a_3 + 3);

  vector<vector<int>> v(0);
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);

  Solution s = Solution();
  cout << s.spiralOrder(v) << endl;
  //  report();
  return 0;
}
