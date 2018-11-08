#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  string addStrings(string num1, string num2) {
    int n = num1.length() - 1;
    int m = num2.length() - 1;
    if (n < 0) {
      return num2;
    }
    if (m < 0) {
      return num1;
    }

    int max = n > m ? n : m;
    int carry = 0;

    string result = "";
    int n1, n2;
    for (int i = max; i >= 0; i--, n--, m--) {

      if (n < 0) {
        n1 = 0;
      } else {
        n1 = num1[n] - '0';
      }

      if (m < 0) {
        n2 = 0;
      } else {
        n2 = num2[m] - '0';
      }

      //      cout << "n1: " << n1 << " n2: " << n2 << endl;
      int v = n1 + n2 + carry;
      if (v >= 10) {
        carry = v / 10;
        v = v % 10;
      } else {
        carry = 0;
      }
      //      cout << "v: " << v << endl;
      char c = v + '0';
      result.append(1, c);
      //      result.insert(0, 1, c);
    }
    if (carry > 0) {
      char c = carry + '0';
      result.append(1, c);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
int main(int argc, char *argv[]) {
  Solution s = Solution();
  ASSERT_EQUAL<string>("2", s.addStrings("1", "1"), "1+1==2?");
  ASSERT_EQUAL<string>("10", s.addStrings("1", "9"), "1+9==10?");
  ASSERT_EQUAL<string>("100", s.addStrings("12", "88"), "12+88==100?");
  ASSERT_EQUAL<string>("198", s.addStrings("99", "99"), "99+99==198?");
  ASSERT_EQUAL<string>("413", s.addStrings("408", "5"), "408+5==413?");
  report();
  return 0;
}
