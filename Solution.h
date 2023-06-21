//
// Created by HUANGYUHUI on 2023/6/21.
//

#ifndef LEETCODE_CPP_SOLUTION_H
#define LEETCODE_CPP_SOLUTION_H

#include <vector>
#include <list>
#include <unordered_map>

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

struct MyListNode {
    int key, val;
    MyListNode *prev;
    MyListNode *next;

    MyListNode(int k, int v) : key{k}, val{v}, prev{nullptr}, next{nullptr} {}
};

class MyDoublyLinkedList {
public:
    MyDoublyLinkedList() : first{nullptr}, last{nullptr}, n{0} {}

    ~MyDoublyLinkedList() {
        while (!empty()) {
            removeFirst();
        }
    }

    void addLast(MyListNode *x) {
        if (n == 0) {
            first = x;
            last = x;
        } else {
            last->next = x;
            x->prev = last;
            last = x;
        }
        ++n;
    }

    void removeFirst() {
        MyListNode *x = first;
        if (n == 1) {
            first = nullptr;
            last = nullptr;
        } else {
            first = first->next;
            first->prev = nullptr;
        }
        delete x;
        --n;
    }

    void removeLast() {
        MyListNode *x = last;
        if (n == 1) {
            first = nullptr;
            last = nullptr;
        } else {
            last = last->prev;
            last->next = nullptr;
        }
        delete x;
        --n;
    }

    void remove(MyListNode *x) {
        if (x == first) {
            removeFirst();
        } else if (x == last) {
            removeLast();
        } else {
            x->prev->next = x->next;
            x->next->prev = x->prev;
            delete x;
            --n;
        }
    }

    const MyListNode *getFirst() const {
        return first;
    }

    bool empty() const {
        return first == nullptr;
    }

private:
    MyListNode *first;
    MyListNode *last;
    int n;
};

class LRUCache {
public:
    explicit LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (contains(key)) {
            return touchCache(key, INT_MIN);
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity > 0) {
            if (contains(key)) {
                touchCache(key, value);
            } else {
                if (full()) {
                    removeCache();
                }
                addCache(key, value);
            }
        }
    }

private:
    bool contains(int key) {
        return keyToNode.count(key) == 1;
    }

    bool full() {
        return keyToNode.size() == capacity;
    }

    void addCache(int key, int val) {
        MyListNode *x = new MyListNode(key, val);
        list.addLast(x);
        keyToNode[key] = x;
    }

    void removeCache() {
        int key = list.getFirst()->key;
        list.removeFirst();
        keyToNode.erase(key);
    }

    int touchCache(int key, int val) {
        MyListNode *x = keyToNode[key];
        int newVal = x->val;
        if (val != INT_MIN) {
            newVal = val;
        }
        list.remove(x);
        x = new MyListNode(key, newVal);
        list.addLast(x);
        keyToNode[key] = x;
        return newVal;
    }

private:
    int capacity;
    MyDoublyLinkedList list;
    unordered_map<int, MyListNode *> keyToNode;
};
// https://leetcode.cn/submissions/detail/391594600/

#endif //LEETCODE_CPP_SOLUTION_H
