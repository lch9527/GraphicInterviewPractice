# C++ Graphics Math Interview Practice

This project contains standalone C++ practice questions for graphics/math, rendering, data structures, and LeetCode-style interviews.

Each buildable answer/exercise file is a separate `.cpp` file inside `questions/` with built-in tests. LeetCode prompts are intentionally separate from their answer files.

## Folder structure

```text
include/MathTypes.h      Shared Vec2, Vec3, Mat4, test macros, helpers
questions/3D math/Q##_*.cpp
                         3D graphics math practice problems
questions/coderpad_rendering/Q*.cpp
                         Rendering-focused CoderPad practice problems
questions/data_structure_builder/Q##_*.cpp
                         Data-structure construction and serialization problems
questions/leetcode/neetcode_150/Prompt_NC###_*.cpp
                         Empty CoderPad-style LeetCode prompts
questions/leetcode/neetcode_150/Answer_NC###_*.cpp
                         NeetCode 150 answer workspaces
questions/leetcode/Answer_Q##_...cpp
                         Extra solved non-roadmap LeetCode examples
scripts/run_all.sh       Compiles and runs every buildable answer/exercise file
CMakeLists.txt           Optional CMake build
```

## Run one question

From a question folder:

```bash
g++ -std=c++17 -I../../include Q04_Compute_Dot_Product.cpp -o q04
./q04
```

On Windows with Visual Studio Developer Command Prompt, you can use:

```bat
cl /std:c++17 /EHsc /I..\..\include Q04_Compute_Dot_Product.cpp
Q04_Compute_Dot_Product.exe
```

## Run all buildable files

From the project root:

```bash
bash scripts/run_all.sh
```

Generated NeetCode roadmap files under `questions/leetcode/neetcode_150/Prompt_NC###_*` and `questions/leetcode/neetcode_150/Answer_NC###_*` are starter workspaces. The current CMake and `run_all.sh` LeetCode build only includes the extra solved non-roadmap `Answer_Q##_...cpp` examples.

## Suggested graphics practice order

1. Q04 Dot product
2. Q05 Cross product
3. Q07 NormalizeSafe
4. Q12 Triangle normal
5. Q10 Angle between vectors
6. Q11 FOV check
7. Q19 Transform point
8. Q20 Transform direction
9. Q26 Ray-plane intersection
10. Q27 Ray-sphere intersection
11. Q28 Ray-AABB intersection
12. Q25 WorldToScreen
13. Q33 Frustum culling

## Interview tip

For each function, practice explaining:

1. What the math means visually
2. The formula
3. Where it is used in rendering/game/UI work
4. Edge cases, like zero-length vectors or parallel rays
