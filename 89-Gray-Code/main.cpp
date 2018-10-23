#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> ret(0);
    for (int i = 0; i < (1 << n); i++) {
      ret.push_back(i ^ (i >> 2));
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s = Solution();
  vector<int> ret = s.grayCode(2);
  cout << ret << endl;
  return 0;
}
