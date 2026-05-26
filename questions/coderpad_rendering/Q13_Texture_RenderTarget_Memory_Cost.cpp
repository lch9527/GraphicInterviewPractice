// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q13_Texture_RenderTarget_Memory_Cost.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q13 && ../../questions_artifacts/coderpad_rendering/coderpad_q13

/*
CoderPad Rendering Question 13: Texture and Render Target Memory Cost

Task:
Estimate memory cost for textures and render targets.

Concepts tested:
- memory footprint
- mipmaps
- MSAA cost
- embedded rendering constraints
*/

#include "MathTypes.h"
#include <iostream>

int TextureMemoryBytes(int width, int height, int bytesPerPixel, bool hasMipmaps) {
    if (width <= 0 || height <= 0 || bytesPerPixel <= 0) {
        return 0;
    }

    int baseBytes = width * height * bytesPerPixel;
    if (!hasMipmaps) {
        return baseBytes;
    }
    return baseBytes * 4 / 3;
}

int RenderTargetMemoryBytes(int width, int height, int bytesPerPixel, int sampleCount) {
    if (width <= 0 || height <= 0 || bytesPerPixel <= 0 || sampleCount <= 0) {
        return 0;
    }

    return width * height * bytesPerPixel * sampleCount;
}

bool RunTests() {
    EXPECT_EQ_INT(TextureMemoryBytes(100, 50, 4, false), 20000);
    EXPECT_EQ_INT(TextureMemoryBytes(300, 300, 4, true), 480000);
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
Mipmaps increase memory but improve texture sampling quality and cache behavior.
MSAA increases memory and bandwidth roughly proportional to the sample count.
*/
