/*
CoderPad Rendering Question 11: Count UI Batches

Task:
Given UI quads with texture IDs, count draw batches when order cannot change
and when order can change.

Concepts tested:
- batching
- texture binding changes
- draw-call count
- ordered transparent UI
- unordered opaque UI
*/

#include "MathTypes.h"
#include <iostream>
#include <vector>
#include <unordered_set>

int CountBatchesOrderCannotChange(const std::vector<UIQuad>& quads) {
    // TODO: count contiguous runs of the same textureId.
    (void)quads;
    return 0;
}

int CountBatchesOrderCanChange(const std::vector<UIQuad>& quads) {
    // TODO: count unique texture IDs.
    (void)quads;
    return 0;
}

bool RunTests() {
    std::vector<UIQuad> quads = {{1}, {1}, {2}, {2}, {1}, {3}};
    EXPECT_EQ_INT(CountBatchesOrderCannotChange(quads), 4);
    EXPECT_EQ_INT(CountBatchesOrderCanChange(quads), 3);
    EXPECT_EQ_INT(CountBatchesOrderCannotChange({}), 0);
    EXPECT_EQ_INT(CountBatchesOrderCanChange({}), 0);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q11 Count UI Batches\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
If UI order cannot change, each texture change creates a new batch. If order can
change, quads can be grouped by texture, so the number of batches is the number
of unique texture IDs.
*/
