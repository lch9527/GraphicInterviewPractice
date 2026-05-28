// Tesla Q10: Implement Doubly Linked List
/*
Goal:
Build a functional doubly linked list that supports push/pop at both ends and
can be traversed forward and backward.
*/

#include "MathTypes.h"
#include <vector>

class DoublyLinkedList {
public:
    void PushFront(int value) {
        // TODO: insert value at the head.
        (void)value;
    }

    void PushBack(int value) {
        // TODO: insert value at the tail.
        (void)value;
    }

    bool PopFront(int& outValue) {
        // TODO: remove head and write its value.
        (void)outValue;
        return false;
    }

    bool PopBack(int& outValue) {
        // TODO: remove tail and write its value.
        (void)outValue;
        return false;
    }

    int Size() const {
        // TODO: return the number of nodes.
        return 0;
    }

    std::vector<int> ToVectorForward() const {
        // TODO: return values from head to tail.
        return {};
    }

    std::vector<int> ToVectorBackward() const {
        // TODO: return values from tail to head.
        return {};
    }
};

bool RunTests() {
    DoublyLinkedList list;
    int value = -1;
    EXPECT_FALSE(list.PopFront(value));
    list.PushBack(2);
    list.PushFront(1);
    list.PushBack(3);
    EXPECT_TRUE(list.ToVectorForward() == std::vector<int>({1,2,3}));
    EXPECT_TRUE(list.ToVectorBackward() == std::vector<int>({3,2,1}));
    EXPECT_EQ_INT(list.Size(), 3);
    EXPECT_TRUE(list.PopFront(value));
    EXPECT_EQ_INT(value, 1);
    EXPECT_TRUE(list.PopBack(value));
    EXPECT_EQ_INT(value, 3);
    EXPECT_TRUE(list.ToVectorForward() == std::vector<int>({2}));
    return true;
}

RUN_TESTS()

