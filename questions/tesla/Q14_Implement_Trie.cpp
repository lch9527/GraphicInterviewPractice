// Tesla Q14: Implement Trie
/*
Goal:
Build a functional trie for lowercase English words.
*/

#include "MathTypes.h"
#include <string>

class Trie {
public:
    void Insert(const std::string& word) {
        // TODO: create nodes for each character and mark the final node as a word.
        (void)word;
    }

    bool Search(const std::string& word) const {
        // TODO: return true only for complete inserted words.
        (void)word;
        return false;
    }

    bool StartsWith(const std::string& prefix) const {
        // TODO: return true when prefix path exists.
        (void)prefix;
        return false;
    }
};

bool RunTests() {
    Trie trie;
    trie.Insert("car");
    trie.Insert("cat");
    trie.Insert("dog");
    EXPECT_TRUE(trie.Search("car"));
    EXPECT_TRUE(trie.Search("cat"));
    EXPECT_FALSE(trie.Search("ca"));
    EXPECT_TRUE(trie.StartsWith("ca"));
    EXPECT_TRUE(trie.StartsWith("do"));
    EXPECT_FALSE(trie.StartsWith("z"));
    return true;
}

RUN_TESTS()

