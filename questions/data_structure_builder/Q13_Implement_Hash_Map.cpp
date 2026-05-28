// Tesla Q13: Implement Hash Map
/*
Goal:
Build a functional int-to-int hash map. Use separate chaining or open addressing.
*/

#include "MathTypes.h"

class IntHashMap {
public:
    explicit IntHashMap(int bucketCount = 16) {
        // TODO: initialize storage with bucketCount buckets.
        (void)bucketCount;
    }

    void Put(int key, int value) {
        // TODO: insert or update key.
        (void)key;
        (void)value;
    }

    bool Get(int key, int& outValue) const {
        // TODO: return true and write value when key exists.
        (void)key;
        (void)outValue;
        return false;
    }

    bool Remove(int key) {
        // TODO: remove key if it exists.
        (void)key;
        return false;
    }

    int Size() const {
        // TODO: return number of stored keys.
        return 0;
    }
};

bool RunTests() {
    IntHashMap map(4);
    int value = -1;
    EXPECT_FALSE(map.Get(10, value));
    map.Put(10, 100);
    map.Put(14, 140);
    map.Put(10, 101);
    EXPECT_EQ_INT(map.Size(), 2);
    EXPECT_TRUE(map.Get(10, value));
    EXPECT_EQ_INT(value, 101);
    EXPECT_TRUE(map.Get(14, value));
    EXPECT_EQ_INT(value, 140);
    EXPECT_TRUE(map.Remove(10));
    EXPECT_FALSE(map.Get(10, value));
    EXPECT_FALSE(map.Remove(10));
    return true;
}

RUN_TESTS()

