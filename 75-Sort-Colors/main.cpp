#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
  Public : void sortColors(vector<int> &nums) {
    int a[3] = {0, 0, 0};
    for (int i = 0; i < nums.size(); i++) {
      a[nums[i]] += 1;
    }
    int k = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < a[i]; j++, k++) {
        nums[k] = i;
      }
    }
  }
};

int main(int argc, char *argv[]) {

  Solution s = Solution();
  int a[] = {2, 0, 2, 1, 1, 0};
  vector<int> v(a, a + 6);
  s.sortColors(v);
  cout << v << endl;
  return 0;
}
