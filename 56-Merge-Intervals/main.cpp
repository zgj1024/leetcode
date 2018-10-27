#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.empty() || intervals.size() == 0)
      return {};

    sort(intervals.begin(), intervals.end(), [](Interval A, Interval B) {
      return A.start == B.start ? A.end < B.end : A.start < B.start;
    });

    vector<Interval> res;
    res.push_back(intervals[0]);

    for (int i = 0; i < intervals.size(); ++i) {
      Interval interval = intervals[i];
      if (res.back().end >= interval.start) {
        if (res.back().end < interval.end)
          res.back().end = interval.end;
      } else {
        res.push_back(interval);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s = Solution();

  vector<Interval> v(0);
  Interval i1 = Interval(1, 3);
  Interval i2 = Interval(2, 6);
  Interval i3 = Interval(8, 10);
  Interval i4 = Interval(15, 18);

  v.push_back(i1);
  v.push_back(i2);
  v.push_back(i3);
  v.push_back(i4);

  printIntervalList(s.merge(v));
  return 0;
}
