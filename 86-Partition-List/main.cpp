#include "../leetcode.cpp"

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

// class Solution {
// public:
//   ListNode *partition(ListNode *head, int x) {
//     if (!head)
//       return head;
//     ListNode *lowHead = new ListNode(0);
//     ListNode *lowTail = lowHead;

//     ListNode *highHead = new ListNode(0);
//     ListNode *highTail = highHead;

//     while (head) {
//       if (head->val >= x) {
//         highTail->next = head;
//         highTail = head;
//       } else {
//         lowTail->next = head;
//         lowTail = head;
//       }

//       head = head->next;
//     }

//     highTail->next = nullptr;
//     lowTail->next = highHead->next;
//     ListNode *ret = lowHead->next;

//     delete lowHead;
//     delete highHead;
//     return ret;
//   }
// };

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *lowHead, *lowTail, *highHead, *highTail;
    lowHead = lowTail = highHead = highTail = NULL;
    while (head) {

      if (head->val < x) {
        if (lowHead == NULL) {
          lowHead = lowTail = head;
        } else {
          lowTail->next = head;
          lowTail = lowTail->next;
        }

      } else {
        if (highHead == NULL) {
          highHead = highTail = head;
        } else {
          highTail->next = head;
          highTail = highTail->next;
        }
      }

      head = head->next;
    }

    if (lowHead == NULL)
      return highHead;
    if (highHead == NULL)
      return lowHead;

    highTail->next = NULL;
    lowTail->next = highHead;
    return lowHead;
  }
};

int main(int argc, char *argv[]) {

  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(4);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(2);
  ListNode *n5 = new ListNode(5);
  ListNode *n6 = new ListNode(2);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  printNode(n1);
  Solution s = Solution();
  printNode(s.partition(n1, 3));

  return 0;
}
