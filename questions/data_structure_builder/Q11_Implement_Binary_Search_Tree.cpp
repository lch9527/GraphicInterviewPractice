// Tesla Q11: Implement Binary Search Tree
/*
Goal:
Build a functional binary search tree for integers. Duplicates should be ignored.
*/

#include "MathTypes.h"
#include <algorithm>
#include <climits>
#include <vector>

class BinarySearchTree {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;
    int minVal;
    int maxVal;

public:
    BinarySearchTree() : root(nullptr), size(0), minVal(INT_MAX), maxVal(INT_MIN) {}

    void Insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
            size = 1;
            minVal = value;
            maxVal = value;
            return;
        }

        Node* curr = root;
        Node* pre = nullptr;
        while (curr) {
            pre = curr;
            if (value == curr->val) {
                return;
            }
            else if (value < curr->val) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        Node* newNode = new Node(value);
        if (value < pre->val) {
            pre->left = newNode;
        }
        else {
            pre->right = newNode;
        }

        minVal = std::min(minVal, value);
        maxVal = std::max(maxVal, value);
        ++size;
    }

    bool Contains(int value) const {
        Node* curr = root;
        while(curr){
            if (curr->val == value){
                return true;
            }
            if (value < curr->val){
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        return false;
    }

    int Min() const {
        if (root == nullptr) {
            return -1;
        }
        return minVal;
    }

    int Max() const {
        if (root == nullptr) {
            return -1;
        }
        return maxVal;
    }

    int Size() const {
        return size;
    }

    std::vector<int> InOrder() const {
        std::vector<int> values;
        values.reserve(size);
        InOrder(root, values);
        return values;
    }

private:
    static void InOrder(Node* node, std::vector<int>& values) {
        if (node == nullptr) {
            return;
        }

        InOrder(node->left, values);
        values.push_back(node->val);
        InOrder(node->right, values);
    }
};

bool RunTests() {
    BinarySearchTree tree;
    EXPECT_EQ_INT(tree.Min(), -1);
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(4);
    tree.Insert(5);
    EXPECT_TRUE(tree.Contains(4));
    EXPECT_FALSE(tree.Contains(9));
    EXPECT_EQ_INT(tree.Min(), 3);
    EXPECT_EQ_INT(tree.Max(), 7);
    EXPECT_EQ_INT(tree.Size(), 4);
    EXPECT_TRUE(tree.InOrder() == std::vector<int>({3,4,5,7}));
    return true;
}

RUN_TESTS()
