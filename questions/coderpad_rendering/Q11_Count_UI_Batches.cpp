/*
CoderPad Rendering Question 11: Count UI Batches

Count draw batches for UI quads with texture IDs. This is a CoderPad-focused
variation of the existing UI batching question.
*/

#include "MathTypes.h"
#include <iostream>
#include <unordered_set>
#include <vector>

int CountBatchesOrderCannotChange(const std::vector<UIQuad>& quads) {
    // TODO: count runs of identical texture IDs in the original order.
    if (quads.empty()) return 0;
    int batches = 1;
    for (size_t i = 1; i < quads.size(); ++i) {
        if (quads[i].textureId != quads[i - 1].textureId) ++batches;
    }
    return batches;
}

int CountBatchesOrderCanChange(const std::vector<UIQuad>& quads) {
    // TODO: count unique texture IDs when order is allowed to change.
    std::unordered_set<int> textureIds;
    for (const UIQuad& quad : quads) textureIds.insert(quad.textureId);
    return static_cast<int>(textureIds.size());
}

bool RunTests() {
    std::vector<UIQuad> quads = {{1},{1},{2},{2},{1},{3}};
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
Transparent UI often cannot be reordered, so each texture change can force a
new batch. Opaque or reorderable UI can group by unique texture.
*/
