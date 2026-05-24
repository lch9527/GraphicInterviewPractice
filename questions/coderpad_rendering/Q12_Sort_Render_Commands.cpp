/*
CoderPad Rendering Question 12: Sort Render Commands

Separate opaque and transparent commands and sort them for batching/blending.
*/

#include "MathTypes.h"
#include <algorithm>
#include <iostream>
#include <vector>

struct RenderCommand {
    int materialId = 0;
    int textureId = 0;
    bool transparent = false;
    float depth = 0.0f;
};

std::vector<RenderCommand> SortOpaqueCommands(const std::vector<RenderCommand>& commands) {
    // TODO: keep opaque only, sorted by material then texture.
    std::vector<RenderCommand> result;
    for (const RenderCommand& command : commands) {
        if (!command.transparent) result.push_back(command);
    }
    std::sort(result.begin(), result.end(), [](const RenderCommand& a, const RenderCommand& b) {
        if (a.materialId != b.materialId) return a.materialId < b.materialId;
        return a.textureId < b.textureId;
    });
    return result;
}

std::vector<RenderCommand> SortTransparentCommands(const std::vector<RenderCommand>& commands) {
    // TODO: keep transparent only, sorted back-to-front by descending depth.
    std::vector<RenderCommand> result;
    for (const RenderCommand& command : commands) {
        if (command.transparent) result.push_back(command);
    }
    std::sort(result.begin(), result.end(), [](const RenderCommand& a, const RenderCommand& b) {
        return a.depth > b.depth;
    });
    return result;
}

bool RunTests() {
    std::vector<RenderCommand> commands = {
        {2, 5, false, 3.0f}, {1, 9, false, 8.0f}, {1, 4, false, 1.0f},
        {7, 1, true, 2.0f}, {7, 2, true, 9.0f}, {7, 3, true, 5.0f}
    };
    std::vector<RenderCommand> opaque = SortOpaqueCommands(commands);
    std::vector<RenderCommand> transparent = SortTransparentCommands(commands);
    EXPECT_EQ_INT(static_cast<int>(opaque.size()), 3);
    EXPECT_EQ_INT(opaque[0].materialId, 1);
    EXPECT_EQ_INT(opaque[0].textureId, 4);
    EXPECT_EQ_INT(opaque[1].textureId, 9);
    EXPECT_EQ_INT(opaque[2].materialId, 2);
    EXPECT_EQ_INT(static_cast<int>(transparent.size()), 3);
    EXPECT_NEAR(transparent[0].depth, 9.0f);
    EXPECT_NEAR(transparent[1].depth, 5.0f);
    EXPECT_NEAR(transparent[2].depth, 2.0f);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q12 Sort Render Commands\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Opaque objects can be sorted to reduce material and texture state changes.
Transparent objects usually need back-to-front sorting because blending is
order-dependent.
*/
