/*
CoderPad Rendering Question 12: Sort Render Commands

Task:
Separate opaque and transparent commands and sort them correctly.

Concepts tested:
- std::vector
- std::sort
- custom comparators
- material/texture batching
- alpha blending order
*/

#include "MathTypes.h"
#include <iostream>
#include <vector>
#include <algorithm>

struct RenderCommand {
    int materialId = 0;
    int textureId = 0;
    bool transparent = false;
    float depth = 0.0f;
};

std::vector<RenderCommand> SortOpaqueCommands(const std::vector<RenderCommand>& commands) {
    // TODO: keep only opaque commands and sort by materialId, then textureId.
    (void)commands;
    return {};
}

std::vector<RenderCommand> SortTransparentCommands(const std::vector<RenderCommand>& commands) {
    // TODO: keep only transparent commands and sort back-to-front by descending depth.
    (void)commands;
    return {};
}

bool RunTests() {
    std::vector<RenderCommand> commands = {
        {2, 5, false, 2.0f},
        {1, 9, false, 1.0f},
        {1, 3, false, 3.0f},
        {9, 1, true,  4.0f},
        {9, 2, true,  8.0f}
    };

    std::vector<RenderCommand> opaque = SortOpaqueCommands(commands);
    EXPECT_EQ_INT(static_cast<int>(opaque.size()), 3);
    EXPECT_EQ_INT(opaque[0].materialId, 1);
    EXPECT_EQ_INT(opaque[0].textureId, 3);
    EXPECT_EQ_INT(opaque[1].textureId, 9);
    EXPECT_EQ_INT(opaque[2].materialId, 2);

    std::vector<RenderCommand> transparent = SortTransparentCommands(commands);
    EXPECT_EQ_INT(static_cast<int>(transparent.size()), 2);
    EXPECT_NEAR(transparent[0].depth, 8.0f);
    EXPECT_NEAR(transparent[1].depth, 4.0f);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q12 Sort Render Commands\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Opaque objects can be sorted to reduce state changes. Transparent objects
usually need back-to-front sorting because blending is order-dependent.
*/
