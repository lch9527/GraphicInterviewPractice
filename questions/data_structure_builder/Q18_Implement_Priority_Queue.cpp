// Data Structure Builder Q18: Implement Priority Queue
/*
Goal:
Build a functional max-priority queue backed by a binary heap.

Higher priority values should be removed before lower priority values.
When two entries have the same priority, remove the older entry first.
*/

#include "MathTypes.h"
#include <vector>

class PriorityQueue {
public:
    void Push(int value, int priority) {
        // TODO: append an item and bubble it up until the heap property holds.
        (void)value;
        (void)priority;
    }

    bool Peek(int& outValue) const {
        // TODO: write the highest-priority value without removing it.
        (void)outValue;
        return false;
    }

    bool Pop(int& outValue) {
        // TODO: remove and write the highest-priority value.
        (void)outValue;
        return false;
    }

    bool Empty() const {
        // TODO: return whether the queue has no entries.
        return true;
    }

    int Size() const {
        // TODO: return the number of queued entries.
        return 0;
    }

private:
    struct Entry {
        int value = 0;
        int priority = 0;
        int insertionOrder = 0;
    };

    std::vector<Entry> heap_;
    int nextInsertionOrder_ = 0;
};

bool RunTests() {
    PriorityQueue queue;
    int value = -1;

    EXPECT_TRUE(queue.Empty());
    EXPECT_FALSE(queue.Peek(value));
    EXPECT_FALSE(queue.Pop(value));

    queue.Push(100, 1);
    queue.Push(200, 5);
    queue.Push(300, 3);
    queue.Push(400, 5);

    EXPECT_FALSE(queue.Empty());
    EXPECT_EQ_INT(queue.Size(), 4);

    EXPECT_TRUE(queue.Peek(value));
    EXPECT_EQ_INT(value, 200);
    EXPECT_EQ_INT(queue.Size(), 4);

    EXPECT_TRUE(queue.Pop(value));
    EXPECT_EQ_INT(value, 200);
    EXPECT_TRUE(queue.Pop(value));
    EXPECT_EQ_INT(value, 400);

    queue.Push(500, 10);
    queue.Push(600, 2);

    EXPECT_TRUE(queue.Pop(value));
    EXPECT_EQ_INT(value, 500);
    EXPECT_TRUE(queue.Pop(value));
    EXPECT_EQ_INT(value, 300);
    EXPECT_TRUE(queue.Pop(value));
    EXPECT_EQ_INT(value, 600);
    EXPECT_TRUE(queue.Pop(value));
    EXPECT_EQ_INT(value, 100);
    EXPECT_TRUE(queue.Empty());
    EXPECT_EQ_INT(queue.Size(), 0);

    return true;
}

RUN_TESTS()
