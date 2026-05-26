// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q06_Design_Circular_Queue.cpp -o ../../questions_artifacts/tesla/tesla_q06 && ../../questions_artifacts/tesla/tesla_q06

// Tesla Q06: Design Circular Queue
/*
Description:
Implement a fixed-capacity circular queue.

A queue is FIFO: the first value enqueued is the first value dequeued.
A circular queue reuses storage by wrapping the rear index back to the beginning
when it reaches the end of the array.

Required behavior:
    enQueue(value) returns false when the queue is full, otherwise inserts value.
    deQueue() returns false when the queue is empty, otherwise removes the front value.
    Front() returns the front value, or -1 when empty.
    Rear() returns the most recently inserted value, or -1 when empty.
    isEmpty() reports whether the queue has zero elements.
    isFull() reports whether the queue has k elements.

Example with capacity 3:
    enQueue(1) -> true
    enQueue(2) -> true
    enQueue(3) -> true
    enQueue(4) -> false
    Rear() -> 3
    deQueue() -> true
    enQueue(4) -> true
    Rear() -> 4
    Front() -> 2

Edge cases:
    Correctly handle wraparound after dequeue followed by enqueue.
    Keep empty and full states distinguishable.
*/

#include "MathTypes.h"
#include <vector>

class MyCircularQueue {
public:
    explicit MyCircularQueue(int k)
        : data(k), head(0), tail(0), count(0) {}

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
    EXPECT_TRUE(q.isFull());
    EXPECT_TRUE(q.deQueue());
    EXPECT_TRUE(q.enQueue(4));
    EXPECT_EQ_INT(q.Rear(), 4);
    EXPECT_EQ_INT(q.Front(), 2);
    return true;
}

RUN_TESTS()

