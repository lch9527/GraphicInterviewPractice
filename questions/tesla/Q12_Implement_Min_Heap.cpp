// Tesla Q12: Implement Min Heap
/*
Goal:
Build a functional binary min heap backed by a vector.
*/

#include "MathTypes.h"
#include <vector>

class MinHeap {
public:
    void Push(int value) {
        // TODO: append value and bubble it up.
        (void)value;
    }

    int Peek() const {
        // TODO: return the smallest value, or -1 if empty.
        return -1;
    }

    int Pop() {
        // TODO: remove and return the smallest value, or -1 if empty.
        return -1;
    }

    bool Empty() const {
        // TODO: return whether the heap has no elements.
        return true;
    }

    int Size() const {
        // TODO: return heap size.
        return 0;
    }
};

bool RunTests() {
    MinHeap heap;
    EXPECT_TRUE(heap.Empty());
    heap.Push(5);
    heap.Push(2);
    heap.Push(8);
    heap.Push(1);
    EXPECT_EQ_INT(heap.Peek(), 1);
    EXPECT_EQ_INT(heap.Size(), 4);
    EXPECT_EQ_INT(heap.Pop(), 1);
    EXPECT_EQ_INT(heap.Pop(), 2);
    heap.Push(0);
    EXPECT_EQ_INT(heap.Pop(), 0);
    EXPECT_EQ_INT(heap.Pop(), 5);
    EXPECT_EQ_INT(heap.Pop(), 8);
    EXPECT_TRUE(heap.Empty());
    return true;
}

RUN_TESTS()

