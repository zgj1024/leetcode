#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<int> a(n);
    int p = 1;
    for (int i = 1; i <= n; i++) {
      a[i] = i;
      p *= i;
    }

    p = p / n;
    int preP = 0;
    for (int i = 0; i < n; i++) {
      if (preP < k && k > p) {
        a.return getPermutation(int n, int k);
      }
    }

    return "";
  }

  string getPermutation(vector<class _Tp>)
};
int main(int argc, char *argv[]) {

  Solution s = Solution();

  cout << s.getPermutation(3, 3) << endl;

  return 0;
}
