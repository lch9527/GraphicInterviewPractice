// Tesla Q11: Implement Binary Search Tree
/*
Goal:
Build a functional binary search tree for integers. Duplicates should be ignored.
*/

#include "MathTypes.h"
#include <vector>

class BinarySearchTree {
public:
    void Insert(int value) {
        // TODO: insert value while preserving BST order. Ignore duplicates.
        (void)value;
    }

    bool Contains(int value) const {
        // TODO: return true if value exists in the tree.
        (void)value;
        return false;
    }

    int Min() const {
        // TODO: return smallest value, or -1 if empty.
        return -1;
    }

    int Max() const {
        // TODO: return largest value, or -1 if empty.
        return -1;
    }

    int Size() const {
        // TODO: return number of unique values.
        return 0;
    }

    std::vector<int> InOrder() const {
        // TODO: return sorted values using inorder traversal.
        return {};
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

