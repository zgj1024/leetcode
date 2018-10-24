#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    if (n == 0) {
      return false;
    }
    int m = matrix[0].size();

    int low = 0, high = n * m - 1, mid;
    while (low <= high) {
      // mid = (low + high) / 2;
      // for stackoverflow problem
      mid = low + (high - low) / 2;
      int midValue = matrix[mid / m][mid % m];

      if (midValue == target) {
        return true;
      }
      if (midValue > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> v(0);
  int a1[] = {1, 3, 5, 7};
  int a2[] = {10, 11, 16, 20};
  int a3[] = {23, 30, 34, 50};

  vector<int> v1(a1, a1 + 4);
  vector<int> v2(a2, a2 + 4);
  vector<int> v3(a3, a3 + 4);

  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);

  Solution s = Solution();

  ASSERT_EQUAL(true, s.searchMatrix(v, 1), "");
  ASSERT_EQUAL(true, s.searchMatrix(v, 3), "");
  ASSERT_EQUAL(false, s.searchMatrix(v, 13), "");
  ASSERT_EQUAL(false, s.searchMatrix(v, 25), "");

  return 0;
}
