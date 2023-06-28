#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <deque>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        auto *dummyHead = new ListNode(-1, head);
        ListNode *ptr = dummyHead;
        while (ptr != nullptr && ptr->next != nullptr) {
            if (ptr->next->val == val) {
                ListNode *x = ptr->next;
                ptr->next = ptr->next->next;
                delete x;
            } else {
                ptr = ptr->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
// https://leetcode.cn/submissions/detail/391584118/

int main() {
    return 0;
}