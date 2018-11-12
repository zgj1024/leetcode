#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  int numDecodings(string s) {
    if (s.length() == 0 && s[0] == '0')
      return 0;
    int c1 = 1;
    int c2 = 1;

    for (int i = 0; i < s.length(); ++i) {
      int w = 0;
      if (!isVaild(s[i]) && !isVaild(s[i - 1], s[i]))
        return 0;
      if (isVaild(s[i]))
        w = c1;
      if (isVaild(s[i - 1], s[i]))
        w += c2;
      c2 = c1;
      c1 = w;
    }
    return c1;
  }

  bool isVaild(const char c) { return c != '0'; }
  bool isVaild(const char c1, const char c2) {
    int num = (c1 - '0') * 10 + (c2 - '0');
    return num > 9 && num < 27;
  }

  //   int numDecodings(string s, int begin, int end, vector<int> &v) {
  //     if (v[begin] != -1)
  //       return v[begin];
  //     if (begin > end) {
  //       return 1;
  //     }
  //     if (s[begin] == '0')
  //       return 0;

  //     int count = 0;
  //     if (v[begin + 1] == -1) {
  //       v[begin + 1] = numDecodings(s, begin + 1, end, v);
  //     }
  //     count = v[begin + 1];

  //     if (checkIsLessThan27(s, begin, end)) {
  //       if (v[begin + 2] == -1) {
  //         v[begin + 2] = numDecodings(s, begin + 2, end, v);
  //       }

  //       count += v[begin + 2];
  //     }

  //     return count;
  //   }

  //   bool checkIsLessThan27(string s, int begin, int end) {
  //     if (begin + 1 > end)
  //       return false;
  //     if (s[begin] == '1')
  //       return true;
  //     if (s[begin] == '2' && s[begin + 1] < '7')
  //       return true;
  //     return false;
  //   }

  //   int numDecodings(string s) {
  //     if (s.length() == 0 || s[0] == '0')
  //       return 0;
  //     vector<int> v(s.length() + 1, -1);
  //     return numDecodings(s, 0, s.length() - 1, v);
  //   }
};

int main(int argc, char *argv[]) {
  Solution s = Solution();
  ASSERT_EQUAL(0, s.numDecodings("0"), "0");
  ASSERT_EQUAL(1, s.numDecodings("2"), "2");
  ASSERT_EQUAL(1, s.numDecodings("1"), "1");
  ASSERT_EQUAL(1, s.numDecodings("9"), "9");
  ASSERT_EQUAL(1, s.numDecodings("10"), "10");
  ASSERT_EQUAL(1, s.numDecodings("20"), "20");
  ASSERT_EQUAL(1, s.numDecodings("27"), "27");
  ASSERT_EQUAL(1, s.numDecodings("29"), "29");
  ASSERT_EQUAL(1, s.numDecodings("99"), "99");
  ASSERT_EQUAL(0, s.numDecodings("00"), "00");
  // 2 1
  // 1
  ASSERT_EQUAL(2, s.numDecodings("12"), "12");
  ASSERT_EQUAL(3, s.numDecodings("226"), "226");

  ASSERT_EQUAL(3, s.numDecodings("216"), "216"); // 2 16; 21 6 ; 2 1 6
  ASSERT_EQUAL(1, s.numDecodings("101"), "101");
  report();
  return 0;
}
