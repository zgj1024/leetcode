#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
public:
  void fullJustify(vector<string> &words, int begin, int last, int linesize,
                   int maxWidth, vector<string> &res) {
    if (begin == last) {
      string word = words[begin];
      for (int i = word.length(); i < maxWidth; i++) {
        word.append(" ");
      }
      res.push_back(word);
      return;
    }

    int sNum = last - begin; //间隔数
    int spaceNum = maxWidth - linesize + sNum;

    int r = spaceNum % sNum;
    int preSpace = spaceNum / sNum;
    string line = "";
    for (int i = begin; i <= last; i++) {
      line.append(words[i]);
      if (sNum > 0) {
        for (int k = 0; k < preSpace; k++) {
          line.append(" ");
        }
        sNum--;
      }
      if (r > 0) {
        line.append(" ");
        r--;
      }
    }
    res.push_back(line);
  }
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res(0);
    int begin = 0;
    int lineSize = words[0].length();
    for (int i = 1; i < words.size();) {
      if (lineSize + 1 + words[i].length() > maxWidth) {

        fullJustify(words, begin, i - 1, lineSize, maxWidth, res);
        // for (int j = begin; j <= i - 1; j++) {
        //   cout << words[j] << " ";
        // }
        // cout << endl;
        begin = i;
        lineSize = words[i].length();
        i++;
      } else {
        lineSize += 1 + words[i].length();
        i++;
      }
    }

    //处理最后一行
    if (lineSize != 0) {
      string line = "";
      for (int i = begin; i < words.size(); i++) {
        if (i != begin) {
          line.append(" ");
        }
        line.append(words[i]);
      }

      for (int i = line.size(); i < maxWidth; i++) {
        line.append(" ");
      }

      res.push_back(line);
      //      fullJustify(words, begin, words.size() - 1, lineSize, maxWidth,
      //      res);
      // for (int i = begin; i < words.size(); i++) {
      //   cout << words[i] << " ";
      // }
      // cout << endl;
      return res;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  string strArray[] = {"Science", "is",        "what", "we",      "understand",
                       "well",    "enough",    "to",   "explain", "to",
                       "a",       "computer.", "Art",  "is",      "everything",
                       "else",    "we",        "do",   "be"};
  std::vector<string> strVector(std::begin(strArray), std::end(strArray));
  Solution s = Solution();
  vector<string> result = s.fullJustify(strVector, 20); //<< endl;
  for (string s : result) {
    cout << s << " " << s.length() << endl;
  }

  string a2[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
  std::vector<string> strVector2(std::begin(a2), std::end(a2));

  result = s.fullJustify(strVector2, 16); //<< endl;
  for (string s : result) {
    cout << s << " " << s.length() << endl;
  }
  //  report();
  return 0;
}
