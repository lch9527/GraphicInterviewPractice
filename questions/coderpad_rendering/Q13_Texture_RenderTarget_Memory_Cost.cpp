/*
CoderPad Rendering Question 13: Texture and Render Target Memory Cost

Estimate memory cost for textures, mipmaps, and MSAA render targets.
*/

#include "MathTypes.h"
#include <iostream>

int TextureMemoryBytes(int width, int height, int bytesPerPixel, bool hasMipmaps) {
    // TODO: base texture cost, with full mip chain approximated as base * 4 / 3.
    int baseSize = width * height * bytesPerPixel;
    if (!hasMipmaps) return baseSize;
    return baseSize * 4 / 3;
}

int RenderTargetMemoryBytes(int width, int height, int bytesPerPixel, int sampleCount) {
    // TODO: MSAA cost is proportional to sample count.
    return width * height * bytesPerPixel * sampleCount;
}

bool RunTests() {
    EXPECT_EQ_INT(TextureMemoryBytes(1024, 1024, 4, false), 4194304);
    EXPECT_EQ_INT(TextureMemoryBytes(1024, 1024, 4, true), 5592405);
    EXPECT_EQ_INT(RenderTargetMemoryBytes(1920, 1080, 4, 1), 8294400);
    EXPECT_EQ_INT(RenderTargetMemoryBytes(1920, 1080, 4, 4), 33177600);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q13 Texture RenderTarget Memory Cost\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Mipmaps add memory but improve texture sampling quality and cache behavior.
MSAA increases render target memory and bandwidth roughly by sample count.
*/
