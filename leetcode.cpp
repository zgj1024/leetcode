#include <iostream>
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
  if (test_count == test_pass) {
    cout << BOLD << GRN << test_pass << "/" << test_count << " ";
    cout << test_pass * 100.0 / test_count << "% passed" << RST << RST << endl;
  }
}
