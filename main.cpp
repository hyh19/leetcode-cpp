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
    // 返回由 n 个不同数字 x_1 < x_2 < ... < x_n 组成的节点值互不相同的二叉搜索树的种数
    int numTrees(int n) {
        if (n < 2) {
            return 1;
        }
        if (memo.count(n) == 0) {
            // 根节点为 x_i
            for (int i = 1; i <= n; ++i) {
                // 左子树由 i-1 个数字 x1 < x2 < ... < x_i-1 组成
                int left = numTrees(i - 1);
                // 右子树由 n-i 个数字 x_i+1 < x_i+2 < ... < x_n 组成
                int right = numTrees(n - i);
                memo[n] += left * right;
            }
        }
        return memo[n];
    }

private:
    unordered_map<int, int> memo;
};
// https://leetcode.cn/submissions/detail/391591454/

int main() {
    return 0;
}