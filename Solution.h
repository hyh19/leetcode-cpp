//
// Created by HUANGYUHUI on 2023/2/20.
//

#ifndef LEETCODE_CPP_SOLUTION_H
#define LEETCODE_CPP_SOLUTION_H

#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

private:
    ListNode *mergeKLists(vector<ListNode *> &lists, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        if (lo == hi) {
            return lists[lo];
        }
        int mid = lo + (hi - lo) / 2;
        ListNode *left = mergeKLists(lists, lo, mid);
        ListNode *right = mergeKLists(lists, mid + 1, hi);
        return mergeTwoLists(left, right);
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        auto *dummyHead = new ListNode();
        ListNode *ptr = dummyHead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = (list1 == nullptr ? list2 : list1);
        ListNode *head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

#endif //LEETCODE_CPP_SOLUTION_H
