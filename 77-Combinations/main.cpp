#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res(0);
    if (k <= 0 && k > n)
      return res;

    vector<int> a(0);
    combine(n, k, 1, a, res);
    return res;
  }
  void combine(int n, int k, int start, vector<int> comb,
               vector<vector<int>> &res) {
    if (k == 0) {
      res.push_back(comb);
      return;
    }
    for (int i = start; i <= n; i++) {
      comb.push_back(i);
      combine(n, k - 1, i + 1, comb, res);
      comb.pop_back();
    }
  }
};

int main(int argc, char *argv[]) {

  Solution s = Solution();
  vector<vector<int>> res = s.combine(4, 2);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}
