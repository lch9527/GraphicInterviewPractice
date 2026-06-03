// LeetCode Q06: Design Circular Queue
// CoderPad-style prompt file. Implement the TODO class methods, then add or run tests.

/*
Implement a fixed-capacity circular queue.

enQueue returns false when full. deQueue returns false when empty. Front and
Rear return -1 when empty.
*/

#include "MathTypes.h"
#include <vector>

class MyCircularQueue {
public:
    explicit MyCircularQueue(int k) : data(k), head(0), tail(0), count(0) {}

    bool enQueue(int value) {
        // TODO: implement.
        (void)value;
        return false;
    }

    bool deQueue() {
        // TODO: implement.
        return false;
    }

    int Front() const {
        // TODO: implement.
        return -1;
    }

    int Rear() const {
        // TODO: implement.
        return -1;
    }

    bool isEmpty() const {
        // TODO: implement.
        return true;
    }

    bool isFull() const {
        // TODO: implement.
        return false;
    }

private:
    std::vector<int> data;
    int head;
    int tail;
    int count;
};

bool RunTests() {
    MyCircularQueue q(3);
    EXPECT_TRUE(q.enQueue(1));
    EXPECT_TRUE(q.enQueue(2));
    EXPECT_TRUE(q.enQueue(3));
    EXPECT_FALSE(q.enQueue(4));
    EXPECT_EQ_INT(q.Rear(), 3);
    EXPECT_TRUE(q.deQueue());
    EXPECT_TRUE(q.enQueue(4));
    EXPECT_EQ_INT(q.Front(), 2);
    return true;
}

RUN_TESTS()
