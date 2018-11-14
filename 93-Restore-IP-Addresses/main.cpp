#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res(0);
    restoreIpAddresses(s, 0, s.length(), 0, "", res);
    return res;
  }

  void restoreIpAddresses(string s, int i, int n, int count, string str,
                          vector<string> &res) {

    if (count == 4 && i != n)
      return;
    if (count == 4 && i == n) {
      res.push_back(str);
      return;
    }
    if (s[i] == '0') {
      if (count == 3) {
        restoreIpAddresses(s, i + 1, n, count + 1, str + "0", res);
      } else {
        restoreIpAddresses(s, i + 1, n, count + 1, str + "0.", res);
      }
      return;
    }
    int num = 0;
    for (int k = 0; k < 3 && i + k < n; k++) {
      num = num * 10 + s[i + k] - '0';
      if (num < 256) {
        str = str + s[i + k];

        if (count == 3) {
          restoreIpAddresses(s, i + k + 1, n, count + 1, str, res);

        } else {
          restoreIpAddresses(s, i + k + 1, n, count + 1, str + ".", res);
        }
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s = Solution();
  vector<string> res = s.restoreIpAddresses("25525511135");
  for (string str : res) {
    cout << str << endl;
  }
  return 0;
}
