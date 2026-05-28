// Tesla Q15: Implement Circular Buffer Queue
/*
Goal:
Build a fixed-capacity queue using a circular buffer.
*/

#include "MathTypes.h"

class CircularBufferQueue {
public:
    explicit CircularBufferQueue(int capacity) {
        // TODO: allocate storage and initialize read/write indices.
        (void)capacity;
    }

    bool Enqueue(int value) {
        // TODO: add value to the back if there is room.
        (void)value;
        return false;
    }

    bool Dequeue(int& outValue) {
        // TODO: remove front value if the queue is not empty.
        (void)outValue;
        return false;
    }

    bool Empty() const {
        // TODO: return whether queue is empty.
        return true;
    }

    bool Full() const {
        // TODO: return whether queue is full.
        return false;
    }

    int Size() const {
        // TODO: return current number of queued values.
        return 0;
    }
};

bool RunTests() {
    CircularBufferQueue q(3);
    int value = -1;
    EXPECT_TRUE(q.Empty());
    EXPECT_TRUE(q.Enqueue(1));
    EXPECT_TRUE(q.Enqueue(2));
    EXPECT_TRUE(q.Enqueue(3));
    EXPECT_TRUE(q.Full());
    EXPECT_FALSE(q.Enqueue(4));
    EXPECT_TRUE(q.Dequeue(value));
    EXPECT_EQ_INT(value, 1);
    EXPECT_TRUE(q.Enqueue(4));
    EXPECT_TRUE(q.Dequeue(value));
    EXPECT_EQ_INT(value, 2);
    EXPECT_TRUE(q.Dequeue(value));
    EXPECT_EQ_INT(value, 3);
    EXPECT_TRUE(q.Dequeue(value));
    EXPECT_EQ_INT(value, 4);
    EXPECT_TRUE(q.Empty());
    return true;
}

RUN_TESTS()

