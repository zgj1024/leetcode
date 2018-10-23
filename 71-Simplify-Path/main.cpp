#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

// class Solution {
// public:
//   string simplifyPath(string path) {
//     vector<string> tokens;
//     for (int i = 0; i < path.size(); i++) {
//       string token = "";
//       while (path[i] != '/' && i < path.size()) {
//         token += path[i];
//         i++;
//       }

//       if (token.size() > 0 && token != ".") {
//         tokens.push_back(token);
//       }
//     }

//     vector<string> pathStack(0);
//     for (int i = 0; i < tokens.size(); i++) {
//       string token = tokens[i];
//       if (token == "..") {
//         if (pathStack.size() == 0)
//           continue;
//         pathStack.pop_back();
//       } else {
//         pathStack.push_back(token);
//       }
//     }

//     if (pathStack.size() == 0) {
//       return "/";
//     }

//     string ret = "";
//     for (int i = 0; i < pathStack.size(); i++) {
//       cout << pathStack[i] << endl;
//       ret += "/" + pathStack[i];
//     }
//     return ret;
//   }
// };

class Solution {
public:
  string simplifyPath(string path) {

    vector<string> pathStack(0);
    for (int i = 0; i < path.size(); i++) {
      string token = "";
      while (path[i] != '/' && i < path.size()) {
        token.push_back(path[i]);
        //        token += path[i];
        i++;
      }

      if (token.size() > 0 && token != ".") {
        if (token == "..") {
          if (pathStack.size() == 0)
            continue;
          pathStack.pop_back();
        } else {
          pathStack.push_back(token);
        }
      }
    }

    if (pathStack.size() == 0) {
      return "/";
    }

    string ret = "";
    for (int i = 0; i < pathStack.size(); i++) {
      ret.append("/");
      ret.append(pathStack[i]);
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {

  Solution s = Solution();

  ASSERT_EQUAL<string>("/home", s.simplifyPath("/home/"), "/home");
  ASSERT_EQUAL<string>("/c", s.simplifyPath("/a/./b/../../c/"),
                       "/a/./b/../../c/");
  ASSERT_EQUAL<string>("/c", s.simplifyPath("/a/../../b/../c//.//"),
                       "/a/../../b/../c//.//");
  ASSERT_EQUAL<string>("/a/b/c", s.simplifyPath("/a//b////c/d//././/.."),
                       "/a//b////c/d//././/..");

  report();
  return 0;
}
