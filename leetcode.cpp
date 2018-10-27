#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

const string RST = "\x1B[0m";
const string RED = "\x1B[31m";
const string GRN = "\x1B[32m";
const string KYEL = "\x1B[33m";

const string BOLD = "\x1B[1m";

static int test_count = 0;
static int test_pass = 0;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void printNode(ListNode *head) {
  while (head) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << "nil" << endl;
}

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

void printIntervalList(vector<Interval> list) {
  for (Interval interval : list) {
    cout << "[" << interval.start << "," << interval.end << "]" << endl;
  }
}

template <typename T> void ASSERT_EQUAL(T expect, T actual, string args) {
  test_count++;
  if (!args.empty()) {
    cerr << BOLD << KYEL << "args：" << args << RST << RST << endl;
  }
  if (expect == actual) {
    test_pass++;
    cerr << BOLD << GRN << "[PASS]" << endl << endl;
  } else {
    cerr << BOLD << RED << "expect is " << expect << RST << RST;
    cerr << BOLD << RED << " but is " << actual << RST << RST << endl << endl;
  }
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "{";
  size_t last = v.size() - 1;
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last)
      out << ", ";
  }
  out << "}";
  return out;
}

void report() {
  cout << BOLD << GRN << test_pass << "/" << test_count << " ";
  cout << test_pass * 100.0 / test_count << "% passed" << RST << RST << endl;
}
