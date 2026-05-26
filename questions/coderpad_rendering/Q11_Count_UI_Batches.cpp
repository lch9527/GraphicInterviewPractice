// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q11_Count_UI_Batches.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q11 && ../../questions_artifacts/coderpad_rendering/coderpad_q11

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
    if (quads.empty()) {
        return 0;
    }

    int ans = 1;
    for (size_t i = 1; i < quads.size(); i++) {
        if (quads[i].textureId != quads[i - 1].textureId) {
            ans++;
        }
    }
    return ans;
}

int CountBatchesOrderCanChange(const std::vector<UIQuad>& quads) {
    std::unordered_set<int> textureIds;
    for (const UIQuad& quad : quads) {
        textureIds.insert(quad.textureId);
    }

    return static_cast<int>(textureIds.size());
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
