#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

    intervals.push_back(newInterval);

    if (intervals.size() == 1) {
      return intervals;
    }
    sort(intervals.begin(), intervals.end(), [](Interval A, Interval B) {
      return A.start == B.start ? A.end < B.end : A.start < B.start;
    });

    vector<Interval> res;
    res.push_back(intervals[0]);

    for (Interval interval : intervals) {
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

  return 0;
}
