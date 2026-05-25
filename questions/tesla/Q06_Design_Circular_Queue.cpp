// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q06_Design_Circular_Queue.cpp -o ../../questions_artifacts/tesla/tesla_q06 && ../../questions_artifacts/tesla/tesla_q06

// Tesla Q06: Design Circular Queue
/*
Description:
Implement a fixed-capacity circular queue with O(1) enqueue, dequeue, front, and rear.
*/

#include "MathTypes.h"
#include <vector>

class MyCircularQueue {
public:
    explicit MyCircularQueue(int k)
        : data(k), head(0), tail(0), count(0) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1) % static_cast<int>(data.size());
        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % static_cast<int>(data.size());
        --count;
        return true;
    }

    int Front() const {
        return isEmpty() ? -1 : data[head];
    }

    int Rear() const {
        if (isEmpty()) return -1;
        int index = (tail - 1 + static_cast<int>(data.size())) % static_cast<int>(data.size());
        return data[index];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == static_cast<int>(data.size());
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

