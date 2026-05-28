// Tesla Q09: Implement Singly Linked List
/*
Goal:
Build a functional singly linked list that supports front/back insertion,
removal by value, lookup, size, and conversion to a vector for testing.
*/

#include "MathTypes.h"
#include <vector>

class SinglyLinkedList {
public:
    void PushFront(int value) {
        // TODO: insert value at the head.
        (void)value;
    }

    void PushBack(int value) {
        // TODO: insert value at the tail.
        (void)value;
    }

    bool RemoveFirst(int value) {
        // TODO: remove the first node with this value.
        (void)value;
        return false;
    }

    bool Contains(int value) const {
        // TODO: return true if any node stores value.
        (void)value;
        return false;
    }

    int Size() const {
        // TODO: return the number of nodes.
        return 0;
    }

    std::vector<int> ToVector() const {
        // TODO: return list values from head to tail.
        return {};
    }
};

bool RunTests() {
    SinglyLinkedList list;
    EXPECT_EQ_INT(list.Size(), 0);
    list.PushBack(2);
    list.PushFront(1);
    list.PushBack(3);
    EXPECT_TRUE(list.ToVector() == std::vector<int>({1,2,3}));
    EXPECT_EQ_INT(list.Size(), 3);
    EXPECT_TRUE(list.Contains(2));
    EXPECT_TRUE(list.RemoveFirst(2));
    EXPECT_FALSE(list.Contains(2));
    EXPECT_TRUE(list.ToVector() == std::vector<int>({1,3}));
    EXPECT_FALSE(list.RemoveFirst(99));
    return true;
}

RUN_TESTS()

